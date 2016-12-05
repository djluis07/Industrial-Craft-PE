#include "RubberSaplingBlock.h"

#include "mcpe/level/BlockSource.h"

RubberSaplingBlock::RubberSaplingBlock():IC::Blocks("ic.rubber.sapling",IC::Blocks::ID::mRubberSapling,Material::getMaterial(MaterialType::PLANT))
{
	setCategory(CreativeItemCategory::DECORATIONS);
	//setSoundType(BlockSoundType::SOUND_DEFAULT);
	setTicking(true);
	setSolid(false);
	renderLayer=4;
}
const AABB& RubberSaplingBlock::getCollisionShape(AABB&box, BlockSource&s, BlockPos const&pos, Entity*e)
{
	return mSapling->getCollisionShape(box,s,pos,e);
}
void RubberSaplingBlock::tick(BlockSource&, BlockPos const&, Random&)
{
	
}
void RubberSaplingBlock::onFertilized(BlockSource&s, BlockPos const&pos, Player*p)
{
	return mSapling->onFertilized(s,pos,p);
}
bool RubberSaplingBlock::mayPlaceOn(Block const&b)
{
	return mSapling->mayPlaceOn(b);
}
bool RubberSaplingBlock::canSurvive(BlockSource&s, BlockPos const&pos)
{
	return mSapling->canSurvive(s,pos);
}
void RubberSaplingBlock::neighborChanged(BlockSource&s, BlockPos const&pos, BlockPos const&pos2)
{
	if(!canSurvive(s,pos)&&s.getBlock(pos.x,pos.y,pos.z)==this)
	{
		s.removeBlock(pos.x,pos.y,pos.z);
		popResource(s,pos,ItemInstance(IC::Blocks::ID::mRubberSapling,1,0));
	}
}
bool RubberSaplingBlock::checkIsPathable(Entity&, BlockPos const&, BlockPos const&)
{
	return true;
}
