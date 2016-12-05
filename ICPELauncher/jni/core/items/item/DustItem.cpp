#include "DustItem.h"

#include "mcpe/client/resources/I18n.h"

DustItem::DustItem():IC::Items("ic.dust.copper",IC::Items::ID::mDust-0x100)
{
	setCategory(CreativeItemCategory::ITEMS);
	setStackedByData(true);
	
	dustTextures[0]=getTextureUVCoordinateSet("du_bronze",0);
	dustTextures[1]=getTextureUVCoordinateSet("du_clay",0);
	dustTextures[2]=getTextureUVCoordinateSet("du_coal",0);
	dustTextures[3]=getTextureUVCoordinateSet("du_coal_fuel",0);
	dustTextures[4]=getTextureUVCoordinateSet("du_copper",0);
	dustTextures[5]=getTextureUVCoordinateSet("du_diamond",0);
	dustTextures[6]=getTextureUVCoordinateSet("du_energium",0);
	dustTextures[7]=getTextureUVCoordinateSet("du_gold",0);
	dustTextures[8]=getTextureUVCoordinateSet("du_iron",0);
	dustTextures[9]=getTextureUVCoordinateSet("du_lapis",0);
	dustTextures[10]=getTextureUVCoordinateSet("du_lead",0);
	dustTextures[11]=getTextureUVCoordinateSet("du_lithium",0);
	dustTextures[12]=getTextureUVCoordinateSet("du_obsidian",0);
	dustTextures[13]=getTextureUVCoordinateSet("du_silicon_dioxide",0);
	dustTextures[14]=getTextureUVCoordinateSet("du_silver",0);
	dustTextures[15]=getTextureUVCoordinateSet("du_stone",0);
	dustTextures[16]=getTextureUVCoordinateSet("du_sulfur",0);
	dustTextures[17]=getTextureUVCoordinateSet("du_tin",0);
	dustTextures[18]=getTextureUVCoordinateSet("small_du_bronze",0);
	dustTextures[19]=getTextureUVCoordinateSet("small_du_copper",0);
	dustTextures[20]=getTextureUVCoordinateSet("small_du_gold",0);
	dustTextures[21]=getTextureUVCoordinateSet("small_du_iron",0);
	dustTextures[22]=getTextureUVCoordinateSet("small_du_lapis",0);
	dustTextures[23]=getTextureUVCoordinateSet("small_du_lead",0);
	dustTextures[24]=getTextureUVCoordinateSet("small_du_obsidian",0);
	dustTextures[25]=getTextureUVCoordinateSet("small_du_lithium",0);
	dustTextures[26]=getTextureUVCoordinateSet("small_du_silver",0);
	dustTextures[27]=getTextureUVCoordinateSet("small_du_sulfur",0);
	dustTextures[28]=getTextureUVCoordinateSet("small_du_tin",0);
}
std::string DustItem::buildDescriptionName(const ItemInstance&i) const
{
	switch(i.aux)
	{
	case 0:
	default:
		return I18n::get("ic.dust.bronze");
	case 1:
		return I18n::get("ic.dust.clay");
	case 2:
		return I18n::get("ic.dust.coal");
	case 3:
		return I18n::get("ic.dust.coal.fuel");
	case 4:
		return I18n::get("ic.dust.copper");
	case 5:
		return I18n::get("ic.dust.diamond");
	case 6:
		return I18n::get("ic.dust.energium");
	case 7:
		return I18n::get("ic.dust.gold");
	case 8:
		return I18n::get("ic.dust.iron");
	case 9:
		return I18n::get("ic.dust.lapis");
	case 10:
		return I18n::get("ic.dust.lead");
	case 11:
		return I18n::get("ic.dust.lithium");
	case 12:
		return I18n::get("ic.dust.obsidian");
	case 13:
		return I18n::get("ic.dust.silicon_dioxide");
	case 14:
		return I18n::get("ic.dust.silver");
	case 15:
		return I18n::get("ic.dust.stone");
	case 16:
		return I18n::get("ic.dust.sulsur");
	case 17:
		return I18n::get("ic.dust.tin");
	case 18:
		return I18n::get("ic.dust.small.bronze");
	case 19:
		return I18n::get("ic.dust.small.copper");
	case 20:
		return I18n::get("ic.dust.small.gold");
	case 21:
		return I18n::get("ic.dust.small.iron");
	case 22:
		return I18n::get("ic.dust.small.lapis");
	case 23:
		return I18n::get("ic.dust.small.lead");
	case 24:
		return I18n::get("ic.dust.small.lithium");
	case 25:
		return I18n::get("ic.dust.small.obsidian");
	case 26:
		return I18n::get("ic.dust.small.silver");
	case 27:
		return I18n::get("ic.dust.small.sulsur");
	case 28:
		return I18n::get("ic.dust.small.tin");
	}
}
const TextureUVCoordinateSet& DustItem::getIcon(int aux, int, bool) const
{
	return dustTextures[aux>=(sizeof(dustTextures)/sizeof(TextureUVCoordinateSet))?0:aux];
}
