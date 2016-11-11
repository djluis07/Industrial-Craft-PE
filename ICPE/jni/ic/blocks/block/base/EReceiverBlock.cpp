#include "EReceiverBlock.h"

EReceiverBlock::EReceiverBlock(const std::string&name, int id, const Material&m):ElectricBlock(name,id,m)
{
	
}
bool EReceiverBlock::isElectricRecevier()const
{
	return true;
}
