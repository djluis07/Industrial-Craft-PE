#include "CableBlock.h"

#include "items/Items.h"
#include "blocks/Blocks.h"

#include "mcpe/item/Item.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/entity/Entity.h"
#include "mcpe/entity/Mob.h"
#include "mcpe/entity/EntityClassTree.h"
#include "mcpe/util/EntityDamageSource.h"

#include "client/ICOptions.h"

#include "ICPE.h"

CableBlock::CableBlock():ElectricConductorBlock("ic.cable.tin",IC::Blocks::ID::mCable,Material::getMaterial(MaterialType::DEVICE))
{
	init();
	setSolid(false);
	setVisualShape({0.25,0.25,0.25,0.75,0.75,0.75});
	renderLayer=mGlass->renderLayer;
}
bool CableBlock::detachesOnPistonMove(BlockSource&, BlockPos const&)const
{
	return true;
}
int CableBlock::getResource(Random&, int, int)const
{
	return IC::Items::ID::mCable;
}
int CableBlock::getResourceCount(Random&, int, int)const
{
	return 1;
}
bool CableBlock::canBeSilkTouched() const
{
	return false;
}
int CableBlock::getSpawnResourcesAuxValue(unsigned char i)const
{
	return i;
}
std::string CableBlock::buildDescriptionName(unsigned char aux) const
{
	return "cable";//Item::mItems[IC::Items::ID::mCable]->buildDescriptionName(ItemInstance();
	
	//uncompleted
}
void CableBlock::neighborChanged(BlockSource&, BlockPos const&, BlockPos const&)const
{
	
}
bool CableBlock::entityInside(BlockSource&s, BlockPos const&pos, Entity&e)const
{
	//uncompleted
	if(!ICPE::mICOptions.getElectricityHurt())
		return false;
	if(!(s.getData(pos)==0||s.getData(pos.x,pos.y,pos.z)==2||s.getData(pos.x,pos.y,pos.z)==6||s.getData(pos.x,pos.y,pos.z)==9))
		return false;
	
	e.doFireHurt(1);
	e.setOnFire(20);

	return true;
}
bool CableBlock::hasComparatorSignal()const
{
	return true;
}
int CableBlock::getComparatorSignal(BlockSource&, BlockPos const&, signed char, int)const
{
	return 1;
}
