#include "RubberWoodBlock.h"

#include "blocks/Blocks.h"

#include "mcpe/level/BlockSource.h"
#include "mcpe/item/ItemInstance.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/util/Random.h"
#include "mcpe/block/blocks/FireBlock.h"
#include "mcpe/entity/player/Player.h"

#include "items/Items.h"
#include "ICPE.h"

RubberWoodBlock::RubberWoodBlock():IC::Blocks("ic.rubber.wood",IC::Blocks::ID::mRubberWood,Material::getMaterial(MaterialType::WOOD))
{
	init();
	setCategory(CreativeItemCategory::DECORATIONS);
	setExplodeable(10);
	setDestroyTime(2);
	setTicking(true);
	
	((FireBlock*)mFire)->setFlammable(BlockID(IC::Blocks::ID::mRubberWood),50,10);
}
void RubberWoodBlock::tick(BlockSource&s, BlockPos const&pos, Random&r)const
{
	if(s.getData(pos)>=3&&s.getData(pos)<=6&&canMakeWet(s,pos)&&r.nextBool(7))
		s.setBlockAndData(pos,FullBlock(IC::Blocks::ID::mRubberWood,s.getData(pos)+4),3,0);
}
int RubberWoodBlock::getSpawnResourcesAuxValue(unsigned char)const
{
	return 0;
}
int RubberWoodBlock::getPlacementDataValue(Entity&, BlockPos const&, signed char side, Vec3 const&, int)const
{
	if(side==2||side==3)
		return 1;
	else if(side==4||side==5)
		return 2;
	return 0;
}
bool RubberWoodBlock::use(Player&p, BlockPos const&pos) const
{
	if(p.getSelectedItem()&&p.getSelectedItem()->getId()==IC::Items::ID::mTreeTap)
	{
		if(p.getRegion().getData(pos)>6)
		{
			p.getRegion().setBlockAndData(pos,FullBlock(Blocks::ID::mRubberWood,p.getRegion().getData(pos)-4),3,0);
			if(!p.isCreative())
				p.getSelectedItem()->hurtAndBreak(1,0);
			popResource(p.getRegion(),pos,ItemInstance(IC::Items::ID::mResin,1+ICPE::mRandom.nextInt(3),0));
		}
		else if(p.getRegion().getData(pos)>2)
		{
			p.getRegion().setBlockAndData(pos,FullBlock(Blocks::ID::mRubberWood,0),3,0);
			if(!p.isCreative())
				p.getSelectedItem()->hurtAndBreak(1,0);
			popResource(p.getRegion(),pos,ItemInstance(IC::Items::ID::mResin,1+ICPE::mRandom.nextInt(3),0));
		}
	}
	else if(p.getSelectedItem()&&p.getSelectedItem()->getId()==IC::Items::ID::mElectricTreeTap)
	{
		if(p.getSelectedItem()->aux<(p.getSelectedItem()->getMaxDamage()-1)&&p.getRegion().getData(pos)>6)
		{
			p.getRegion().setBlockAndData(pos,FullBlock(Blocks::ID::mRubberWood,p.getRegion().getData(pos)-4),3,0);
			if(!p.isCreative())
				p.getSelectedItem()->hurtAndBreak(1,0);
			popResource(p.getRegion(),pos,ItemInstance(IC::Items::ID::mResin,1+ICPE::mRandom.nextInt(3),0));
		}
		if(p.getSelectedItem()->aux<(p.getSelectedItem()->getMaxDamage()-1)&&p.getRegion().getData(pos)>2)
		{
			p.getRegion().setBlockAndData(pos,FullBlock(Blocks::ID::mRubberWood,0),3,0);
			if(!p.isCreative())
				p.getSelectedItem()->hurtAndBreak(1,0);
			popResource(p.getRegion(),pos,ItemInstance(IC::Items::ID::mResin,1+ICPE::mRandom.nextInt(3),0));
		}
	}
	else
		return false;
	return true;
}
bool RubberWoodBlock::canMakeWet(BlockSource&s,BlockPos const&pos)const
{
	if(hasLeafAround(s,pos))
		return true;
	if(hasWoodTop(s,pos))
		return canMakeWet(s,BlockPos(pos.x,pos.y+1,pos.z));
	return false;
}
bool RubberWoodBlock::hasWoodTop(BlockSource&s,BlockPos const&pos)const
{
	return s.getBlock(pos.x,pos.y+1,pos.z)==this;
}
bool RubberWoodBlock::hasLeafAround(BlockSource&s,BlockPos const&pos)const
{
	return s.getBlock(pos.x,pos.y-1,pos.z)==mBlocks[ID::mRubberLeaves]||
	s.getBlock(pos.x,pos.y+1,pos.z)==mBlocks[ID::mRubberLeaves]||
	s.getBlock(pos.x,pos.y,pos.z-1)==mBlocks[ID::mRubberLeaves]||
	s.getBlock(pos.x,pos.y,pos.z+1)==mBlocks[ID::mRubberLeaves]||
	s.getBlock(pos.x-1,pos.y,pos.z)==mBlocks[ID::mRubberLeaves]||
	s.getBlock(pos.x+1,pos.y,pos.z)==mBlocks[ID::mRubberLeaves];
}
void RubberWoodBlock::spawnResources(BlockSource&s, BlockPos const&pos, int aux, float f, int i) const
{
	if(aux>2)
		popResource(s,pos,ItemInstance(IC::Items::ID::mResin,1+ICPE::mRandom.nextInt(3),0));
	Block::spawnResources(s,pos,aux,f,i);
}
