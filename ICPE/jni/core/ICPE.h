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
class Random;
class BiomeDecorator;
class Biome;
class BlockSource;
class FlowerPotBlock;

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
	static void (*decorateChunk_)(BiomeDecorator*,BlockSource*, Random&, Biome*, BlockPos const&, bool, float);
	static void decorateChunk(BiomeDecorator*,BlockSource*, Random&, Biome*, BlockPos const&, bool, float);
	static void (*initRecipes_)(Recipes*);
	static void initRecipes(Recipes*);
	static bool (*tessellateInWorld_)(BlockTessellator*,Block const&,BlockPos const&,uchar,bool);
	static bool tessellateInWorld(BlockTessellator*,Block const&,BlockPos const&,uchar,bool);
	static void (*initMCClient_)(MinecraftClient*);
	static void initMCClient(MinecraftClient*);
	static void (*initCreativeItems_)();
	static void initCreativeItems();
	static bool (*isSupportedFlower_)(FlowerPotBlock const*const,Block const*,short);
	static bool isSupportedFlower(FlowerPotBlock const*const,Block const*,short);
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
	static MinecraftClient* pMinecraftClient;
	static Level* pLevel;
	static std::string mLevelFolder;
	static ICBlockEntityManager mBlockEntityManager;
	static ICOptions mICOptions;
	static UIScreenChooser mUIScreenChooser;
	static Random mRandom;
	static const int localKeyCode;
};
