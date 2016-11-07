#include "ESpreadBlock.h"

ESpreadBlock::ESpreadBlock(const std::string&name, int id, const Material&m):EAbleBlock(name,id,m)
{
	
}
bool ESpreadBlock::isElectronicConductor()const
{
	return true;
}
