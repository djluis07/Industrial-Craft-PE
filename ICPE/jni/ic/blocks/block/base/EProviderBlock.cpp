#include "EProviderBlock.h"

EProviderBlock::EProviderBlock(const std::string&name, int id, const Material&m):EAbleBlock(name,id,m)
{
	
}
bool EProviderBlock::isElectronicProvider()const
{
	return true;
}
