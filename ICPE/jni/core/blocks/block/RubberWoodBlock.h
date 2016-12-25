#pragma once

#include "blocks/Blocks.h"

class RubberWoodBlock : public IC::Blocks
{
public:
	RubberWoodBlock();
public:
	virtual bool use(Player&, BlockPos const&) const;
	virtual void tick(BlockSource&, BlockPos const&, Random&)const;
	virtual int getSpawnResourcesAuxValue(unsigned char)const;
	virtual int getPlacementDataValue(Mob&, BlockPos const&, signed char, Vec3 const&, int)const;
protected:
	bool canMakeWet(BlockSource&,BlockPos const&)const;
	bool hasLeafAround(BlockSource&,BlockPos const&)const;
	bool hasWoodTop(BlockSource&,BlockPos const&)const;
};
