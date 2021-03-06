#include "BlockGraphics.h"

#include "mcpe/block/BlockGraphics.h"

#include "ICPE.h"
#include "Blocks.h"

namespace IC
{
void BlockGraphics::initBlockGraphics()
{
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mOre]=new MCPEBlockGraphics("diamond_ore");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mOre]->setTextureItem("icpe_icore");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mOre]->setSoundType(BlockSoundType::STONE);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberSapling]=new MCPEBlockGraphics("sapling");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberSapling]->setTextureItem("icpe_rubber_sapling");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberSapling]->setBlockShape(BlockShape::CROSS);
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberSapling]->setSoundType(BlockSoundType::GRASS);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mITNT]=new MCPEBlockGraphics("tnt");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mITNT]->setTextureItem("icpe_itnt_top","icpe_itnt_bottom","icpe_itnt_sides");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mITNT]->setTextureIsotropic(1);
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mITNT]->setTextureIsotropic(0);
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mITNT]->setSoundType(BlockSoundType::GRASS);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberWood]=new MCPEBlockGraphics("dirt");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberWood]->setTextureItem("icpe_rubberwood_top","icpe_rubberwood_top","icpe_rubberwood_side","icpe_rubberwood_side","icpe_rubberwood_side","icpe_rubberwood_side");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberWood]->setSoundType(BlockSoundType::WOOD);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mResin]=new MCPEBlockGraphics("portal");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mResin]->setTextureItem("icpe_resin_sheet");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mResin]->setSoundType(BlockSoundType::SLIME);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberLeaves]=new MCPEBlockGraphics("portal");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberLeaves]->setTextureItem("icpe_rubber_leaves");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberLeaves]->setCarriedTextureItem("icpe_rubber_leaves");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberLeaves]->setTextureIsotropic(1);
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberLeaves]->setTextureIsotropic(0);
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberLeaves]->setSoundType(BlockSoundType::GRASS);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mFurnace]=new MCPEBlockGraphics("dirt");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mFurnace]->setTextureItem("icpe_icFurnace_carried_top","icpe_icFurnace_carried_top","icpe_icFurnace_carried_side","icpe_icFurnace_carried_front","icpe_icFurnace_carried_side","icpe_icFurnace_carried_side");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mFurnace]->setSoundType(BlockSoundType::STONE);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mCable]=new MCPEBlockGraphics("portal");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mCable]->setTextureItem("icpe_cable");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mCable]->setSoundType(BlockSoundType::STONE);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFence]=new MCPEBlockGraphics("portal");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFence]->setTextureItem("icpe_fence_iron");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFence]->setBlockShape(BlockShape::FENCE);
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFence]->setSoundType(BlockSoundType::STONE);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mMetal]=new MCPEBlockGraphics("dirt");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mMetal]->setTextureItem("icpe_metal_block","icpe_metal_block","icpe_metal_block_side");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mMetal]->setSoundType(BlockSoundType::STONE);
}
}
