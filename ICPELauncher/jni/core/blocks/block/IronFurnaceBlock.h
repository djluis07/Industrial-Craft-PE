#pragma once

#include "blocks/Blocks.h"

class IronFurnaceBlock : public IC::Blocks
{
public:
	IronFurnaceBlock();
public:
	virtual bool use(Player&, BlockPos const&);
	virtual int getPlacementDataValue(Mob&, BlockPos const&, signed char, Vec3 const&, int);
};
