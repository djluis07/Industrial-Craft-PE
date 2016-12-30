#include "Blocks.h"

#include "mcpe/client/resources/I18n.h"

#include "util/Log.h"

#include "block/ICOreBlock.h"
#include "block/RubberSaplingBlock.h"
#include "block/MetalBlock.h"
#include "block/ITNTBlock.h"
#include "block/RubberWoodBlock.h"
#include "block/ResinBlock.h"
#include "block/RubberLeavesBlock.h"
#include "block/CableBlock.h"
#include "block/IronFurnaceBlock.h"
#include "block/IronFenceBlock.h"

bool IC::Blocks::mICBlocks[256];

namespace IC
{
void Blocks::initICBlocks()
{
	for(bool & block : mICBlocks)
		block=false;
	
	Block::mBlocks[ID::mIronFurnace]=new IronFurnaceBlock();
	Block::mBlocks[ID::mCable]=new CableBlock();
	Block::mBlocks[ID::mRubberLeaves]=new RubberLeavesBlock();
	Block::mBlocks[ID::mResin]=new ResinBlock();
	Block::mBlocks[ID::mRubberWood]=new RubberWoodBlock();
	Block::mBlocks[ID::mITNT]=new ITNTBlock();
	Block::mBlocks[ID::mRubberSapling]=new RubberSaplingBlock();
	Block::mBlocks[ID::mOre]=new ICOreBlock();
	Block::mBlocks[ID::mIronFence]=new IronFenceBlock();
	Block::mBlocks[ID::mOre]=new ICOreBlock();
	Block::mBlocks[ID::mMetal]=new MetalBlock();
}
bool Blocks::isElectricBlock()const
{
	return false;
}
bool Blocks::isElectricConductor()const
{
	return false;
}
bool Blocks::shouldExplodeOutOfVoltage()const
{
	return false;
}
int Blocks::getElectricResistance()const
{
	return 0;
}
int Blocks::getMaxVoltage()const
{
	return INT_MAX;
}
bool Blocks::isElectricProvider()const
{
	return false;
}
bool Blocks::isElectricRecevier()const
{
	return false;
}
int Blocks::getNowVoltage(BlockSource&,BlockPos const&)const
{
	return 0;
}
Blocks::Blocks(std::string const&name,int id,Material const&m):Block(name,id,m)
{
	mICBlocks[id]=true;
	LOG_P("Block defined:name="+name+",id="+Util::toString(id));
}
bool Blocks::isAnyAuxValueInRecipe()const
{
	return true;
}
}
