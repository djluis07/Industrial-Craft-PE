#include "CableBlock.h"

#include "items/Items.h"
#include "blocks/Blocks.h"

#include "mcpe/item/Item.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/entity/Entity.h"
#include "mcpe/entity/Mob.h"
#include "mcpe/entity/EntityClassTree.h"
#include "mcpe/util/EntityDamageSource.h"

#include "util/ICOptions.h"

#include "ICPE.h"

CableBlock::CableBlock():ElectricConductorBlock("ic.cable.tin",IC::Blocks::ID::mCable,Material::getMaterial(MaterialType::DEVICE))
{
	init();
	setSolid(false);
	setVisualShape({0.25,0.25,0.25,0.75,0.75,0.75});
}
bool CableBlock::detachesOnPistonMove(BlockSource&, BlockPos const&)const
{
	return true;
}
int CableBlock::getResource(Random&, int, int aux)const
{
	switch(aux)
	{
	case 0:
	default:
		return IC::Items::ID::mTinCable0;
	case 1:
		return IC::Items::ID::mTinCable1;
	case 2:
		return IC::Items::ID::mIronCable0;
	case 3:
		return IC::Items::ID::mIronCable1;
	case 4:
		return IC::Items::ID::mIronCable2;
	case 5:
		return IC::Items::ID::mIronCable3;
	case 6:
		return IC::Items::ID::mGoldCable0;
	case 7:
		return IC::Items::ID::mGoldCable1;
	case 8:
		return IC::Items::ID::mGoldCable2;
	case 9:
		return IC::Items::ID::mCopperCable0;
	case 10:
		return IC::Items::ID::mCopperCable1;
	case 11:
		return IC::Items::ID::mDetectorCable;
	case 12:
		return IC::Items::ID::mGlassCable;
	case 13:
		return IC::Items::ID::mSplitterCable;
	}
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
	return 0;
}
std::string CableBlock::buildDescriptionName(unsigned char aux) const
{
	return "ic.cable";
}
void CableBlock::neighborChanged(BlockSource&, BlockPos const&, BlockPos const&)const
{
	
}
bool CableBlock::entityInside(BlockSource&s, BlockPos const&pos, Entity&e)const
{
	//uncompleted
	//if(!ICPE::mICOptions.getElectricityHurt())
		//return false;
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
int CableBlock::getRenderLayer(BlockSource&s, BlockPos const&pos) const
{
	return mGlass->getRenderLayer(s,pos);
}
