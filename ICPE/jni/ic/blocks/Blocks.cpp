#include "Blocks.h"

#include "mcpe/client/resources/I18n.h"

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
	/*Block::mBlocks[ID::mIronFurnace]=new IronFurnaceBlock();
	Block::mBlocks[ID::mCable]=new CableBlock();
	Block::mBlocks[ID::mRubberLeaves]=new RubberLeavesBlock();
	Block::mBlocks[ID::mResin]=new ResinBlock();
	Block::mBlocks[ID::mRubberWood]=new RubberWoodBlock();
	Block::mBlocks[ID::mITNT]=new ITNTBlock();
	Block::mBlocks[ID::mRubberSapling]=new RubberSaplingBlock();
	Block::mBlocks[ID::mOre]=new ICOreBlock();
	Block::mBlocks[ID::mIronFence]=new IronFenceBlock();
*/}
bool Blocks::isElectronicBlock()const
{
	return false;
}
bool Blocks::isElectronicConductor()const
{
	return false;
}
bool Blocks::shouldExplodeOutOfVoltage()const
{
	return false;
}
int Blocks::getElectronicResistance()const
{
	return 0;
}
int Blocks::getMaxVoltage()const
{
	return INT_MAX;
}
bool Blocks::isElectronicProvider()const
{
	return false;
}
bool Blocks::isElectronicRecevier()const
{
	return false;
}
int Blocks::getNowVoltage(BlockSource&,BlockPos const&)
{
	return 0;
}
Blocks::Blocks(std::string const&name,int id,Material const&m):Block(name,id,m)
{
	mICBlocks[id]=true;
}
}
