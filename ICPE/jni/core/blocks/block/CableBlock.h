#pragma once

#include "base/ElectricConductorBlock.h"

class CableBlock : public ElectricConductorBlock
{
public:
	CableBlock();
public:
	virtual bool detachesOnPistonMove(BlockSource&, BlockPos const&)const;
	virtual int getResource(Random&, int, int)const;
	virtual int getResourceCount(Random&, int, int)const;
	virtual bool canBeSilkTouched() const;
	virtual int getSpawnResourcesAuxValue(unsigned char)const;
	virtual std::string buildDescriptionName(unsigned char aux) const;
	virtual void neighborChanged(BlockSource&, BlockPos const&, BlockPos const&)const;
	virtual bool entityInside(BlockSource&, BlockPos const&, Entity&)const;
	virtual bool hasComparatorSignal()const;
	virtual int getComparatorSignal(BlockSource&, BlockPos const&, signed char, int)const;
};
