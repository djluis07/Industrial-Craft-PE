#include "TextureManager.h"

#include "mcpe/block/BlockGraphics.h"

BlockGraphics* TextureManager::ironFurnaceUnLit[4];
BlockGraphics* TextureManager::ironFurnaceLit[4];
BlockGraphics* TextureManager::rubberWood[11];

void TextureManager::init()
{
	ironFurnaceUnLit[0]=new BlockGraphics("dirt");
	ironFurnaceUnLit[1]=new BlockGraphics("dirt");
	ironFurnaceUnLit[2]=new BlockGraphics("dirt");
	ironFurnaceUnLit[3]=new BlockGraphics("dirt");
	ironFurnaceLit[0]=new BlockGraphics("dirt");
	ironFurnaceLit[1]=new BlockGraphics("dirt");
	ironFurnaceLit[2]=new BlockGraphics("dirt");
	ironFurnaceLit[3]=new BlockGraphics("dirt");
	rubberWood[0]=new BlockGraphics("dirt");
	rubberWood[1]=new BlockGraphics("dirt");
	rubberWood[2]=new BlockGraphics("dirt");
	rubberWood[3]=new BlockGraphics("dirt");
	rubberWood[4]=new BlockGraphics("dirt");
	rubberWood[5]=new BlockGraphics("dirt");
	rubberWood[6]=new BlockGraphics("dirt");
	rubberWood[7]=new BlockGraphics("dirt");
	rubberWood[8]=new BlockGraphics("dirt");
	rubberWood[9]=new BlockGraphics("dirt");
	rubberWood[10]=new BlockGraphics("dirt");
	
	ironFurnaceUnLit[0]->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_unlit","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_side");
	ironFurnaceUnLit[1]->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_side","icpe_ironFurnace_unlit","icpe_ironFurnace_side","icpe_ironFurnace_side");
	ironFurnaceUnLit[2]->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_unlit","icpe_ironFurnace_side");
	ironFurnaceUnLit[3]->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_unlit");
	ironFurnaceLit[0]->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_lit","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_side");
	ironFurnaceLit[1]->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_side","icpe_ironFurnace_lit","icpe_ironFurnace_side","icpe_ironFurnace_side");
	ironFurnaceLit[2]->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_lit","icpe_ironFurnace_side");
	ironFurnaceLit[3]->setTextureItem("icpe_ironFurnace_top","icpe_ironFurnace_bottom","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_side","icpe_ironFurnace_lit");
	rubberWood[0]->setTextureItem("icpe_rubberwood_top","icpe_rubberwood_top","icpe_rubberwood_side","icpe_rubberwood_side","icpe_rubberwood_side","icpe_rubberwood_side");
	rubberWood[1]->setTextureItem("icpe_rubberwood_side","icpe_rubberwood_side","icpe_rubberwood_top","icpe_rubberwood_top","icpe_rubberwood_sidefallen","icpe_rubberwood_sidefallen");
	rubberWood[2]->setTextureItem("icpe_rubberwood_sidefallen","icpe_rubberwood_sidefallen","icpe_rubberwood_sidefallen","icpe_rubberwood_sidefallen","icpe_rubberwood_top","icpe_rubberwood_top");
	rubberWood[3]->setTextureItem("icpe_rubberwood_top","icpe_rubberwood_top","icpe_rubberwood_dry","icpe_rubberwood_side","icpe_rubberwood_side","icpe_rubberwood_side");
	rubberWood[4]->setTextureItem("icpe_rubberwood_top","icpe_rubberwood_top","icpe_rubberwood_side","icpe_rubberwood_dry","icpe_rubberwood_side","icpe_rubberwood_side");
	rubberWood[5]->setTextureItem("icpe_rubberwood_top","icpe_rubberwood_top","icpe_rubberwood_side","icpe_rubberwood_side","icpe_rubberwood_dry","icpe_rubberwood_side");
	rubberWood[6]->setTextureItem("icpe_rubberwood_top","icpe_rubberwood_top","icpe_rubberwood_side","icpe_rubberwood_side","icpe_rubberwood_side","icpe_rubberwood_side");
	rubberWood[7]->setTextureItem("icpe_rubberwood_top","icpe_rubberwood_top","icpe_rubberwood_wet","icpe_rubberwood_side","icpe_rubberwood_side","icpe_rubberwood_side");
	rubberWood[8]->setTextureItem("icpe_rubberwood_top","icpe_rubberwood_top","icpe_rubberwood_side","icpe_rubberwood_wet","icpe_rubberwood_side","icpe_rubberwood_side");
	rubberWood[9]->setTextureItem("icpe_rubberwood_top","icpe_rubberwood_top","icpe_rubberwood_side","icpe_rubberwood_side","icpe_rubberwood_wet","icpe_rubberwood_side");
	rubberWood[10]->setTextureItem("icpe_rubberwood_top","icpe_rubberwood_top","icpe_rubberwood_side","icpe_rubberwood_side","icpe_rubberwood_side","icpe_rubberwood_wet");
}
void TextureManager::teardown()
{
	delete []ironFurnaceUnLit;
	delete []ironFurnaceLit;
	delete []rubberWood;
}
