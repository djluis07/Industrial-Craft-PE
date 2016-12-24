#pragma once

#include "mcpe/util/FullBlock.h"

#include "Feature.h"

class FullBlock;
class BlockPos;
class BlockSource;
class Random;

namespace IC
{
class OreFeature : public IC::Feature
{
public:
	enum class OreGenType
	{
		ALONE,
		SMALL,
		MIDDLE,
		BIG,
		LARGE
	};
protected:
	FullBlock oreBlock;
	OreGenType type;
public:
	OreFeature(FullBlock,OreGenType);
	~OreFeature()=default;
public:
	bool place(BlockSource&,BlockPos const&,Random&)const;
protected:
	void checkToPlace(BlockSource&,BlockPos const&)const;
	void checkToPlace(BlockSource&,int,int,int)const;
};
}
