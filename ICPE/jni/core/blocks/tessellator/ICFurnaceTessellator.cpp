#include "ICFurnaceTessellator.h"

#include "blocks/blockentity/IronFurnaceBlockEntity.h"
#include "blocks/texture/TextureManager.h"
#include "mcpe/level/BlockSource.h"

bool ICFurnaceTessellator::tessellate(Block const&b,BlockPos const&pos,unsigned char aux,bool wtf)
{
	BlockGraphics* mDefaultBlock=BlockGraphics::mBlocks[b.blockId];
	if(aux<4)
	{
		IronFurnaceBlockEntity* ironFurnace=(IronFurnaceBlockEntity*)blockSource->getICBlockEntity(pos);
		if(ironFurnace->isLit())
		{
			switch(aux)
			{
			case 0:
				BlockGraphics::mBlocks[b.blockId]=TextureManager::ironFurnaceLit0;
			break;
			case 1:
				BlockGraphics::mBlocks[b.blockId]=TextureManager::ironFurnaceLit1;
			break;
			case 2:
				BlockGraphics::mBlocks[b.blockId]=TextureManager::ironFurnaceLit2;
			break;
			case 3:
				BlockGraphics::mBlocks[b.blockId]=TextureManager::ironFurnaceLit3;
			break;
			}
		}
		else
		{
			switch(aux)
			{
			case 0:
				BlockGraphics::mBlocks[b.blockId]=TextureManager::ironFurnaceUnLit0;
			break;
			case 1:
				BlockGraphics::mBlocks[b.blockId]=TextureManager::ironFurnaceUnLit1;
			break;
			case 2:
				BlockGraphics::mBlocks[b.blockId]=TextureManager::ironFurnaceUnLit2;
			break;
			case 3:
				BlockGraphics::mBlocks[b.blockId]=TextureManager::ironFurnaceUnLit3;
			break;
			}
		}
	}
	
	_setShapeAndTessellate(Vec3(0,0,0),Vec3(1,1,1),b,pos,0);
	BlockGraphics::mBlocks[b.blockId]=mDefaultBlock;
	return true;
}
