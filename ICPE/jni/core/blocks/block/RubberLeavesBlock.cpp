#include "RubberLeavesBlock.h"

#include "mcpe/level/BlockSource.h"
#include "mcpe/item/ItemInstance.h"
#include "mcpe/block/blocks/FireBlock.h"
#include "mcpe/util/Random.h"

#include "blocks/Blocks.h"

#include "ICPE.h"

RubberLeavesBlock::RubberLeavesBlock():IC::Blocks("ic.rubber.leaves",IC::Blocks::ID::mRubberLeaves,Material::getMaterial(MaterialType::PLANT))
{
	init();
	setCategory(CreativeItemCategory::DECORATIONS);
	setSolid(false);
	//setSoundType(BlockSoundType::SOUND_DEFAULT);
	setExplodeable(1);
	setDestroyTime(0.2);
	setTicking(true);
	setVisualShape({0.001,0.001,0.001,1,1,1});
	renderLayer=mLeaves->renderLayer;
	
	((FireBlock*)mFire)->setFlammable(BlockID(IC::Blocks::ID::mRubberLeaves),65,25);
}
int RubberLeavesBlock::getResource(Random&, int id, int)const
{
	return id==359?IC::Blocks::ID::mRubberLeaves:IC::Blocks::ID::mRubberSapling;
}
int RubberLeavesBlock::getResourceCount(Random&r, int id, int)const
{
	return id==359?1:(r.nextInt(10)==9?1:0);
}
ItemInstance RubberLeavesBlock::getSilkTouchItemInstance(unsigned char)const
{
	return ItemInstance(IC::Blocks::ID::mRubberLeaves,1,0);
}
void RubberLeavesBlock::onGraphicsModeChanged(bool, bool, bool)
{
	renderLayer=mLeaves->renderLayer;
}
int RubberLeavesBlock::getRenderLayer(BlockSource&s, BlockPos const&pos) const
{
	return mLeaves->getRenderLayer(s,pos);
}
int RubberLeavesBlock::getExtraRenderLayers() const
{
	return mLeaves->getExtraRenderLayers();
}
bool RubberLeavesBlock::isSeasonTinted(BlockSource&, BlockPos const&) const
{
	return true;
}
void RubberLeavesBlock::tick(BlockSource&s, BlockPos const&pos, Random&r)const
{
	if(r.nextBool(8))
	{
		
	}
}
int RubberLeavesBlock::getPlacementDataValue(Entity&, BlockPos const&, signed char, Vec3 const&, int) const
{
	return 4;
}
