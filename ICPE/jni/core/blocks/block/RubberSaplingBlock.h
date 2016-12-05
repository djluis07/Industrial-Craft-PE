#pragma once

#include "blocks/Blocks.h"

class RubberSaplingBlock : public IC::Blocks
{
public:
	RubberSaplingBlock();
public:
	virtual const AABB& getCollisionShape(AABB&, BlockSource&, BlockPos const&, Entity*);
	virtual void tick(BlockSource&, BlockPos const&, Random&);
	virtual void onFertilized(BlockSource&, BlockPos const&, Player*);
	virtual bool mayPlaceOn(Block const&);
	virtual bool canSurvive(BlockSource&, BlockPos const&);
	virtual void neighborChanged(BlockSource&, BlockPos const&, BlockPos const&);
	virtual bool checkIsPathable(Entity&, BlockPos const&, BlockPos const&);
};
