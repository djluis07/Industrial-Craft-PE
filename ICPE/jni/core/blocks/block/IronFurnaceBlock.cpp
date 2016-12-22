#include "IronFurnaceBlock.h"

IronFurnaceBlock::IronFurnaceBlock():IC::Blocks("ic.ironfurnace",IC::Blocks::ID::mIronFurnace,Material::getMaterial(MaterialType::STONE))
{
	init();
	setCategory(CreativeItemCategory::DECORATIONS);
	//setSoundType(BlockSoundType::SOUND_DEFAULT);
	setSolid(true);
	setDestroyTime(3);
	setExplodeable(15);
}
int IronFurnaceBlock::getPlacementDataValue(Entity&e, BlockPos const&pos, signed char side, Vec3 const&pixel, int aux)const
{
	return mFurnace->getPlacementDataValue(e,pos,side,pixel,aux)-2;
}
bool IronFurnaceBlock::use(Player&, BlockPos const&)const
{
	return true;
}
