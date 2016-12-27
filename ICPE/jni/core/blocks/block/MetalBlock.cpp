#include "MetalBlock.h"

MetalBlock::MetalBlock():IC::Blocks("ic.metal",ID::mMetal,Material::getMaterial(MaterialType::METAL))
{
	init();
	setCategory(CreativeItemCategory::DECORATIONS);
	setSolid(true);
	setDestroyTime(3);
	setExplodeable(15);
}
bool MetalBlock::isAnyAuxValueInRecipe()const
{
	return false;
}
