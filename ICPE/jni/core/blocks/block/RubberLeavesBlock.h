#pragma once

#include "blocks/Blocks.h"

class RubberLeavesBlock : public IC::Blocks
{
public:
	RubberLeavesBlock();
public:
	virtual void tick(BlockSource&, BlockPos const&, Random&);
	virtual int getResource(Random&, int, int);
	virtual int getResourceCount(Random&, int, int);
	virtual ItemInstance getSilkTouchItemInstance(unsigned char);
	virtual int getRenderLayer(BlockSource&, BlockPos const&) const;
	virtual int getColor(BlockSource&, BlockPos const&) const;
};
