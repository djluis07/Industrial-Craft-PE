#pragma once

#include <vector>
#include <string>
#include <memory>

#include "BlockEntityChunkContainer.h"

class ICBlockEntity;
class BlockPos;
class Level;
class BlockSource;

class ICBlockEntityManager
{
public:
	std::vector<BlockEntityChunkContainer>list;
	BlockSource*s;
	std::string path;
public:
	ICBlockEntityManager()=default;
	ICBlockEntityManager(std::string const&,BlockSource&);
	~ICBlockEntityManager()=default;
public:
	std::unique_ptr<ICBlockEntity>& getBlockEntity(BlockPos const&);
	void removeBlockEntity(BlockPos const&);
	void addNew(std::unique_ptr<ICBlockEntity>);
	void tick(Level&);
	void save();
	void load();
protected:	
	int getBlockEntityPos(BlockPos const&);
};
