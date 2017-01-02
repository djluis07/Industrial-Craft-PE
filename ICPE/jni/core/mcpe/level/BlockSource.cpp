#include "BlockSource.h"

#include "ICPE.h"
#include "blocks/blockentity/ICBlockEntityManager.h"

#include "../util/BlockPos.h"

ICBlockEntity* BlockSource::getICBlockEntity(int x,int y,int z)
{
	return getICBlockEntity({x,y,z});
}
ICBlockEntity* BlockSource::getICBlockEntity(BlockPos const&pos)
{
	return ICPE::mBlockEntityManager.getBlockEntity(*this,pos);
}
