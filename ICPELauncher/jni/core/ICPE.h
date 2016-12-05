#pragma once

#include <jni.h>
#include <string>

class Localization;
class Level;
class Player;
class Recipes;
class LevelChunk;
class BlockTessellator;
class MinecraftClient;
class Minecraft;
class Block;
class Item;
class BlockPos;
class LevelSettings;
class ResourcePackManager;
class BlockGraphics;
class ICBlockEntityManager;
class ICOptions;
class UIScreenChooser;

typedef BlockGraphics MCPEBlockGraphics;
typedef unsigned char uchar;

class ICPE
{
public:
	static jint onJNI_Loaded(JavaVM*,void*);
	static void setupMSHookFunctions();
public:
	static void (*loadLocalization_)(Localization*, const std::string&);
	static void loadLocalization(Localization *, const std::string &);
	static void (*onNewChunkFor_)(Level*,Player &, LevelChunk &);
	static void onNewChunkFor(Level*,Player &, LevelChunk &);
	static void (*initRecipes_)(Recipes*);
	static void initRecipes(Recipes*);
	static bool (*tessellateInWorld_)(BlockTessellator*,Block&,BlockPos const&,uchar,bool);
	static bool tessellateInWorld(BlockTessellator*,Block&,BlockPos const&,uchar,bool);
	static void (*initMCClient_)(MinecraftClient*);
	static void initMCClient(MinecraftClient*);
	static void (*initCreativeItems_)();
	static void initCreativeItems();
	static void (*initItems_)();
	static void initItems();
	static void (*initBlockGraphics_)();
	static void initBlockGraphics();
	static void (*initBlocks_)();
	static void initBlocks();
	static void (*createLevel_)(Minecraft*,void*,std::string const&,std::string const&,LevelSettings const &,ResourcePackManager&);
	static void createLevel(Minecraft*,void*,std::string const&,std::string const&,LevelSettings const &,ResourcePackManager&);
	static void (*tickLevel_)(Level*);
	static void tickLevel(Level*);
public:
	static MinecraftClient* mcClient;
	static Level* currentLevel;
	static std::string currentLevelFolder;
	static ICBlockEntityManager* currentICBlockEntityManager;
	static ICOptions* icOptions;
	static UIScreenChooser* uiChooser;
};
