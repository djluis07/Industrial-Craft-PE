#include "FeatureGen.h"

#include <stdlib.h>

#include "blocks/Blocks.h"
#include "util/Log.h"

#include "feature/RubTreeFeature.h"

#include "mcpe/level/gen/Feature.h"
#include "mcpe/level/gen/OreFeature.h"
#include "mcpe/level/ChunkPos.h"
#include "mcpe/level/biome/Biome.h"
#include "mcpe/level/biome/BiomeDecorator.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/level/Level.h"
#include "mcpe/util/Random.h"

namespace IC
{

bool FeatureGen::inited=false;
std::unique_ptr<Feature> FeatureGen::rubTree;
std::unique_ptr<Feature> FeatureGen::tinOre;
std::unique_ptr<Feature> FeatureGen::copperOre;
std::unique_ptr<Feature> FeatureGen::uraniumOre;
std::unique_ptr<Feature> FeatureGen::leadOre;

void FeatureGen::decorateChunk(BiomeDecorator*bd,BlockSource&s, Random&random,Biome*biome,BlockPos const&pos)
{
	prepare();
	
	LOG_P("Started decorating Chunk");
	
	//rubber trees
	{
		for(int x=pos.x;x<pos.x+16;++x)
			for(int z=pos.z;z<pos.z+16;++z)
				for(int y=256;y>50;--y)
					if(s.getBlock(x,y,z)==Block::mGrass&&getRubGenChance(*biome)!=0&&random.nextBool(getRubGenChance(*biome)))
						bd->_placeFeature(&s,rubTree,BlockPos(x,y+1,z),random);
	}
	
	//uranium ore
	for(int x=pos.x;x<pos.x+16;++x)
		for(int y=5;y<25;++y)
			for(int z=pos.z;z<pos.z+16;++z)
				if(random.nextBool(5000))
					bd->_placeFeature(&s,uraniumOre,BlockPos(x,y,z),random);
	//copper ore
	for(int x=pos.x;x<pos.x+16;++x)
		for(int y=10;y<70;++y)
			for(int z=pos.z;z<pos.z+16;++z)
				if(random.nextBool(1000))
					bd->_placeFeature(&s,copperOre,BlockPos(x,y,z),random);
	//tin ore
	for(int x=pos.x;x<pos.x+16;++x)
		for(int y=0;y<40;++y)
			for(int z=pos.z;z<pos.z+16;++z)
				if(random.nextBool(1000))
					bd->_placeFeature(&s,tinOre,BlockPos(x,y,z),random);
	//lead ore
	for(int x=pos.x;x<pos.x+16;++x)
		for(int y=0;y<30;++y)
			for(int z=pos.z;z<pos.z+16;++z)
				if(random.nextBool(2000))
					bd->_placeFeature(&s,leadOre,BlockPos(x,y,z),random);
	
	LOG_P("Finished decorating Chunk");
}
unsigned int FeatureGen::getRubGenChance(Biome&b)
{
	if(&b==Biome::forest||&b==Biome::extremeHillsWithTrees||&b==Biome::extremeHillsWithTreesMutated||&b==Biome::forestHills||&b==Biome::forestMutated||&b==Biome::plainsMutated)
		return 10000;
	if(&b==Biome::swampland||&b==Biome::swamplandMutated)
		return 7000;
	return 0;
}
void FeatureGen::prepare()
{
	if(inited)
		return;
	inited=true;
	
	tinOre=std::unique_ptr<OreFeature>(new OreFeature(Blocks::ID::mOre,0,6));
	copperOre=std::unique_ptr<OreFeature>(new OreFeature(Blocks::ID::mOre,1,10));
	leadOre=std::unique_ptr<OreFeature>(new OreFeature(Blocks::ID::mOre,2,6));
	uraniumOre=std::unique_ptr<OreFeature>(new OreFeature(Blocks::ID::mOre,3,4));
	rubTree=std::unique_ptr<RubTreeFeature>(new RubTreeFeature(FullBlock(Blocks::ID::mRubberWood,0),FullBlock(Blocks::ID::mRubberWood,2),FullBlock(Blocks::ID::mRubberLeaves,0),15));
}
}
