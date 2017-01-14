/**********************************
 * Industrial Craft:Pocket-Edition Source Code
 * CopyRight © 2016-2017 MCAL Team
 * CopyRight © 2016-2017 ICPE Dev Team
 **********************************/

#include "ICPE.h"
#include "Substrate.h"
#include <jni.h>
#include <cmath>
#include <dlfcn.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

#include "mcpe/item/Item.h"
#include "mcpe/block/Block.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/block/blocks/FlowerPotBlock.h"
#include "mcpe/client/MinecraftClient.h"
#include "mcpe/client/Minecraft.h"
#include "mcpe/client/resources/Localization.h"
#include "mcpe/client/renderer/BlockTessellator.h"
#include "mcpe/client/gui/GuiData.h"
#include "mcpe/client/gui/screen/Screen.h"
#include "mcpe/client/gui/screen/ScreenChooser.h"
#include "mcpe/client/renderer/ScreenRenderer.h"
#include "mcpe/recipe/Recipes.h"
#include "mcpe/recipe/Recipe.h"
#include "mcpe/recipe/FurnaceRecipes.h"
#include "mcpe/gamemode/GameMode.h"
#include "mcpe/entity/player/LocalPlayer.h"
#include "mcpe/entity/item/ItemEntity.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/level/Level.h"
#include "mcpe/level/chunk/LevelChunk.h"
#include "mcpe/level/ChunkPos.h"
#include "mcpe/level/biome/BiomeDecorator.h"

#include "items/Items.h"
#include "items/recipe/ICRecipes.h"
#include "blocks/Blocks.h"
#include "blocks/BlockGraphics.h"
#include "blocks/blockentity/ICBlockEntityManager.h"
#include "blocks/tessellator/CableTessellator.h"
#include "gen/FeatureGen.h"
#include "ui/UIScreenChooser.h"
#include "util/ICOptions.h"
#include "util/Log.h"
#include "util/language/zh_CN.h"
#include "util/language/en_US.h"

void ICPE::launch(JavaVM*,void*)
{
	LOG_P("ICPE loaded.");
	setupMSHookFunctions();
}
void ICPE::setupMSHookFunctions()
{
	LOG_P("Start setting up MSHookFunctions.");
	//MSHookFunction((void*)&Level::saveGameData,(void*)&saveLevel,(void**)&saveLevel_);
	MSHookFunction((void*)&MinecraftClient::leaveGame,(void*)&leaveGame,(void**)&leaveGame_);
	MSHookFunction((void*)&Level::onNewChunkFor,(void*)&onChunkLoaded,(void**)&onChunkLoaded_);
	MSHookFunction((void*)&BlockSource::onChunkDiscarded,(void*)&onChunkDiscarded,(void**)&onChunkDiscarded_);
	MSHookFunction((void*)&Recipe::isAnyAuxValue,(void*)&isAnyAuxValue,(void**)&isAnyAuxValue_);
	MSHookFunction((void*)&FlowerPotBlock::isSupportedBlock,(void*)&isSupportedFlower,(void**)&isSupportedFlower_);
	MSHookFunction((void*)&Localization::_load,(void*)&loadLocalization,(void**)&loadLocalization_);
	MSHookFunction((void*)&Level::tick,(void*)&tickLevel,(void**)&tickLevel_);
	MSHookFunction((void*)&Minecraft::createLevel,(void*)&createLevel,(void**)&createLevel_);
	MSHookFunction((void*)&BiomeDecorator::decorate,(void*)&decorateChunk,(void**)&decorateChunk_);
	MSHookFunction((void*)&Recipes::init,(void*)&initRecipes,(void**)&initRecipes_);
	MSHookFunction((void*)&BlockTessellator::tessellateInWorld,(void*)&tessellateInWorld,(void**)&tessellateInWorld_);
	MSHookFunction((void*)&MinecraftClient::init,(void*)&initMCClient,(void**)&initMCClient_);
	MSHookFunction((void*)&Item::initCreativeItems,(void*)&initCreativeItems,(void**)&initCreativeItems_);
	MSHookFunction((void*)&Item::initClientData,(void*)&initItems,(void**)&initItems_);
	MSHookFunction((void*)&MCPEBlockGraphics::initBlocks,(void*)&initBlockGraphics,(void**)&initBlockGraphics_);
	MSHookFunction((void*)&Block::initBlocks,(void*)&initBlocks,(void**)&initBlocks_);
	LOG_P("MSHookFunctions have been set up.");
}

void (*ICPE::loadLocalization_)(Localization*, const std::string&)=0;
void (*ICPE::decorateChunk_)(BiomeDecorator*,BlockSource*, Random&, Biome*, BlockPos const&, bool, float)=0;
void (*ICPE::initRecipes_)(Recipes*self)=0;
bool (*ICPE::tessellateInWorld_)(BlockTessellator*,Block const&,BlockPos const&,uchar,bool)=0;
void (*ICPE::initMCClient_)(MinecraftClient*)=0;
void (*ICPE::initCreativeItems_)()=0;
void (*ICPE::initItems_)()=0;
void (*ICPE::initBlockGraphics_)()=0;
void (*ICPE::initBlocks_)()=0;
bool (*ICPE::isSupportedFlower_)(FlowerPotBlock const*const,Block const*,short)=0;
void (*ICPE::createLevel_)(Minecraft*,void*,std::string const&,std::string const&,LevelSettings const &,ResourcePackManager&)=0;
void (*ICPE::tickLevel_)(Level*)=0;
bool (*ICPE::isAnyAuxValue_)(int)=0;
void (*ICPE::saveLevel_)(Level*)=0;
void (*ICPE::leaveGame_)(MinecraftClient*,bool)=0;
void (*ICPE::onChunkDiscarded_)(BlockSource*,LevelChunk&)=0;
void (*ICPE::onChunkLoaded_)(Level*,Player&,LevelChunk&)=0;

MinecraftClient* ICPE::pMinecraftClient=0;
Level* ICPE::pLevel=0;
bool ICPE::enterLevel=false;
std::string ICPE::mLevelFolder;
ICBlockEntityManager ICPE::mBlockEntityManager;
ICOptions ICPE::mICOptions;
UIScreenChooser ICPE::mUIScreenChooser;
Random ICPE::mRandom;
const int ICPE::localKeyCode=3497615802;

void ICPE::loadLocalization(Localization *self, const std::string &languageName)
{
	loadLocalization_(self,languageName);
	
	std::vector<std::string> languageList;
	
	LOG_P("Load localization:"+languageName);
	
	if(languageName=="en_US")
		languageList=ICLangauge::en_US;
	else if(languageName=="zh_CN")
		languageList=ICLangauge::zh_CN;
	for(std::string translation : languageList)
		self->_appendTranslations(translation);
}
bool ICPE::isSupportedFlower(FlowerPotBlock const*const self,Block const*block,short aux)
{
	return block==Block::mBlocks[IC::Blocks::ID::mRubberSapling]||isSupportedFlower_(self,block,aux);
}
void ICPE::decorateChunk(BiomeDecorator*decorator,BlockSource*s, Random&r, Biome*biome, BlockPos const&pos, bool b, float f)
{
	decorateChunk_(decorator,s,r,biome,pos,b,f);
	
	LOG_P("Decorating chunk:"+Util::toString(pos.x)+","+Util::toString(pos.y)+","+Util::toString(pos.z));
	
	if(s)
		IC::FeatureGen::decorateChunk(decorator,*s,r,biome,pos);
}
void ICPE::initRecipes(Recipes*self)
{
	initRecipes_(self);
	LOG_P("Adding recipes.");
	ICRecipes recipes(*self,*FurnaceRecipes::getInstance());
	recipes.addRecipes();
}
bool ICPE::tessellateInWorld(BlockTessellator*tessellator,Block const&block,BlockPos const&pos,uchar aux,bool wtf)
{
	if(&block==Block::mBlocks[IC::Blocks::ID::mCable])
		return ((CableTessellator*)tessellator)->tessellate(block,pos,aux,wtf);
	return tessellateInWorld_(tessellator,block,pos,aux,wtf);
}
void ICPE::initMCClient(MinecraftClient*self)
{
	initMCClient_(self);
	LOG_P("Client inited.");
	pMinecraftClient=self;
	mUIScreenChooser=UIScreenChooser(*self);
	mRandom=Random((unsigned long int)time(0));
}
void ICPE::initCreativeItems()
{
	initCreativeItems_();
	LOG_P("Initing creative items");
	IC::Items::addICCreativeItems();
}
void ICPE::initItems()
{
	initItems_();
	LOG_P("Initing items.");
	IC::Items::initICAllItems();
}
void ICPE::initBlockGraphics()
{
	initBlockGraphics_();
	LOG_P("Initing block graphics.");
	IC::BlockGraphics::initBlockGraphics();
}
void ICPE::initBlocks()
{
	initBlocks_();
	LOG_P("Initing Blocks.");
	IC::Blocks::initICBlocks();
}
void ICPE::createLevel(Minecraft*self,void*v,std::string const&path,std::string const&name,LevelSettings const &settings,ResourcePackManager&manager)
{
	createLevel_(self,v,path,name,settings,manager);
	LOG_P("Level created.");
	mLevelFolder=path;
	enterLevel=true;
}
void ICPE::tickLevel(Level*self)
{
	tickLevel_(self);
	pLevel=self;
	
	mBlockEntityManager.tick(*self);
}
void ICPE::saveLevel(Level*self)
{
	saveLevel_(self);
	
	mBlockEntityManager.save();
	LOG_P("Level saved!");
}
void ICPE::onChunkLoaded(Level*self,Player&p,LevelChunk&chunk)
{
	onChunkLoaded_(self,p,chunk);
	if(enterLevel)
	{
		enterLevel=false;
		mBlockEntityManager=ICBlockEntityManager(mLevelFolder);
		LOG_P("Created block entity manager");
	}
}
void ICPE::onChunkDiscarded(BlockSource*self,LevelChunk&chunk)
{
	onChunkDiscarded_(self,chunk);
}
void ICPE::leaveGame(MinecraftClient*self,bool b)
{
	leaveGame_(self,b);
	LOG_P("LEAVE GAME");
	mBlockEntityManager.save();
	mBlockEntityManager=ICBlockEntityManager();
}
bool ICPE::isAnyAuxValue(int id)
{
	if(id<=255&&IC::Blocks::mICBlocks[id])
		if(!((IC::Blocks*)Block::mBlocks[id])->isAnyAuxValueInRecipe())
			return false;
	return isAnyAuxValue_(id);
}
