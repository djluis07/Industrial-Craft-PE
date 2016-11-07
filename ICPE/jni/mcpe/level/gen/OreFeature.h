#pragma once
#include "Feature.h"
#include "mcpe/util/BlockID.h"

class BlockSource;
class BlockPos;
class Random;

class OreFeature : public Feature
{
	BlockID id;
	unsigned char data;
	int veinSize;
	
public:
	OreFeature(BlockID, int);
	OreFeature(BlockID, unsigned char, int);
	
	virtual ~OreFeature();
	virtual bool place(BlockSource&, const BlockPos&, Random&) const;
};
