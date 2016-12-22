#include "OreFeature.h"

#include "util/ICRandom.h"

#include "mcpe/level/BlockSource.h"
#include "mcpe/util/BlockPos.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/block/Block.h"

namespace IC
{
OreFeature::OreFeature(FullBlock b,OreGenType t)
{
	oreBlock=b;
	type=t;
}
void OreFeature::place(BlockSource&s,BlockPos const&pos,ICRandom&r)
{
	if(type==OreGenType::ALONE)
		checkToPlace(s,pos);
	else if(type==OreGenType::SMALL)
	{
		checkToPlace(s,pos);
		checkToPlace(s,{pos.x+1,pos.y,pos.z});
		checkToPlace(s,{pos.x,pos.y,pos.z+1});
		checkToPlace(s,{pos.x+1,pos.y,pos.z+1});
		if(r.nextBool())checkToPlace(s,{pos.x+r.nextInt(2),pos.y+1,pos.z+r.nextInt(2)});
		if(r.nextBool())checkToPlace(s,{pos.x+r.nextInt(2),pos.y+1,pos.z+r.nextInt(2)});
		if(r.nextBool())checkToPlace(s,{pos.x+r.nextInt(2),pos.y-1,pos.z+r.nextInt(2)});
		if(r.nextBool())checkToPlace(s,{pos.x+r.nextInt(2),pos.y-1,pos.z+r.nextInt(2)});
	}
}
void OreFeature::checkToPlace(BlockSource&s,BlockPos const&pos)
{
	if(s.getBlock(pos)==Block::mStone&&s.getData(pos)==0)
		s.setBlockAndData(pos,oreBlock,3,0);
}
}
