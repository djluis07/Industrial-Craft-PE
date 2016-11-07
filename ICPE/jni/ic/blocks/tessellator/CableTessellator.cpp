#include "CableTessellator.h"

#include "ic/blocks/Blocks.h"

bool CableTessellator::tessellate(Block&block,BlockPos const&pos,unsigned char aux,bool wtf,bool (*tessellate)(BlockTessellator*,Block&,BlockPos const&,uchar,bool))
{
	float defaultDistance=blockSource->getData(pos)==12?0.375:0.3125;
	
	if(isElectronicBlockAt({pos.x,pos.y+1,pos.z}))
	{
		block.setVisualShape({defaultDistance,1-defaultDistance,defaultDistance,1-defaultDistance,1,1-defaultDistance});
		tessellate(this,block,pos,aux,wtf);
	}
	if(isElectronicBlockAt({pos.x,pos.y-1,pos.z}))
	{
		block.setVisualShape({defaultDistance,0,defaultDistance,1-defaultDistance,defaultDistance,1-defaultDistance});
		tessellate(this,block,pos,aux,wtf);
	}
	if(isElectronicBlockAt({pos.x,pos.y,pos.z+1}))
	{
		block.setVisualShape({defaultDistance,defaultDistance,1-defaultDistance,1-defaultDistance,1-defaultDistance,1});
		tessellate(this,block,pos,aux,wtf);
	}
	if(isElectronicBlockAt({pos.x,pos.y,pos.z-1}))
	{
		block.setVisualShape({defaultDistance,defaultDistance,0,1-defaultDistance,1-defaultDistance,defaultDistance});
		tessellate(this,block,pos,aux,wtf);
	}
	if(isElectronicBlockAt({pos.x+1,pos.y,pos.z}))
	{
		block.setVisualShape({1-defaultDistance,defaultDistance,defaultDistance,1,1-defaultDistance,1-defaultDistance});
		tessellate(this,block,pos,aux,wtf);
	}
	if(isElectronicBlockAt({pos.x-1,pos.y,pos.z}))
	{
		block.setVisualShape({0,defaultDistance,defaultDistance,defaultDistance,1-defaultDistance,1-defaultDistance});
		tessellate(this,block,pos,aux,wtf);
	}
	
	block.setVisualShape({defaultDistance,defaultDistance,defaultDistance,1-defaultDistance,1-defaultDistance,1-defaultDistance});
	tessellate(this,block,pos,aux,wtf);
	block.setVisualShape({0.25,0.25,0.25,0.75,0.75,0.75});
	return true;
}
bool CableTessellator::isElectronicBlockAt(BlockPos const&pos)
{
	if(IC::Blocks::mICBlocks[blockSource->getBlockID(pos).id])
		return ((IC::Blocks*)blockSource->getBlock(pos))->isElectronicBlock();
	return false;
}
