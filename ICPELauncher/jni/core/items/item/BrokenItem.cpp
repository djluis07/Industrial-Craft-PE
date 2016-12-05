#include "BrokenItem.h"

#include "mcpe/client/resources/I18n.h"

#include "items/Items.h"

BrokenItem::BrokenItem():IC::Items("ic.crushed.copper",IC::Items::ID::mBroken-0x100)
{
	setCategory(CreativeItemCategory::ITEMS);
	setStackedByData(true);
	
	brokenTextures[0]=getTextureUVCoordinateSet("cr_copper",0);
	brokenTextures[1]=getTextureUVCoordinateSet("cr_gold",0);
	brokenTextures[2]=getTextureUVCoordinateSet("cr_iron",0);
	brokenTextures[3]=getTextureUVCoordinateSet("cr_lead",0);
	brokenTextures[4]=getTextureUVCoordinateSet("cr_silver",0);
	brokenTextures[5]=getTextureUVCoordinateSet("cr_tin",0);
	brokenTextures[6]=getTextureUVCoordinateSet("cr_uranium",0);
	brokenTextures[7]=getTextureUVCoordinateSet("pu_copper",0);
	brokenTextures[8]=getTextureUVCoordinateSet("pu_gold",0);
	brokenTextures[9]=getTextureUVCoordinateSet("pu_iron",0);
	brokenTextures[10]=getTextureUVCoordinateSet("pu_lead",0);
	brokenTextures[11]=getTextureUVCoordinateSet("pu_silver",0);
	brokenTextures[12]=getTextureUVCoordinateSet("pu_tin",0);
	brokenTextures[13]=getTextureUVCoordinateSet("pu_uranium",0);
	brokenTextures[14]=getTextureUVCoordinateSet("ca_bronze",0);
	brokenTextures[15]=getTextureUVCoordinateSet("ca_copper",0);
	brokenTextures[16]=getTextureUVCoordinateSet("ca_gold",0);
	brokenTextures[17]=getTextureUVCoordinateSet("ca_iron",0);
	brokenTextures[18]=getTextureUVCoordinateSet("ca_lead",0);
	brokenTextures[19]=getTextureUVCoordinateSet("ca_steel",0);
	brokenTextures[20]=getTextureUVCoordinateSet("ca_tin",0);
}
std::string BrokenItem::buildDescriptionName(const ItemInstance&i) const
{
	switch(i.aux)
	{
	case 0:
	default:
		return I18n::get("ic.crushed.copper");
	case 1:
		return I18n::get("ic.crushed.gold");
	case 2:
		return I18n::get("ic.crushed.iron");
	case 3:
		return I18n::get("ic.crushed.lead");
	case 4:
		return I18n::get("ic.crushed.silver");
	case 5:
		return I18n::get("ic.crushed.tin");
	case 6:
		return I18n::get("ic.crushed.uranium");
	case 7:
		return I18n::get("ic.purified.copper");
	case 8:
		return I18n::get("ic.purified.gold");
	case 9:
		return I18n::get("ic.purified.iron");
	case 10:
		return I18n::get("ic.purified.lead");
	case 11:
		return I18n::get("ic.purified.silver");
	case 12:
		return I18n::get("ic.purified.tin");
	case 13:
		return I18n::get("ic.purified.uranium");
	case 14:
		return I18n::get("ic.casing.bronze");
	case 15:
		return I18n::get("ic.casing.copper");
	case 16:
		return I18n::get("ic.casing.gold");
	case 17:
		return I18n::get("ic.casing.iron");
	case 18:
		return I18n::get("ic.casing.lead");
	case 19:
		return I18n::get("ic.casing.steel");
	case 20:
		return I18n::get("ic.casing.tin");
	}
}
const TextureUVCoordinateSet& BrokenItem::getIcon(int aux, int, bool) const
{
	return brokenTextures[aux>=(sizeof(brokenTextures)/sizeof(TextureUVCoordinateSet))?0:aux];
}