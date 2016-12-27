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
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mRubberWood]->setTextureItem("icpe_rubber_wood_bottom","icpe_rubber_wood_bottom","icpe_rubber_wood");
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
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFurnace]=new MCPEBlockGraphics("dirt");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFurnace]->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_1","icpe_ironFurnace_2","icpe_ironFurnace_3","icpe_ironFurnace_4");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFurnace]->setSoundType(BlockSoundType::STONE);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mCable]=new MCPEBlockGraphics("portal");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mCable]->setTextureItem("icpe_cable");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mCable]->setSoundType(BlockSoundType::STONE);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFence]=new MCPEBlockGraphics("portal");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFence]->setTextureItem("icpe_fence_iron");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFence]->setBlockShape(BlockShape::FENCE);
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mIronFence]->setSoundType(BlockSoundType::STONE);
	
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mMetal]=new MCPEBlockGraphics("dirt");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mMetal]->setTextureItem("icpe_metal_block");
	MCPEBlockGraphics::mBlocks[IC::Blocks::ID::mMetal]->setSoundType(BlockSoundType::STONE);
}
}
