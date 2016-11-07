#include "ITNTBlock.h"

#include "ic/blocks/Blocks.h"

ITNTBlock::ITNTBlock():TntBlock("ic.itnt",IC::Blocks::ID::mITNT)
{
	setCategory(CreativeItemCategory::TOOLS);
	//setSoundType(BlockSoundType::SOUND_DEFAULT);
	
	((FireBlock*)mFire)->setFlammable(BlockID(IC::Blocks::ID::mITNT),65,25);
}
