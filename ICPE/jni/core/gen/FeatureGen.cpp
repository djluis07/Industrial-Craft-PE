#include "FeatureGen.h"

#include <stdlib.h>

#include "blocks/Blocks.h"

#include "feature/OreFeature.h"
#include "feature/RubTreeFeature.h"
#include "feature/Feature.h"

#include "mcpe/level/ChunkPos.h"
#include "mcpe/level/biome/Biome.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/level/Level.h"
#include "mcpe/util/Random.h"

namespace IC
{

bool FeatureGen::inited=false;
std::shared_ptr<Feature> FeatureGen::rubTree;
std::shared_ptr<Feature> FeatureGen::tinOre;
std::shared_ptr<Feature> FeatureGen::copperOre;
std::shared_ptr<Feature> FeatureGen::uraniumOre;
std::shared_ptr<Feature> FeatureGen::leadOre;

void FeatureGen::decorateChunk(BlockSource&s, Random&random,Biome*biome,BlockPos const&pos)
{
	prepare();
	
	//rubber trees
	{
		for(int x=pos.x;x<pos.x+16;++x)
			for(int z=pos.z;z<pos.z+16;++z)
				for(int y=256;y>50;--y)
					if(s.getBlock(x,y,z)==Block::mGrass&&getRubGenChance(*biome)!=0&&random.nextBool(getRubGenChance(*biome)))
						rubTree->place(s,BlockPos(x,y,z),random);
	}
	
	//uraniun ore
	for(int x=pos.x;x<pos.x+16;++x)
		for(int y=5;y<20;++y)
			for(int z=pos.z;z<pos.z+16;++z)
				if(random.nextBool(3000))
					uraniumOre->place(s,BlockPos(x,y,z),random);
	//copper ore
	for(int x=pos.x;x<pos.x+16;++x)
		for(int y=5;y<70;++y)
			for(int z=pos.z;z<pos.z+16;++z)
				if(random.nextBool(1000))
					copperOre->place(s,BlockPos(x,y,z),random);
	//tin ore
	for(int x=pos.x;x<pos.x+16;++x)
		for(int y=5;y<55;++y)
			for(int z=pos.z;z<pos.z+16;++z)
				if(random.nextBool(1400))
					tinOre->place(s,BlockPos(x,y,z),random);
	//lead ore
	for(int x=pos.x;x<pos.x+16;++x)
		for(int y=5;y<25;++y)
			for(int z=pos.z;z<pos.z+16;++z)
				if(random.nextBool(2000))
					tinOre->place(s,BlockPos(x,y,z),random);
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
	
	tinOre=std::make_shared<OreFeature>(FullBlock(Blocks::ID::mOre,0),OreFeature::OreGenType::MIDDLE);
	copperOre=std::make_shared<OreFeature>(FullBlock(Blocks::ID::mOre,1),OreFeature::OreGenType::BIG);
	leadOre=std::make_shared<OreFeature>(FullBlock(Blocks::ID::mOre,2),OreFeature::OreGenType::SMALL);
	uraniumOre=std::make_shared<OreFeature>(FullBlock(Blocks::ID::mOre,3),OreFeature::OreGenType::ALONE);
	rubTree=std::make_shared<RubTreeFeature>(FullBlock(Blocks::ID::mRubberWood,0),FullBlock(Blocks::ID::mRubberWood,2),FullBlock(Blocks::ID::mRubberLeaves,0),15);
}
}
