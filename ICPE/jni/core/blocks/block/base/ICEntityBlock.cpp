#include "ICEntityBlock.h"

#include "blocks/blockentity/ICBlockEntity.h"
#include "blocks/blockentity/ICBlockEntityManager.h"

#include "ICPE.h"

ICEntityBlock::ICEntityBlock(std::string const&name,int id, const Material&m):IC::Blocks(name,id,m)
{
	
}
void ICEntityBlock::onPlace(BlockSource&s, BlockPos const&pos)const
{
	ICBlockEntity* newE = newICBlockEntity(BlockPos(pos.x,pos.y,pos.z),s);
	newE->create();
	newE->load();
}
void ICEntityBlock::onRemove(BlockSource&, BlockPos const&pos)const
{
	if(ICPE::mBlockEntityManager.getBlockEntity(pos))
		ICPE::mBlockEntityManager.getBlockEntity(pos)->onRemove();
	ICPE::mBlockEntityManager.removeBlockEntity(pos);
}
void ICEntityBlock::onLoaded(BlockSource&s, BlockPos const&pos)const
{
	ICBlockEntity* newE = newICBlockEntity(BlockPos(pos.x,pos.y,pos.z),s);
	newE->load();
}
void ICEntityBlock::onMove(BlockSource&, BlockPos const&pos, BlockPos const&pos2)const
{
	if(ICPE::mBlockEntityManager.getBlockEntity(pos))
		ICPE::mBlockEntityManager.getBlockEntity(pos)->moveTo(pos2);
	else if(ICPE::mBlockEntityManager.getBlockEntity(pos2))
		ICPE::mBlockEntityManager.getBlockEntity(pos2)->moveTo(pos);
}
