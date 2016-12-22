#pragma once

#include "blocks/Blocks.h"

class IronFurnaceBlock : public IC::Blocks
{
public:
	IronFurnaceBlock();
public:
	virtual bool use(Player&, BlockPos const&)const;
	virtual int getPlacementDataValue(Entity&, BlockPos const&, signed char, Vec3 const&, int)const;
};
