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
#include "mcpe/entity/player/Player.h"
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
#include "util/language/zh_CN.h"
#include "util/language/en_US.h"

void ICPE::launch(JavaVM*,void*)
{
	setupMSHookFunctions();
}
void ICPE::setupMSHookFunctions()
{
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

MinecraftClient* ICPE::pMinecraftClient=0;
Level* ICPE::pLevel=0;
std::string ICPE::mLevelFolder;
ICBlockEntityManager ICPE::mBlockEntityManager;
ICOptions ICPE::mICOptions;
UIScreenChooser ICPE::mUIScreenChooser;
Random ICPE::mRandom;
const int ICPE::localKeyCode=137624695;

void ICPE::loadLocalization(Localization *self, const std::string &languageName)
{
	loadLocalization_(self,languageName);
	
	std::vector<std::string> languageList;
	
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
	
	if(s)
		IC::FeatureGen::decorateChunk(decorator,*s,r,biome,pos);
}
void ICPE::initRecipes(Recipes*self)
{
	initRecipes_(self);
	ICRecipes::addRecipes(*self,*FurnaceRecipes::getInstance());
}
bool ICPE::tessellateInWorld(BlockTessellator*tessellator,Block const&block,BlockPos const&pos,uchar aux,bool wtf)
{
	if(&block==Block::mBlocks[IC::Blocks::ID::mCable])
		return ((CableTessellator*)tessellator)->tessellate(block,pos,aux,wtf,tessellateInWorld_);
	return tessellateInWorld_(tessellator,block,pos,aux,wtf);
}
void ICPE::initMCClient(MinecraftClient*self)
{
	initMCClient_(self);
	pMinecraftClient=self;
	mUIScreenChooser=UIScreenChooser(*self);
	mRandom=Random((unsigned long int)time(0));
}
void ICPE::initCreativeItems()
{
	initCreativeItems_();
	IC::Items::addICCreativeItems();
}
void ICPE::initItems()
{
	initItems_();
	IC::Items::initICAllItems();
}
void ICPE::initBlockGraphics()
{
	initBlockGraphics_();
	IC::BlockGraphics::initBlockGraphics();
}
void ICPE::initBlocks()
{
	initBlocks_();
	IC::Blocks::initICBlocks();
}
void ICPE::createLevel(Minecraft*self,void*v,std::string const&path,std::string const&name,LevelSettings const &settings,ResourcePackManager&manager)
{
	createLevel_(self,v,path,name,settings,manager);
	mLevelFolder=path;
}
void ICPE::tickLevel(Level*self)
{
	tickLevel_(self);
	pLevel=self;
}
bool ICPE::isAnyAuxValue(int id)
{
	if(id<=255&&IC::Blocks::mICBlocks[id])
		if(!((IC::Blocks*)Block::mBlocks[id])->isAnyAuxValueInRecipe())
			return false;
	return isAnyAuxValue_(id);
}
