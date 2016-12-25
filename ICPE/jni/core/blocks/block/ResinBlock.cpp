#include "ResinBlock.h"

#include "items/Items.h"
#include "blocks/Blocks.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/level/BlockSource.h"

ResinBlock::ResinBlock():IC::Blocks("ic.resin",IC::Blocks::ID::mResin,Material::getMaterial(MaterialType::DEVICE))
{
	init();
	setCategory(CreativeItemCategory::DECORATIONS);
	setVisualShape({0,0,0,1,0.125,1});
	setDestroyTime(1);
	setSolid(false);
}
int ResinBlock::getResource(Random&, int, int)const
{
	return IC::Items::ID::mRubber;
}
int ResinBlock::getSpawnResourcesAuxValue(unsigned char aux)const
{
	return aux;
}
bool ResinBlock::mayPlaceOn(Block const&b)const
{
	return b.isSolid();
}
void ResinBlock::neighborChanged(BlockSource&s, BlockPos const&pos, BlockPos const&)const
{
	if(s.getBlock(pos)==this&&!mayPlaceOn(*s.getBlock(pos.x,pos.y-1,pos.z)))
	{
		popResource(s,pos,ItemInstance(IC::Items::ID::mRubber,1,s.getData(pos)));
		s.removeBlock(pos);
	}
}
bool ResinBlock::entityInside(BlockSource&s, BlockPos const&pos, Entity&e)const
{
	if(s.getData(pos)==0)
		mSlimeBlock->onStepOn(e,pos);
}
