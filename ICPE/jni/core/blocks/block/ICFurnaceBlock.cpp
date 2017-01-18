#include "ICFurnaceBlock.h"

#include "ICPE.h"
#include "ui/UIScreenChooser.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/entity/player/Player.h"
#include "mcpe/level/BlockSource.h"
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
	if(aux==0)
		return mFurnace->getPlacementDataValue(e,pos,side,pixel,0)-2;
	else
		return mFurnace->getPlacementDataValue(e,pos,side,pixel,0)+2;
}
bool ICFurnaceBlock::use(Player&p, BlockPos const&pos)const
{
	if(p.getRegion().getData(pos)<4)
		ICPE::mUIScreenChooser.pushIronFurnaceScreen(p,pos);
//	else
//		ICPE::mUIScreenChooser.pushElectricFurnaceScreen(p,pos);
	return true;
}
std::shared_ptr<ICBlockEntity> ICFurnaceBlock::getBlockEntity(BlockSource&s,BlockPos const&pos)const
{
	if(s.getData(pos)<4)
		return std::make_shared<IronFurnaceBlockEntity>(s,pos,this);
	return std::make_shared<IronFurnaceBlockEntity>(s,pos,this);
}
