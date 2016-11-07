#include "ResinBlock.h"

#include "ic/items/Items.h"
#include "ic/blocks/Blocks.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/level/BlockSource.h"

ResinBlock::ResinBlock():IC::Blocks("ic.resin",IC::Blocks::ID::mResin,Material::getMaterial(MaterialType::DEVICE))
{
	init();
	setCategory(CreativeItemCategory::DECORATIONS);
	setVisualShape({0,0,0,1,0.125,1});
	//setSoundType(BlockSoundType::SOUND_DEFAULT);
	setDestroyTime(1);
	setSolid(false);
}
int ResinBlock::getResource(Random&, int, int)
{
	return IC::Items::ID::mRubber;
}
int ResinBlock::getSpawnResourcesAuxValue(unsigned char aux)
{
	return aux;
}
bool ResinBlock::mayPlaceOn(Block const&b)
{
	return b.isSolid();
}
void ResinBlock::neighborChanged(BlockSource&s, BlockPos const&pos, BlockPos const&)
{
	if(s.getBlock(pos)==this&&!mayPlaceOn(*s.getBlock(pos.x,pos.y-1,pos.z)))
	{
		popResource(s,pos,ItemInstance(IC::Items::ID::mRubber,1,s.getData(pos)));
		s.removeBlock(pos);
	}
}
bool ResinBlock::entityInside(BlockSource&s, BlockPos const&pos, Entity&e)
{
	if(s.getData(pos)==0)
		mSlimeBlock->onStepOn(e,pos);
	else
		return mVine->entityInside(s,pos,e);
}
bool ResinBlock::shouldStopFalling(Entity&)
{
	return true;
}
