#pragma once

#include "blocks/Blocks.h"

class RubberLeavesBlock : public IC::Blocks
{
public:
	RubberLeavesBlock();
public:
	virtual void tick(BlockSource&, BlockPos const&, Random&)const;
	virtual int getResource(Random&, int, int)const;
	virtual int getResourceCount(Random&, int, int)const;
	virtual ItemInstance getSilkTouchItemInstance(unsigned char)const;
	virtual bool isSeasonTinted(BlockSource&, BlockPos const&) const;
	virtual void onGraphicsModeChanged(bool, bool, bool);
	virtual int getRenderLayer(BlockSource&, BlockPos const&) const;
	virtual int getExtraRenderLayers() const;
	virtual int getPlacementDataValue(Entity&, BlockPos const&, signed char, Vec3 const&, int) const;
};
