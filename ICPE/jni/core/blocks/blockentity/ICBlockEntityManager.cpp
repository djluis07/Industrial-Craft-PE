#include "ICBlockEntityManager.h"

#include "ICBlockEntity.h"

ICBlockEntityManager::ICBlockEntityManager(std::string const&path,BlockSource&s)
{
	this->s=&s;
	this->path=path;
}
std::unique_ptr<ICBlockEntity>& ICBlockEntityManager::getBlockEntity(BlockPos const&pos)
{
	
}
void ICBlockEntityManager::removeBlockEntity(BlockPos const&pos)
{
	
}
int ICBlockEntityManager::getBlockEntityPos(BlockPos const&pos)
{
	
}
void ICBlockEntityManager::addNew(std::unique_ptr<ICBlockEntity>)
{
	
}
void ICBlockEntityManager::tick(Level&l)
{
	
}
void ICBlockEntityManager::save()
{
	
}
void ICBlockEntityManager::load()
{
	
}
