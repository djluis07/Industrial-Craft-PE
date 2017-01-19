#include "RavineFeature.h"

#include "mcpe/level/BlockSource.h"
#include "mcpe/util/BlockPos.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/util/Random.h"
#include "mcpe/block/Block.h"

#include "util/Math.h"

#include <stdlib.h>

RavineFeature::RavineFeature():Feature(0)
{
	
}
bool RavineFeature::place(BlockSource&s,BlockPos const&pos,Random&r)const
{
	const int xOffSet=getRandomOffset(r);
	const int zOffSet=getRandomOffset(r);
	BlockPos startPosition=BlockPos(pos.x+xOffSet,pos.y,pos.z+zOffSet);
	BlockPos endPosition=BlockPos(pos.x-xOffSet,pos.y,pos.z-zOffSet);
	const int randomWidth=8+r.nextInt(5);
	const int randomHeight=12+r.nextInt(5);
	const bool direction=r.nextBool();
	
	generateChildRavine(s,startPosition,endPosition,randomWidth,randomHeight,direction,r);
	startPosition.y+=randomHeight;
	endPosition.y+=randomHeight;
	generateChildRavine(s,startPosition,endPosition,randomWidth+2,randomHeight,direction,r);
	if(r.nextBool())
	{
		startPosition.y+=randomHeight;
		endPosition.y+=randomHeight;
		generateChildRavine(s,startPosition,endPosition,randomWidth,randomHeight,direction,r);
	}
	return true;
}
int RavineFeature::getRandomOffset(Random&random)const
{
	return (20+random.nextInt(10))*(random.nextBool()?-1:1);
}
void RavineFeature::placeAirBlock(BlockSource&s,BlockPos const&pos)const
{
	Block const* block=s.getBlock(pos);
	if(block->getDestroySpeed()>0&&block!=Block::mStillWater&&block!=Block::mFlowingWater)
		s.removeBlock(pos);
}
void RavineFeature::placeAirChunk(BlockSource&s,BlockPos const&pos,int w,int h,bool b,Random&r)const
{
	for(int y=pos.y;y<pos.y+h;++y)
	{
		if(b)
		{
			for(int x=pos.x-(w/2);x<pos.x+(w/2);++x)
				placeAirBlock(s,BlockPos(x,y,pos.z));
			if(r.nextBool(100))
				placeSpring(s,BlockPos(pos.x+(w/2+1)*(r.nextBool()?-1:1),y,pos.z),true);
			else if(r.nextBool(250))
				placeSpring(s,BlockPos(pos.x+(w/2+1)*(r.nextBool()?-1:1),y,pos.z),false);
		}
		else
		{
			for(int z=pos.z-(w/2);z<pos.z+(w/2);++z)
				placeAirBlock(s,BlockPos(pos.x,y,z));
			if(r.nextBool(100))
				placeSpring(s,BlockPos(pos.x,y,pos.z+(w/2+1)*(r.nextBool()?-1:1)),true);
			else if(r.nextBool(250))
				placeSpring(s,BlockPos(pos.x,y,pos.z+(w/2+1)*(r.nextBool()?-1:1)),false);
		}
	}
}
void RavineFeature::generateChildRavine(BlockSource&s,BlockPos const&posStart,BlockPos const&posEnd,int w,int h,bool b,Random&r)const
{
	const float lineConstK=(posEnd.z-posStart.z)/(posEnd.x-posStart.x);
	const int lineConstB=(posStart.z*posEnd.x-posEnd.z*posStart.x)/(posEnd.x-posStart.x);
	
	const int endX=Math::max(posStart.x,posEnd.x);
	const int startX=Math::min(posStart.x,posEnd.x);
	for(int xp=startX;xp<endX;++xp)
		placeAirChunk(s,BlockPos(xp,posStart.y,((int)lineConstK*xp)+lineConstB),w,h,b,r);
}
void RavineFeature::placeSpring(BlockSource&s,BlockPos const&pos,bool b)const
{
	if(s.getBlock(pos)==Block::mStone&&s.getData(pos)==0)
	{
		if(b)
			s.setBlockAndData(pos,FullBlock(9,0),3,0);
		else
			s.setBlockAndData(pos,FullBlock(11,0),3,0);
	}
}
