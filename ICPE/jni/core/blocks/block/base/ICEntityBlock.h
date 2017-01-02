#pragma once

#include "blocks/Blocks.h"

#include <memory>

class ICBlockEntity;

class ICEntityBlock : public IC::Blocks
{
public:
	ICEntityBlock();
public:
	ICEntityBlock(std::string const&,int, const Material&);
public:
	virtual bool isICEntityBlock()const;
	virtual void onLoaded(BlockSource&, BlockPos const&) const;
	virtual void onPlace(BlockSource&, BlockPos const&) const;
	virtual void onRemove(BlockSource&, BlockPos const&) const;
	virtual void onMove(BlockSource&, BlockPos const&, BlockPos const&) const;
	virtual std::shared_ptr<ICBlockEntity> getBlockEntity(BlockSource&,BlockPos const&)const=0;
};
