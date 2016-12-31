#pragma once

#include <memory>

#include "ICBlockEntity.h"
#include "mca/data/Database.h"
#include "mcpe/level/ChunkPos.h"

class ICBlockEntity;
class ChunkBlockPos;
class BlockPos;
class BlockSource;
class ChunkPos;
class Level;

class BlockEntityChunkContainer
{
public:
	std::unique_ptr<ICBlockEntity> mBlockEntities[16][256][16];
	BlockSource*s;
	ChunkPos pos;
	mca::Database localTag;
public:
	BlockEntityChunkContainer(std::string const&,ChunkPos const&,BlockSource&);
	~BlockEntityChunkContainer()=default;
public:
	void tick(Level&);
	void load();
	void save();
	void addNew(ChunkBlockPos const&,std::unique_ptr<ICBlockEntity>);
	void remove(ChunkBlockPos const&);
	std::unique_ptr<ICBlockEntity>& getICBlockEntity(ChunkBlockPos const&);
};
