#include "PlateItem.h"

#include "mcpe/client/resources/I18n.h"

PlateItem::PlateItem():IC::Items("ic.plate.tin",IC::Items::ID::mPlate-0x100)
{
	setCategory(CreativeItemCategory::ITEMS);
	setStackedByData(true);
	
	plateTextures[0]=getTextureUVCoordinateSet("pl_bronze",0);
	plateTextures[1]=getTextureUVCoordinateSet("pl_copper",0);
	plateTextures[2]=getTextureUVCoordinateSet("pl_gold",0);
	plateTextures[3]=getTextureUVCoordinateSet("pl_iron",0);
	plateTextures[4]=getTextureUVCoordinateSet("pl_lapis",0);
	plateTextures[5]=getTextureUVCoordinateSet("pl_lead",0);
	plateTextures[6]=getTextureUVCoordinateSet("pl_obsidian",0);
	plateTextures[7]=getTextureUVCoordinateSet("pl_steel",0);
	plateTextures[8]=getTextureUVCoordinateSet("pl_tin",0);
	plateTextures[9]=getTextureUVCoordinateSet("pl_bronze",0);
	plateTextures[10]=getTextureUVCoordinateSet("dense_copper",0);
	plateTextures[11]=getTextureUVCoordinateSet("dense_gold",0);
	plateTextures[12]=getTextureUVCoordinateSet("dense_iron",0);
	plateTextures[13]=getTextureUVCoordinateSet("dense_lapis",0);
	plateTextures[14]=getTextureUVCoordinateSet("dense_lead",0);
	plateTextures[15]=getTextureUVCoordinateSet("dense_obsidian",0);
	plateTextures[16]=getTextureUVCoordinateSet("dense_steel",0);
	plateTextures[17]=getTextureUVCoordinateSet("dense_tin",0);
}
const std::string PlateItem::buildDescriptionName(const ItemInstance&i) const
{
	switch(i.aux)
	{
	case 0:
	default:
		return I18n::get("ic.plate.bronze");
	case 1:
		return I18n::get("ic.plate.copper");
	case 2:
		return I18n::get("ic.plate.gold");
	case 3:
		return I18n::get("ic.plate.iron");
	case 4:
		return I18n::get("ic.plate.lapis");
	case 5:
		return I18n::get("ic.plate.lead");
	case 6:
		return I18n::get("ic.plate.obsidian");
	case 7:
		return I18n::get("ic.plate.steel");
	case 8:
		return I18n::get("ic.plate.tin");
	case 9:
		return I18n::get("ic.plate.dense.bronze");
	case 10:
		return I18n::get("ic.plate.dense.copper");
	case 11:
		return I18n::get("ic.plate.dense.gold");
	case 12:
		return I18n::get("ic.plate.dense.iron");
	case 13:
		return I18n::get("ic.plate.dense.lapis");
	case 14:
		return I18n::get("ic.plate.dense.lead");
	case 15:
		return I18n::get("ic.plate.dense.obsidian");
	case 16:
		return I18n::get("ic.plate.dense.steel");
	case 17:
		return I18n::get("ic.plate.dense.tin");
	}
}
const TextureUVCoordinateSet& PlateItem::getIcon(int aux, int, bool) const
{
	return plateTextures[aux>=(sizeof(plateTextures)/sizeof(TextureUVCoordinateSet))?0:aux];
}
