#pragma once

#include <memory>

class BlockSource;
class ChunkPos;

namespace IC
{
class FeatureGen
{
public:
	static void decorateChunk(BlockSource&, ChunkPos const&);
};
}
