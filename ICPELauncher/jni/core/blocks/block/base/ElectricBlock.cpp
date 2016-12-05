#include "ElectricBlock.h"

ElectricBlock::ElectricBlock(const std::string&name, int id, const Material&m):IC::Blocks(name,id,m)
{
	
}
bool ElectricBlock::isElectricBlock()const
{
	return true;
}
