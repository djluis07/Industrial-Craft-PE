/**********************************
 * Industrial Craft : PE Source Code
 * CopyRight © 2016-2017 MCAL Team(MinecraftPE Addons Laboratory Team)
 * Developded BY ModelPart
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
#include "mcpe/client/MinecraftClient.h"
#include "mcpe/client/Minecraft.h"
#include "mcpe/client/resources/Localization.h"
#include "mcpe/client/renderer/BlockTessellator.h"
#include "mcpe/client/gui/GuiData.h"
#include "mcpe/client/gui/screen/Screen.h"
#include "mcpe/client/gui/screen/ScreenChooser.h"
#include "mcpe/client/renderer/ScreenRenderer.h"
#include "mcpe/recipe/Recipes.h"
#include "mcpe/recipe/FurnaceRecipes.h"
#include "mcpe/gamemode/GameMode.h"
#include "mcpe/entity/player/Player.h"
#include "mcpe/entity/item/ItemEntity.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/level/Level.h"
#include "mcpe/level/chunk/LevelChunk.h"
#include "mcpe/level/ChunkPos.h"

#include "items/Items.h"
#include "items/recipe/ICRecipes.h"
#include "blocks/Blocks.h"
#include "blocks/BlockGraphics.h"
#include "blocks/blockentity/ICBlockEntityManager.h"
#include "blocks/tessellator/CableTessellator.h"
#include "gen/FeatureGen.h"
#include "client/ICClient.h"
#include "ui/uilib/UILib.h"
#include "ui/UIScreenChooser.h"
#include "util/ICRandom.h"
#include "util/language/zh_CN.h"
#include "util/language/en_US.h"

namespace IC
{
static void (*tickLevel_)(Level*);
static void tickLevel(Level*self)
{
	tickLevel_(self);
	ICClient::mInstance.setCurrentLevel(self);
}
static void (*createLevel_)(Minecraft*,void*,std::string const&,std::string const&,LevelSettings const &,ResourcePackManager&);
static void createLevel(Minecraft*self,void*v,std::string const&path,std::string const&name,LevelSettings const &settings,ResourcePackManager&manager)
{
	createLevel_(self,v,path,name,settings,manager);
	ICClient::mInstance.setLevelFolder(path);
}
static void (*initBlocks_)();
static void initBlocks()
{
	initBlocks_();
	IC::Blocks::initICBlocks();
}
static void (*initBlockGraphics_)();
static void initBlockGraphics()
{
	initBlockGraphics_();
	IC::BlockGraphics::initBlockGraphics();
}
static void (*initItems_)();
static void initItems()
{
	initItems_();
	IC::Items::initICAllItems();
}
static void (*initCreativeItems_)();
static void initCreativeItems()
{
	initCreativeItems_();
	IC::Items::addICCreativeItems();
}
static void (*initMCClient_)(MinecraftClient*);
static void initMCClient(MinecraftClient*self)
{
	initMCClient_(self);
	ICClient::mInstance.setMinecraftClient(self);
}
static bool (*tessellateInWorld_)(BlockTessellator*,Block&,BlockPos const&,uchar,bool);
static bool tessellateInWorld(BlockTessellator*tessellator,Block&block,BlockPos const&pos,uchar aux,bool wtf)
{
	if(&block==Block::mBlocks[IC::Blocks::ID::mCable])
		return ((CableTessellator*)tessellator)->tessellate(block,pos,aux,wtf,tessellateInWorld_);
	return tessellateInWorld_(tessellator,block,pos,aux,wtf);
}
static void (*initRecipes_)(Recipes*);
static void initRecipes(Recipes*self)
{
	initRecipes_(self);
	ICRecipes::addRecipes(*self,*FurnaceRecipes::getInstance());
}
static void (*onNewChunkFor_)(Level*,Player &, LevelChunk &);
static void onNewChunkFor(Level*self,Player &p, LevelChunk &chunk)
{
	onNewChunkFor_(self,p,chunk);
	
	if(p.getRegion().getBlock(chunk.getPosition().x*16,0,chunk.getPosition().z)==Block::mBedrock&&p.getRegion().getData(chunk.getPosition().x*16,0,chunk.getPosition().z)==0)
	{
		p.getRegion().setBlockAndData(chunk.getPosition().x*16,0,chunk.getPosition().z,FullBlock(7,1),3);
		IC::FeatureGen::decorateChunk(p.getRegion(),chunk.getPosition());
	}
}
static void (*loadLocalization_)(Localization*, const std::string&);
static void loadLocalization(Localization *self, const std::string &languageName)
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

}
JNIEXPORT jint JNI_OnLoad(JavaVM*,void*)
{
	using namespace IC;
	
	UILib::setup();
	
	MSHookFunction((void*)&Localization::_load,(void*)&loadLocalization,(void**)&loadLocalization_);
	MSHookFunction((void*)&Level::tick,(void*)&tickLevel,(void**)&tickLevel_);
	MSHookFunction((void*)&Minecraft::createLevel,(void*)&createLevel,(void**)&createLevel_);
	MSHookFunction((void*)&Level::onNewChunkFor,(void*)&onNewChunkFor,(void**)&onNewChunkFor_);
	MSHookFunction((void*)&Recipes::init,(void*)&initRecipes,(void**)&initRecipes_);
	MSHookFunction((void*)&BlockTessellator::tessellateInWorld,(void*)&tessellateInWorld,(void**)&tessellateInWorld_);
	MSHookFunction((void*)&MinecraftClient::init,(void*)&initMCClient,(void**)&initMCClient_);
	MSHookFunction((void*)&Item::initCreativeItems,(void*)&initCreativeItems,(void**)&initCreativeItems_);
	MSHookFunction((void*)&Item::initClientData,(void*)&initItems,(void**)&initItems_);
	MSHookFunction((void*)&MCPEBlockGraphics::initBlocks,(void*)&initBlockGraphics,(void**)&initBlockGraphics_);
	MSHookFunction((void*)&Block::initBlocks,(void*)&initBlocks,(void**)&initBlocks_);
	return JNI_VERSION_1_6;
}
