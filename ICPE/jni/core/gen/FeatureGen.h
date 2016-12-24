#pragma once

#include <memory>

class BlockSource;
class BlockPos;
class Biome;
class Random;

namespace IC
{
class Feature;

class FeatureGen
{
private:
	static bool inited;
	static std::shared_ptr<IC::Feature> rubTree;
	static std::shared_ptr<IC::Feature> tinOre;
	static std::shared_ptr<IC::Feature> copperOre;
	static std::shared_ptr<IC::Feature> leadOre;
	static std::shared_ptr<IC::Feature> uraniumOre;
public:
	static void decorateChunk(BlockSource&, Random&,Biome*,BlockPos const&);
private:
	static unsigned int getRubGenChance(Biome&);
	static void prepare();
};
}
