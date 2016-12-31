#pragma once

#include <string>

#include "mcpe/util/BlockPos.h"

class Block;
class Level;
class BlockSource;

class ICBlockEntity
{
public:
	BlockPos position;
	Block*block;
	std::string path;
	bool changed;
	BlockSource* source;
public:
	ICBlockEntity(BlockPos,BlockSource&,Block*);
	~ICBlockEntity()=default;
public:
	virtual void tick(Level&);
public:
	virtual void load();
	virtual void save();
	virtual void remove();
	virtual void create();
	virtual void moveTo(BlockPos const&);
protected:
	void setChanged();
	void update();
};
