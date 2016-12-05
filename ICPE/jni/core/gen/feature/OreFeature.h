#pragma once

#include "mcpe/util/FullBlock.h"

class FullBlock;
class BlockPos;
class BlockSource;
class ICRandom;

namespace IC
{
class OreFeature
{
public:
	enum class OreGenType
	{
		ALONE,SMALL,MIDDLE
	};
protected:
	FullBlock oreBlock;
	OreGenType type;
public:
	OreFeature(FullBlock,OreGenType);
	~OreFeature()=default;
public:
	void place(BlockSource&,BlockPos const&,ICRandom&);
protected:
	void checkToPlace(BlockSource&,BlockPos const&);
};
}
