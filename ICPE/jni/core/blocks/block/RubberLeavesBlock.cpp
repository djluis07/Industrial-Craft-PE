#include "RubberLeavesBlock.h"

#include "mcpe/level/BlockSource.h"
#include "mcpe/item/ItemInstance.h"
#include "mcpe/block/blocks/FireBlock.h"

#include "client/ICClient.h"
#include "util/ICRandom.h"
#include "blocks/Blocks.h"

RubberLeavesBlock::RubberLeavesBlock():IC::Blocks("ic.rubber.leaves",IC::Blocks::ID::mRubberLeaves,Material::getMaterial(MaterialType::PLANT))
{
	init();
	setCategory(CreativeItemCategory::DECORATIONS);
	setSolid(false);
	//setSoundType(BlockSoundType::SOUND_DEFAULT);
	setExplodeable(1);
	setDestroyTime(0.2);
	renderLayer=mLeaves->renderLayer;
	setTicking(true);
	
	((FireBlock*)mFire)->setFlammable(BlockID(IC::Blocks::ID::mRubberLeaves),65,25);
}
int RubberLeavesBlock::getResource(Random&, int id, int)
{
	return id==359?IC::Blocks::ID::mRubberLeaves:IC::Blocks::ID::mRubberSapling;
}
int RubberLeavesBlock::getResourceCount(Random&, int id, int)
{
	return id==359?1:(ICClient::mInstance.getRandom().nextInt(10)==9?1:0);
}
ItemInstance RubberLeavesBlock::getSilkTouchItemInstance(unsigned char)
{
	return ItemInstance(IC::Blocks::ID::mRubberLeaves,1,0);
}
int RubberLeavesBlock::getRenderLayer(BlockSource&s, BlockPos const&pos) const
{
	return mLeaves->getRenderLayer(s,pos);
}
int RubberLeavesBlock::getColor(BlockSource&, BlockPos const&) const
{
	return 8431445;
}
void RubberLeavesBlock::tick(BlockSource&s, BlockPos const&pos, Random&)
{
	
}
