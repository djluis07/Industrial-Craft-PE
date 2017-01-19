#pragma once

#include "mcpe/util/FullBlock.h"
#include "mcpe/level/gen/Feature.h"

class FullBlock;
class BlockPos;
class BlockSource;
class Random;

class RavineFeature : public Feature
{
public:
	RavineFeature();
	~RavineFeature()=default;
public:
	bool place(BlockSource&,BlockPos const&,Random&)const;
private:
	int getRandomOffset(Random&)const;
	void placeAirBlock(BlockSource&,BlockPos const&)const;
	void generateChildRavine(BlockSource&,BlockPos const&,BlockPos const&,int,int,bool,Random&)const;
	void placeAirChunk(BlockSource&,BlockPos const&,int,int,bool,Random&)const;
	void placeSpring(BlockSource&,BlockPos const&,bool)const;
};
