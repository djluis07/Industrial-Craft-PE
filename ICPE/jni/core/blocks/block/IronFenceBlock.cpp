#include "IronFenceBlock.h"

#include "blocks/Blocks.h"

IronFenceBlock::IronFenceBlock():FenceBlock("ic.ironfence",IC::Blocks::ID::mIronFence,Material::getMaterial(MaterialType::METAL))
{
	init();
	setCategory(CreativeItemCategory::DECORATIONS);
	setSolid(false);
	//setSoundType(BlockSoundType::SOUND_DEFAULT);
	setDestroyTime(3);
	setExplodeable(15);
}
