#include "CableBlock.h"

#include "items/Items.h"
#include "blocks/Blocks.h"

#include "mcpe/item/Item.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/entity/Entity.h"
#include "mcpe/entity/Mob.h"
#include "mcpe/entity/EntityClassTree.h"
#include "mcpe/util/EntityDamageSource.h"

#include "client/ICClient.h"
#include "client/ICOptions.h"

CableBlock::CableBlock():ElectricConductorBlock("ic.cable.tin",IC::Blocks::ID::mCable,Material::getMaterial(MaterialType::DEVICE))
{
	init();
	setSolid(false);
	setVisualShape({0.25,0.25,0.25,0.75,0.75,0.75});
	renderLayer=mGlass->renderLayer;
}
bool CableBlock::detachesOnPistonMove(BlockSource&, BlockPos const&)
{
	return true;
}
int CableBlock::getResource(Random&, int, int)
{
	return IC::Items::ID::mCable;
}
int CableBlock::getResourceCount(Random&, int, int)
{
	return 1;
}
bool CableBlock::canBeSilkTouched() const
{
	return false;
}
int CableBlock::getSpawnResourcesAuxValue(unsigned char i)
{
	return i;
}
std::string CableBlock::buildDescriptionName(unsigned char aux) const
{
	return "cable";//Item::mItems[IC::Items::ID::mCable]->buildDescriptionName(ItemInstance();
}
void CableBlock::neighborChanged(BlockSource&, BlockPos const&, BlockPos const&)
{
	
}
bool CableBlock::entityInside(BlockSource&s, BlockPos const&pos, Entity&e)
{
	if(!ICClient::mInstance.getOptions().getElectricityHurt())
		return false;
	if(!(s.getData(pos)==0||s.getData(pos)==2||s.getData(pos)==6||s.getData(pos)==9))
		return false;
	/*if(EntityClassTree::isMob(e))
	{
		e.doFireHurt(1);
		e.setOnFire(20);
	}
	else e.remove();*/
	return true;
}
bool CableBlock::hasComparatorSignal()
{
	return true;
}
int CableBlock::getComparatorSignal(BlockSource&, BlockPos const&, signed char, int)
{
	return 1;
}
