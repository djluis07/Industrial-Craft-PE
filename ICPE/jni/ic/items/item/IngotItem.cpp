#include "IngotItem.h"

#include "mcpe/client/resources/I18n.h"

IngotItem::IngotItem():IC::Items("ic.ingot.tin",IC::Items::ID::mIngot-0x100)
{
	setCategory(CreativeItemCategory::ITEMS);
	setStackedByData(true);
	
	ingotTextures[0]=getTextureUVCoordinateSet("tin",0);
	ingotTextures[1]=getTextureUVCoordinateSet("steel",0);
	ingotTextures[2]=getTextureUVCoordinateSet("copper",0);
	ingotTextures[3]=getTextureUVCoordinateSet("iclead",0);
	ingotTextures[4]=getTextureUVCoordinateSet("bronze",0);
	ingotTextures[5]=getTextureUVCoordinateSet("alloy",0);
}
const std::string IngotItem::buildDescriptionName(const ItemInstance&i) const
{
	switch(i.aux)
	{
	case 0:
	default:
		return I18n::get("ic.ingot.tin");
	case 1:
		return I18n::get("ic.ingot.steel");
	case 2:
		return I18n::get("ic.ingot.copper");
	case 3:
		return I18n::get("ic.ingot.lead");
	case 4:
		return I18n::get("ic.ingot.bronze");
	case 5:
		return I18n::get("ic.ingot.alloy");
	}
}
const TextureUVCoordinateSet& IngotItem::getIcon(int aux, int, bool) const
{
	return ingotTextures[aux>=(sizeof(ingotTextures)/sizeof(TextureUVCoordinateSet))?0:aux];
}
