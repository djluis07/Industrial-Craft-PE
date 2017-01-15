#include "ICOreBlock.h"

#include "mcpe/client/resources/I18n.h"
#include "mcpe/item/ItemInstance.h"

ICOreBlock::ICOreBlock():OreBlock("ic.ore",IC::Blocks::ID::mOre)
{
	init();
	setSolid(true);
	setDestroyTime(3);
	setExplodeable(15);
	setCategory(CreativeItemCategory::BLOCKS);
}
std::string ICOreBlock::buildDescriptionName(unsigned char aux) const
{
	switch(aux)
	{
	case 0:
	default:
		return I18n::get("tile.ic.ore.tin.name");
	case 1:
		return I18n::get("tile.ic.ore.copper.name");
	case 2:
		return I18n::get("tile.ic.ore.lead.name");
	case 3:
		return I18n::get("tile.ic.ore.uranium.name");
	case 4:
		return I18n::get("tile.ic.basalt.name");
	}
}
int ICOreBlock::getSpawnResourcesAuxValue(unsigned char aux)const
{
	return aux;
}
int ICOreBlock::getPlacementDataValue(Entity&, BlockPos const&, signed char, Vec3 const&, int aux)const
{
	return aux;
}
