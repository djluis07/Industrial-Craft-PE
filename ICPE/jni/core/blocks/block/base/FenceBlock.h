#pragma once

#include "mcpe/block/Block.h"

class FenceBlock : public Block
{
public:
	FenceBlock(std::string const&,int,Material const&);
public:
	virtual bool isFenceBlock() const;
	virtual const AABB& getVisualShape(BlockSource&, BlockPos const&, AABB&, bool)const;
	virtual int getSpawnResourcesAuxValue(unsigned char)const;
	virtual bool use(Player&, BlockPos const&)const;
	virtual const AABB& getAABB(BlockSource&, BlockPos const&, AABB&, int, bool, int)const;
	virtual bool canBeSilkTouched() const;
	virtual std::string buildDescriptionName(unsigned char aux) const;
};
