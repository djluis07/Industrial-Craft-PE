#include "OreFeature.h"

#include "mcpe/level/BlockSource.h"
#include "mcpe/util/BlockPos.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/util/Random.h"
#include "mcpe/block/Block.h"

namespace IC
{
OreFeature::OreFeature(FullBlock b,OreGenType t)
{
	oreBlock=b;
	type=t;
}
bool OreFeature::place(BlockSource&s,BlockPos const&pos,Random&r)const
{
	BlockPos pox=pos;
	switch(type)
	{
	case OreGenType::ALONE:
	{
		checkToPlace(s,pos);
	}
	break;
	case OreGenType::SMALL:
	{
		checkToPlace(s,pos);
		unsigned int chance=r.nextInt(4);
		if(chance==0)
		{
			checkToPlace(s,pox.x-1,pos.y,pos.z);
			checkToPlace(s,pox.x-1,pos.y,pos.z-1);
			checkToPlace(s,pox.x,pos.y,pos.z-1);
		}
		else if(chance==1)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
		}
		else if(chance==2)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==3)
		{
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y-1,pos.z+1);
			checkToPlace(s,pox.x,pos.y-1,pos.z);
		}
	}
	case OreGenType::MIDDLE:
	{
		checkToPlace(s,pos);
		unsigned int chance=r.nextInt(5);
		if(chance==0)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==1)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==2)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==3)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
		}
		else if(chance==4)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
	}
	case OreGenType::BIG:
	{
		checkToPlace(s,pos);
		unsigned int chance=r.nextInt(5);
		if(chance==0)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==1)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==2)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==3)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
		}
		else if(chance==4)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		pox.x+=2;
		pox.y+=2;
		checkToPlace(s,pos);
		chance=r.nextInt(5);
		if(chance==0)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==1)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==2)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==3)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
		}
		else if(chance==4)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
	}
	break;
	case OreGenType::LARGE:
	{
		checkToPlace(s,pos);
		unsigned int chance=r.nextInt(5);
		if(chance==0)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==1)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==2)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==3)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
		}
		else if(chance==4)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		pox.x+=2;
		pox.y+=2;
		checkToPlace(s,pos);
		chance=r.nextInt(5);
		if(chance==0)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==1)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==2)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==3)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
		}
		else if(chance==4)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		pox.z+=2;
		pox.y-=4;
		checkToPlace(s,pos);
		chance=r.nextInt(5);
		if(chance==0)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==1)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==2)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
		else if(chance==3)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
		}
		else if(chance==4)
		{
			checkToPlace(s,pox.x+1,pos.y,pos.z);
			checkToPlace(s,pox.x+1,pos.y,pos.z+1);
			checkToPlace(s,pox.x,pos.y,pos.z+1);
			checkToPlace(s,pox.x+1,pos.y+1,pos.z);
			checkToPlace(s,pox.x,pos.y+1,pos.z+1);
			checkToPlace(s,pox.x,pos.y+1,pos.z);
		}
	}
	break;
	}
}
void OreFeature::checkToPlace(BlockSource&s,BlockPos const&pos)const
{
	if(s.getBlock(pos)==Block::mStone&&s.getData(pos)==0)
		s.setBlockAndData(pos,oreBlock,3,0);
}
void OreFeature::checkToPlace(BlockSource&s,int x,int y,int z)const
{
	if(s.getBlock(x,y,z)==Block::mStone&&s.getData(x,y,z)==0)
		s.setBlockAndData(x,y,z,oreBlock,3);
}
}
