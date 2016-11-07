#include "EAbleBlock.h"

EAbleBlock::EAbleBlock(const std::string&name, int id, const Material&m):IC::Blocks(name,id,m)
{
	
}
bool EAbleBlock::isElectronicBlock()const
{
	return true;
}
