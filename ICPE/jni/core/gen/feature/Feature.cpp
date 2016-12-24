#include "Feature.h"

#include "mcpe/level/BlockSource.h"
#include "mcpe/util/FullBlock.h"

namespace IC
{
void Feature::setBlock(BlockSource&s,BlockPos const&pos,FullBlock const&b)const
{
	s.setBlockAndData(pos,b,3,0);
}
void Feature::setBlock(BlockSource&s,int x,int y,int z,FullBlock const&b)const
{
	s.setBlockAndData(x,y,z,b,3);
}
}
