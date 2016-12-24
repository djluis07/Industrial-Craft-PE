#include "MetalBlock.h"

MetalBlock::MetalBlock(std::string const&name,int id):IC::Blocks(name,id,Material::getMaterial(MaterialType::METAL))
{
	init();
	setCategory(CreativeItemCategory::DECORATIONS);
	setSolid(true);
	setDestroyTime(3);
	setExplodeable(15);
}
