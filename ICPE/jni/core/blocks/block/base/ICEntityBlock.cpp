#include "ICEntityBlock.h"

#include "ICPE.h"
#include "UTIL/LOG.H"

#include "blocks/blockentity/ICBlockEntityManager.h"

ICEntityBlock::ICEntityBlock(std::string const&name,int id, const Material&m):IC::Blocks(name,id,m)
{
	
}
bool ICEntityBlock::isICEntityBlock()const
{
	return true;
}
void ICEntityBlock::onLoaded(BlockSource&s, BlockPos const&pos) const
{
	ICPE::mBlockEntityManager.load(s,pos);
	
}
void ICEntityBlock::onPlace(BlockSource&s, BlockPos const&pos) const
{
	LOG_P("ON PLACE");
	ICPE::mBlockEntityManager.addNew(getBlockEntity(s,pos));
}
void ICEntityBlock::onRemove(BlockSource&, BlockPos const&pos) const
{
	LOG_P("ON REMOVE");
	ICPE::mBlockEntityManager.removeBlockEntity(pos);
}
void ICEntityBlock::onMove(BlockSource&s, BlockPos const&pos, BlockPos const&pos2) const
{
	LOG_P("ON_MOVE");
	ICPE::mBlockEntityManager.removeBlockEntity(pos);
	ICPE::mBlockEntityManager.addNew(getBlockEntity(s,pos2));
}
