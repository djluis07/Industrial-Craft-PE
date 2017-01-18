#include "TextureManager.h"

#include "mcpe/block/BlockGraphics.h"

BlockGraphics* TextureManager::ironFurnaceUnLit0;
BlockGraphics* TextureManager::ironFurnaceUnLit1;
BlockGraphics* TextureManager::ironFurnaceUnLit2;
BlockGraphics* TextureManager::ironFurnaceUnLit3;
BlockGraphics* TextureManager::ironFurnaceLit0;
BlockGraphics* TextureManager::ironFurnaceLit1;
BlockGraphics* TextureManager::ironFurnaceLit2;
BlockGraphics* TextureManager::ironFurnaceLit3;

void TextureManager::init()
{
	ironFurnaceUnLit0=new BlockGraphics("dirt");
	ironFurnaceUnLit1=new BlockGraphics("dirt");
	ironFurnaceUnLit2=new BlockGraphics("dirt");
	ironFurnaceUnLit3=new BlockGraphics("dirt");
	ironFurnaceLit0=new BlockGraphics("dirt");
	ironFurnaceLit1=new BlockGraphics("dirt");
	ironFurnaceLit2=new BlockGraphics("dirt");
	ironFurnaceLit3=new BlockGraphics("dirt");
	
	ironFurnaceUnLit0->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_unlit","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_side");
	ironFurnaceUnLit1->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_side","icpe_ironFurnace_unlit","icpe_ironFurnace_side","icpe_ironFurnace_side");
	ironFurnaceUnLit2->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_unlit","icpe_ironFurnace_side");
	ironFurnaceUnLit3->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_unlit");
	ironFurnaceLit0->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_lit","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_side");
	ironFurnaceLit1->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_side","icpe_ironFurnace_lit","icpe_ironFurnace_side","icpe_ironFurnace_side");
	ironFurnaceLit2->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_lit","icpe_ironFurnace_side");
	ironFurnaceLit3->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_lit");
}
void TextureManager::teardown()
{
	delete ironFurnaceUnLit0;
	delete ironFurnaceUnLit1;
	delete ironFurnaceUnLit2;
	delete ironFurnaceUnLit3;
	delete ironFurnaceLit0;
	delete ironFurnaceLit1;
	delete ironFurnaceLit2;
	delete ironFurnaceLit3;
}
