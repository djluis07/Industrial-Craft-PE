#pragma once

#include "base/ElectricConductorBlock.h"

class CableBlock : public ElectricConductorBlock
{
public:
	CableBlock();
public:
	virtual bool detachesOnPistonMove(BlockSource&, BlockPos const&);
	virtual int getResource(Random&, int, int);
	virtual int getResourceCount(Random&, int, int);
	virtual bool canBeSilkTouched() const;
	virtual int getSpawnResourcesAuxValue(unsigned char);
	virtual std::string buildDescriptionName(unsigned char aux) const;
	virtual void neighborChanged(BlockSource&, BlockPos const&, BlockPos const&);
	virtual bool entityInside(BlockSource&, BlockPos const&, Entity&);
	virtual bool hasComparatorSignal();
	virtual int getComparatorSignal(BlockSource&, BlockPos const&, signed char, int);
};
