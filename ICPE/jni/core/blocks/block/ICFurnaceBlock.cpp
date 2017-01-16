#include "ICFurnaceBlock.h"

#include "ICPE.h"
#include "ui/UIScreenChooser.h"

#include "mcpe/item/ItemInstance.h"
#include "blocks/blockentity/IronFurnaceBlockEntity.h"

ICFurnaceBlock::ICFurnaceBlock():ICEntityBlock("ic.ironfurnace",IC::Blocks::ID::mFurnace,Material::getMaterial(MaterialType::STONE))
{
	init();
	setCategory(CreativeItemCategory::DECORATIONS);
	setSolid(true);
	setDestroyTime(3);
	setExplodeable(15);
}
int ICFurnaceBlock::getPlacementDataValue(Entity&e, BlockPos const&pos, signed char side, Vec3 const&pixel, int aux)const
{
	return mFurnace->getPlacementDataValue(e,pos,side,pixel,aux)-2;
}
bool ICFurnaceBlock::use(Player&p, BlockPos const&pos)const
{
	ICPE::mUIScreenChooser.pushIronFurnaceScreen(p,pos);
	return true;
}
std::shared_ptr<ICBlockEntity> ICFurnaceBlock::getBlockEntity(BlockSource&s,BlockPos const&pos)const
{
	return std::make_shared<IronFurnaceBlockEntity>(s,pos,this);
}
