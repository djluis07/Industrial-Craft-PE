#pragma once

#include "blocks/Blocks.h"

class RubberWoodBlock : public IC::Blocks
{
public:
	RubberWoodBlock();
public:
	virtual void tick(BlockSource&, BlockPos const&, Random&);
	virtual int getSpawnResourcesAuxValue(unsigned char);
	virtual int getPlacementDataValue(Mob&, BlockPos const&, signed char, Vec3 const&, int);

};
