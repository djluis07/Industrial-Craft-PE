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
#include "util/CableUtil.h"

#include "ICPE.h"

CableBlock::CableBlock():ElectricConductorBlock("ic.cable.tin",IC::Blocks::ID::mCable,Material::getMaterial(MaterialType::DEVICE))
{
	init();
	setSolid(false);
}
void CableBlock::addCollisionShapes(BlockSource&s, BlockPos const&pos, AABB const*pAABB, std::vector<AABB, std::allocator<AABB> >&list,Entity*) const
{
	float defaultDistance=CableUtil::isGlassCable(s.getData(pos))?0.375:0.3125;
	
	if(CableUtil::canConnectTo(s,pos,{pos.x,pos.y+1,pos.z}))
		list.push_back({pos.x+defaultDistance,pos.y+1-defaultDistance,pos.z+defaultDistance,pos.x+1-defaultDistance,pos.y+1,pos.z+1-defaultDistance});
	if(CableUtil::canConnectTo(s,pos,{pos.x,pos.y-1,pos.z}))
		list.push_back({pos.x+defaultDistance,pos.y+0,pos.z+defaultDistance,pos.z+1-defaultDistance,pos.y+defaultDistance,pos.z+1-defaultDistance});
	if(CableUtil::canConnectTo(s,pos,{pos.x,pos.y,pos.z+1}))
		list.push_back({pos.x+defaultDistance,pos.y+defaultDistance,pos.z+1-defaultDistance,pos.y+1-defaultDistance,pos.z+1-defaultDistance,1});
	if(CableUtil::canConnectTo(s,pos,{pos.x,pos.y,pos.z-1}))
		list.push_back({pos.x+defaultDistance,pos.y+defaultDistance,pos.z+0,pos.x+1-defaultDistance,pos.y+1-defaultDistance,pos.z+defaultDistance});
	if(CableUtil::canConnectTo(s,pos,{pos.x+1,pos.y,pos.z}))
		list.push_back({pos.x+1-defaultDistance,pos.y+defaultDistance,pos.z+defaultDistance,pos.x+1,pos.y+1-defaultDistance,pos.z+1-defaultDistance});
	if(CableUtil::canConnectTo(s,pos,{pos.x-1,pos.y,pos.z}))
		list.push_back({pos.x+0,pos.y+defaultDistance,pos.z+defaultDistance,pos.x+defaultDistance,pos.y+1-defaultDistance,pos.z+1-defaultDistance});
	list.push_back({pos.x+defaultDistance,pos.y+defaultDistance,pos.z+defaultDistance,pos.x+1-defaultDistance,pos.y+1-defaultDistance,pos.z+1-defaultDistance});
	Block::addAABBs(s,pos,pAABB,list);
}
bool CableBlock::detachesOnPistonMove(BlockSource&, BlockPos const&)const
{
	return true;
}
int CableBlock::getResource(Random&, int aux,int)const
{
	return CableUtil::getDropItemID(aux);
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
	if(!(s.getData(pos)==0||s.getData(pos)==2||s.getData(pos)==6||s.getData(pos)==9))
		return false;
	
	e.doFireHurt(CableUtil::getHurt(s.getData(pos)));
	e.setOnFire(CableUtil::getFire(s.getData(pos)));

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
