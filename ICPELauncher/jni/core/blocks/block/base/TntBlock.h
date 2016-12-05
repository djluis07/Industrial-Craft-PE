#pragma once

#include "mcpe/block/Block.h"

class TntBlock : public Block
{
public:
	TntBlock(std::string const&,int);
public:
	virtual void onExploded(BlockSource&, BlockPos const&, Entity*);
	virtual int getResourceCount(Random&, int, int);
	virtual void onRedstoneUpdate(BlockSource&, BlockPos const&, int, bool);
	virtual bool use(Player&, BlockPos const&);
	virtual void destroy(BlockSource&, BlockPos const&, int, Entity*);
	virtual void onPlace(BlockSource&, BlockPos const&);
	virtual void dispense(BlockSource&, Container&, int, Vec3 const&, signed char);
	virtual void onLoaded(BlockSource&, BlockPos const&);
};
