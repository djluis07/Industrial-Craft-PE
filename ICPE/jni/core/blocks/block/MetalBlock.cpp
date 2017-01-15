#include "MetalBlock.h"

#include "mcpe/client/resources/I18n.h"

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
std::string MetalBlock::buildDescriptionName(unsigned char aux) const
{
	switch(aux)
	{
	case 0:
	default:
		return I18n::get("tile.ic.metal.tin.name");
	case 1:
		return I18n::get("tile.ic.metal.steel.name");
	case 2:
		return I18n::get("tile.ic.metal.copper.name");
	case 3:
		return I18n::get("tile.ic.metal.lead.name");
	case 4:
		return I18n::get("tile.ic.machine.name");
	case 5:
		return I18n::get("tile.ic.advanced_machine.name");
	}
}
