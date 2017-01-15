#pragma once

#include <memory>

#include "base/ElectricConductorBlock.h"
#include "base/ICEntityBlock.h"

class BatBoxBlock : public ICEntityBlock
{
public:
	BatBoxBlock();
public:
	virtual std::shared_ptr<ICBlockEntity> getBlockEntity(BlockSource&,BlockPos const&)const;
	virtual bool isElectricConductor()const;
	virtual bool detachesOnPistonMove(BlockSource&, BlockPos const&)const;
	virtual int getResource(Random&, int, int)const;
	virtual int getResourceCount(Random&, int, int)const;
	virtual bool canBeSilkTouched() const;
	virtual int getSpawnResourcesAuxValue(unsigned char)const;
	virtual std::string buildDescriptionName(unsigned char aux) const;
	virtual bool hasComparatorSignal()const;
	virtual int getPlacementDataValue(Entity&, BlockPos const&, signed char, Vec3 const&, int) const;
	virtual int getComparatorSignal(BlockSource&, BlockPos const&, signed char, int)const;
};
