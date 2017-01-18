#include "RubberWoodTessellator.h"

#include "blocks/texture/TextureManager.h"
#include "mcpe/level/BlockSource.h"

bool RubberWoodTessellator::tessellate(Block const&b,BlockPos const&pos,unsigned char aux,bool wtf)
{
	BlockGraphics* mDefaultBlock=BlockGraphics::mBlocks[b.blockId];
	if(aux>10)aux=0;
	BlockGraphics::mBlocks[b.blockId]=TextureManager::rubberWood[aux];
	_setShapeAndTessellate(Vec3(0,0,0),Vec3(1,1,1),b,pos,0);
	BlockGraphics::mBlocks[b.blockId]=mDefaultBlock;
	return true;
}
