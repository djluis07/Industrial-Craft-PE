#pragma once

#include "base/ICEntityBlock.h"

class ICFurnaceBlock : public ICEntityBlock
{
public:
	ICFurnaceBlock();
public:
	virtual std::shared_ptr<ICBlockEntity> getBlockEntity(BlockSource&,BlockPos const&)const;
	virtual bool use(Player&, BlockPos const&)const;
	virtual int getPlacementDataValue(Entity&, BlockPos const&, signed char, Vec3 const&, int)const;
};
