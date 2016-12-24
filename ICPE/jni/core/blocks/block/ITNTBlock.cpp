#include "ITNTBlock.h"

#include "blocks/Blocks.h"

#include "mcpe/block/blocks/FireBlock.h"

ITNTBlock::ITNTBlock():TntBlock("ic.itnt",IC::Blocks::ID::mITNT)
{
	setCategory(CreativeItemCategory::TOOLS);
	
	((FireBlock*)mFire)->setFlammable(BlockID(IC::Blocks::ID::mITNT),65,25);
}
