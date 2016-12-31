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
	virtual std::unique_ptr<ICBlockEntity> getBlockEntity(BlockSource&,BlockPos const&)const=0;
};
