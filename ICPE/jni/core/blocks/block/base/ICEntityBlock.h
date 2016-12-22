#pragma once

#include "blocks/Blocks.h"

class Level;
class ICBlockEntity;

class ICEntityBlock : public IC::Blocks
{
public:
	ICEntityBlock();
public:
	ICEntityBlock(std::string const&,int, const Material&);
public:
	virtual void onPlace(BlockSource&, BlockPos const&)const;
	virtual void onRemove(BlockSource&, BlockPos const&)const;
	virtual void onLoaded(BlockSource&, BlockPos const&)const;
	virtual void onMove(BlockSource&, BlockPos const&, BlockPos const&)const;
public:
	virtual ICBlockEntity* newICBlockEntity(BlockPos,BlockSource&)const=0;
};
