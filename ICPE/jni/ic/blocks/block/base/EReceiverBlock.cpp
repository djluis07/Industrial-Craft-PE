#include "EReceiverBlock.h"

EReceiverBlock::EReceiverBlock(const std::string&name, int id, const Material&m):EAbleBlock(name,id,m)
{
	
}
bool EReceiverBlock::isElectronicRecevier()const
{
	return true;
}
