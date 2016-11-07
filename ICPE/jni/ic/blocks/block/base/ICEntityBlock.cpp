#include "ICEntityBlock.h"

#include "ic/blocks/blockentity/ICBlockEntity.h"
#include "ic/blocks/blockentity/ICBlockEntityManager.h"
#include "ic/client/ICClient.h"

ICEntityBlock::ICEntityBlock(std::string const&name,int id, const Material&m):IC::Blocks(name,id,m)
{
	
}
void ICEntityBlock::onPlace(BlockSource&s, BlockPos const&pos)
{
	ICBlockEntity* newE = newICBlockEntity(BlockPos(pos.x,pos.y,pos.z),s);
	newE->create();
	newE->load();
}
void ICEntityBlock::onRemove(BlockSource&, BlockPos const&pos)
{
	if(ICClient::mInstance.getBlockEntityManager().getBlockEntity(pos))
		ICClient::mInstance.getBlockEntityManager().getBlockEntity(pos)->onRemove();
	ICClient::mInstance.getBlockEntityManager().removeBlockEntity(pos);
}
void ICEntityBlock::onLoaded(BlockSource&s, BlockPos const&pos)
{
	ICBlockEntity* newE = newICBlockEntity(BlockPos(pos.x,pos.y,pos.z),s);
	newE->load();
}
void ICEntityBlock::onMove(BlockSource&, BlockPos const&pos, BlockPos const&pos2)
{
	if(ICClient::mInstance.getBlockEntityManager().getBlockEntity(pos))
		ICClient::mInstance.getBlockEntityManager().getBlockEntity(pos)->moveTo(pos2);
	else if(ICClient::mInstance.getBlockEntityManager().getBlockEntity(pos2))
		ICClient::mInstance.getBlockEntityManager().getBlockEntity(pos2)->moveTo(pos);
}
