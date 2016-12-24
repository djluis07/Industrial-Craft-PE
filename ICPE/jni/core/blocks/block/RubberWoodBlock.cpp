#include "RubberWoodBlock.h"

#include "blocks/Blocks.h"

#include "mcpe/level/BlockSource.h"
#include "mcpe/item/ItemInstance.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/util/Random.h"
#include "mcpe/block/blocks/FireBlock.h"

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
	if(s.getData(pos)==1&&canMakeWet(s,pos)&&r.nextBool(7))
		s.setBlockAndData(pos,FullBlock(IC::Blocks::ID::mRubberWood,2),3,0);
}
int RubberWoodBlock::getSpawnResourcesAuxValue(unsigned char)const
{
	return 0;
}
int RubberWoodBlock::getPlacementDataValue(Mob&, BlockPos const&, signed char, Vec3 const&, int aux)const
{
	return aux;
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
