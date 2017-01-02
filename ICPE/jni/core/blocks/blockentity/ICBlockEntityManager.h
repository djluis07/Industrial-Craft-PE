#pragma once

#include <vector>
#include <string>
#include <memory>

#include "ICBlockEntity.h"
#include "mca/data/Database.h"

class ICBlockEntity;
class BlockPos;
class Level;
class BlockSource;
class ChunkPos;

class ICBlockEntityManager
{
public:
	std::vector<std::shared_ptr<ICBlockEntity>>mBlockEntities;
	mca::Database localTag;
public:
	ICBlockEntityManager()=default;
	ICBlockEntityManager(std::string const&);
	~ICBlockEntityManager();
public:
	ICBlockEntity* getBlockEntity(BlockSource&,BlockPos const&);
	void removeBlockEntity(BlockPos const&);
	void addNew(std::shared_ptr<ICBlockEntity>);
	void save();
	void load(BlockSource&,BlockPos const&);
public:
	inline void tick(Level&l)
	{
		for(std::shared_ptr<ICBlockEntity> bd : mBlockEntities)
			if(bd)bd->tick(l);
	}
	static std::string getLocalPath();
	static bool access(std::string const&);
};
