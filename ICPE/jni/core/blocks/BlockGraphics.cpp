#include "BlockGraphics.h"

#include "mcpe/block/BlockGraphics.h"

#include "ICPE.h"
#include "Blocks.h"

namespace IC
{
void BlockGraphics::initBlockGraphics()
{
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mOre]=new MCPEBlockGraphics("diamond_ore");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mOre]->setTextureItem("icore");
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberSapling]=new MCPEBlockGraphics("sapling");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberSapling]->setTextureItem("rubber_sapling");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberSapling]->setBlockShape(BlockShape::CROSS);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mITNT]=new MCPEBlockGraphics("tnt");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mITNT]->setTextureItem("itnt_top","itnt_bottom","itnt_sides");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mITNT]->setTextureIsotropic(1);
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mITNT]->setTextureIsotropic(0);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberWood]=new MCPEBlockGraphics("dirt");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberWood]->setTextureItem("rubber_wood_bottom","rubber_wood_bottom","rubber_wood");
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mResin]=new MCPEBlockGraphics("portal");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mResin]->setTextureItem("resin_sheet");
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberLeaves]=new MCPEBlockGraphics("portal");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberLeaves]->setTextureItem("rubber_leaves_carried");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberLeaves]->setCarriedTextureItem("rubber_leaves_carried");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberLeaves]->setTextureIsotropic(1);
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberLeaves]->setTextureIsotropic(0);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFurnace]=new MCPEBlockGraphics("dirt");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFurnace]->setTextureItem("ironFurnace_top","ironFurnace_bottom","ironFurnace_1","ironFurnace_2","ironFurnace_3","ironFurnace_4");
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mCable]=new MCPEBlockGraphics("portal");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mCable]->setTextureItem("cable");
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFence]=new MCPEBlockGraphics("portal");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFence]->setTextureItem("fence_iron");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFence]->setBlockShape(BlockShape::FENCE);
}
}
