#pragma once

class ICLevel;
class ICBlockEntity;
class ChunkBlockPos;
class BlockPos;
class BlockSource;
class ChunkPos;
class Level;

class BlockEntityChunkContainer
{
public:
	ICBlockEntity* mBlockEntities[16][128][16];
public:
	BlockEntityChunkContainer(ICLevel&,ChunkPos const&,BlockSource&);
	~BlockEntityChunkContainer();
public:
	void tick(Level&);
	void load();
	void save();
	void addNew(ChunkBlockPos const&,ICBlockEntity*);
	void remove(ChunkBlockPos const&);
	ICBlockEntity* getICBlockEntity(ChunkBlockPos const&);
};
