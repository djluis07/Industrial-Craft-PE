#pragma once

#include "mcpe/util/FullBlock.h"

#include "Feature.h"

class FullBlock;
class BlockPos;
class BlockSource;
class Random;

namespace IC
{
class RubTreeFeature : public IC::Feature
{
protected:
	int maxTreeHeight;
	FullBlock log;
	FullBlock log2;
	FullBlock leaf;
public:
	RubTreeFeature(FullBlock const&log,FullBlock const&log2,FullBlock const&leaf,int max);
	~RubTreeFeature()=default;
public:
	bool place(BlockSource&,BlockPos const&,Random&)const;
protected:
	bool grow(BlockSource&,BlockPos const&,Random&)const;
	int getGrowHeight(BlockSource&,BlockPos const&)const;
	bool canBeReplacedByWood(BlockSource&,BlockPos const&)const;
	bool canBeReplacedByLeaves(BlockSource&,BlockPos const&)const;
};
}
