#pragma once

#include <vector>
#include <string>

class ICBlockEntity;
class BlockPos;
class Level;

class ICBlockEntityManager
{
public:
	std::vector<ICBlockEntity*>icBlockEntityList;
public:
	ICBlockEntityManager();
	~ICBlockEntityManager();
public:
	ICBlockEntity *getBlockEntity(BlockPos const&);
	void removeBlockEntity(BlockPos const&);
	void addNew(ICBlockEntity*);
	void tick(Level&);
	void save();
protected:	
	int getBlockEntityPos(BlockPos const&);
};
