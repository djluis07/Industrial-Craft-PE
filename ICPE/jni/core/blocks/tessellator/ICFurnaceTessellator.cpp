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
			BlockGraphics::mBlocks[b.blockId]=TextureManager::ironFurnaceLit[aux];
		else
			BlockGraphics::mBlocks[b.blockId]=TextureManager::ironFurnaceUnLit[aux];
	}
	_setShapeAndTessellate(Vec3(0,0,0),Vec3(1,1,1),b,pos,0);
	BlockGraphics::mBlocks[b.blockId]=mDefaultBlock;
	return true;
}
