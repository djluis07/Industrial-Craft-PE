#include "ICBlockEntityManager.h"

#include "ICBlockEntity.h"

ICBlockEntityManager::ICBlockEntityManager()
{
	
}
ICBlockEntityManager::~ICBlockEntityManager()
{
	icBlockEntityList.clear();
}
ICBlockEntity *ICBlockEntityManager::getBlockEntity(BlockPos const&pos)
{
	return getBlockEntityPos(pos)>=0?icBlockEntityList[getBlockEntityPos(pos)]:0;
}
void ICBlockEntityManager::removeBlockEntity(BlockPos const&pos)
{
	if(getBlockEntity(pos))
		getBlockEntity(pos)->remove();
	if(getBlockEntityPos(pos)>=0)
		icBlockEntityList[getBlockEntityPos(pos)]=0;
}
int ICBlockEntityManager::getBlockEntityPos(BlockPos const&pos)
{
	for(unsigned int poss=0;poss<icBlockEntityList.size();++poss)
		if(icBlockEntityList[poss]&&icBlockEntityList[poss]->position.x==pos.x&&icBlockEntityList[poss]->position.y==pos.y&&icBlockEntityList[poss]->position.z==pos.z)
			return poss;
	return -1;
}
void ICBlockEntityManager::addNew(ICBlockEntity*icb)
{
	for(unsigned int poss=0;poss<icBlockEntityList.size();++poss)
		if(!icBlockEntityList[poss])
		{
			icBlockEntityList[poss]=icb;
			return;
		}
	icBlockEntityList.push_back(icb);
}
void ICBlockEntityManager::tick(Level&l)
{
	for(unsigned int poss=0;poss<icBlockEntityList.size();++poss)
		if(icBlockEntityList[poss])
			icBlockEntityList[poss]->tick(l);
}
void ICBlockEntityManager::save()
{
	for(unsigned int poss=0;poss<icBlockEntityList.size();++poss)
		if(icBlockEntityList[poss])
			icBlockEntityList[poss]->save();
}
