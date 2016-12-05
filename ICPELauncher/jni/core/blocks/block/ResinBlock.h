#pragma once

#include "blocks/Blocks.h"

class ResinBlock : public IC::Blocks
{
public:
	ResinBlock();
public:
	virtual bool shouldStopFalling(Entity&);
	virtual bool entityInside(BlockSource&, BlockPos const&, Entity&);
	virtual int getSpawnResourcesAuxValue(unsigned char);
	virtual int getResource(Random&, int, int);
	virtual bool mayPlaceOn(Block const&);
	virtual void neighborChanged(BlockSource&, BlockPos const&, BlockPos const&);
};
