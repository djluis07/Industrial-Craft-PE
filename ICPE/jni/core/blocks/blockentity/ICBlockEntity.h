#pragma once

#include <string>

#include "mcpe/util/BlockPos.h"

namespace mca
{
	class ComposedTag;
}
class Block;
class Level;
class BlockSource;

class ICBlockEntity
{
public:
	BlockPos pos;
	Block const*block;
	std::string path;
	bool changed;
	BlockSource& source;
public:
	ICBlockEntity(BlockSource&,BlockPos const&,Block const*);
	~ICBlockEntity()=default;
public:
	virtual inline void tick(Level&){}
	virtual void load(mca::ComposedTag &);
	virtual void save(mca::ComposedTag &);
	virtual void remove();
	virtual void moveTo(BlockPos const&);
protected:
	void update();
};
