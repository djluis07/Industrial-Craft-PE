#pragma once

#include "ic/blocks/Blocks.h"

class Level;
class ICBlockEntity;

class ICEntityBlock : public IC::Blocks
{
public:
	ICEntityBlock();
public:
	ICEntityBlock(std::string const&,int, const Material&);
public:
	virtual void onPlace(BlockSource&, BlockPos const&);
	virtual void onRemove(BlockSource&, BlockPos const&);
	virtual void onLoaded(BlockSource&, BlockPos const&);
	virtual void onMove(BlockSource&, BlockPos const&, BlockPos const&);
public:
	virtual ICBlockEntity* newICBlockEntity(BlockPos,BlockSource&)=0;
};
