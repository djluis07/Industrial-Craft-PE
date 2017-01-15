#if 0


#include "BatBoxBlock.h"

#include "items/Items.h"
#include "blocks/Blocks.h"

#include "mcpe/item/Item.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/entity/Entity.h"
#include "mcpe/entity/Mob.h"
#include "mcpe/entity/EntityClassTree.h"
#include "mcpe/util/EntityDamageSource.h"

#include "util/ICOptions.h"
#include "blocks/blockentity/BatBoxBlockEntity.h"
#include "ICPE.h"

BatBoxBlock::BatBoxBlock():
ICEntityBlock("ic.batbox",IC::Blocks::ID::mBatBox,Material::getMaterial(MaterialType::DEVICE))
{
	init();
	setCategory(CreativeItemCategory::DECORATIONS);
	setExplodeable(10);
	setDestorySpeed(4);
}
bool CableBlock::detachesOnPistonMove(BlockSource&, BlockPos const&)const
{
	return true;
}
int CableBlock::getResource(Random&, int aux,int)const
{
	return ID::mBatBox;
}
int CableBlock::getResourceCount(Random&, int, int)const
{
	return 1;
}
bool CableBlock::canBeSilkTouched() const
{
	return true;
}
int CableBlock::getSpawnResourcesAuxValue(unsigned char i)const
{
	return i;
}
std::string CableBlock::buildDescriptionName(unsigned char aux) const
{
	return "ic.batbox";
}
bool CableBlock::hasComparatorSignal()const
{
	return true;
}
int CableBlock::getComparatorSignal(BlockSource&, BlockPos const&, signed char, int)const
{
	return 1;
}
int CableBlock::getPlacementDataValue(Entity&, BlockPos const&, signed char, Vec3 const&, int aux) const
{
	return aux;
}
AABB const& CableBlock::getVisualShape(BlockSource&s, BlockPos const&pos, AABB&, bool) const
{
	float defaultDistance=CableUtil::isGlassCable(s.getData(pos))?0.375:0.3125;
	return {defaultDistance,defaultDistance,defaultDistance,1-defaultDistance,1-defaultDistance,1-defaultDistance};
}
AABB const& CableBlock::getVisualShape(unsigned char aux, AABB&, bool) const
{
	float defaultDistance=CableUtil::isGlassCable(aux)?0.375:0.3125;
	return {defaultDistance,defaultDistance,defaultDistance,1-defaultDistance,1-defaultDistance,1-defaultDistance};
}
bool CableBlock::isElectricConductor()const
{
	return true;
}
std::shared_ptr<ICBlockEntity> CableBlock::getBlockEntity(BlockSource&s,BlockPos const&pos)const
{
	return std::make_shared<CableBlockEntity>(s,pos,this);
}

#endif
