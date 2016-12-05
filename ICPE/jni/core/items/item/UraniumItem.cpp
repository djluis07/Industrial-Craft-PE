#include "UraniumItem.h"

#include "mcpe/client/resources/I18n.h"

UraniumItem::UraniumItem():IC::Items("ic.uranium.0",IC::Items::ID::mUranium-0x100)
{
	setCategory(CreativeItemCategory::ITEMS);
	setStackedByData(true);
	
	uraniumTextures[0]=getTextureUVCoordinateSet("uranium",0);
	uraniumTextures[1]=getTextureUVCoordinateSet("uranium",235);
	uraniumTextures[2]=getTextureUVCoordinateSet("uranium",238);
	uraniumTextures[3]=getTextureUVCoordinateSet("depleted_dual_mox",0);
	uraniumTextures[4]=getTextureUVCoordinateSet("depleted_dual_uranium",0);
	uraniumTextures[5]=getTextureUVCoordinateSet("depleted_mox",0);
	uraniumTextures[6]=getTextureUVCoordinateSet("depleted_quad_mox",0);
	uraniumTextures[7]=getTextureUVCoordinateSet("depleted_quad_uranium",0);
	uraniumTextures[8]=getTextureUVCoordinateSet("depleted_uranium",0);
	uraniumTextures[9]=getTextureUVCoordinateSet("mox",0);
	uraniumTextures[10]=getTextureUVCoordinateSet("mox_pellet",0);
	uraniumTextures[11]=getTextureUVCoordinateSet("plutonium",0);
	uraniumTextures[12]=getTextureUVCoordinateSet("rtg_pellet",0);
	uraniumTextures[13]=getTextureUVCoordinateSet("small_plutonium",0);
	uraniumTextures[14]=getTextureUVCoordinateSet("small_uranium",235);
	uraniumTextures[15]=getTextureUVCoordinateSet("small_uranium",238);
	uraniumTextures[16]=getTextureUVCoordinateSet("uranium_pellet",0);
}
std::string UraniumItem::buildDescriptionName(const ItemInstance&i) const
{
	switch(i.aux)
	{
	case 0:
	default:
		return I18n::get("ic.uranium.0");
	case 1:
		return I18n::get("ic.uranium.235");
	case 2:
		return I18n::get("ic.uranium.238");
	case 3:
		return I18n::get("ic.depleted.dual.mox");
	case 4:
		return I18n::get("ic.depleted.dual.uranium");
	case 5:
		return I18n::get("ic.depleted.mox");
	case 6:
		return I18n::get("ic.depleted.quad.mox");
	case 7:
		return I18n::get("ic.depleted.quad.uranium");
	case 8:
		return I18n::get("ic.depleted.uranium");
	case 9:
		return I18n::get("ic.mox");
	case 10:
		return I18n::get("ic.mox.pellet");
	case 11:
		return I18n::get("ic.plutonium");
	case 12:
		return I18n::get("ic.rtg.pellet");
	case 13:
		return I18n::get("ic.small.plutonium");
	case 14:
		return I18n::get("ic.small.uranium.235");
	case 15:
		return I18n::get("ic.small.uranium.238");
	case 16:
		return I18n::get("ic.uranium.pellet");
	}
}
const TextureUVCoordinateSet& UraniumItem::getIcon(int aux, int, bool) const
{
	return uraniumTextures[aux>=(sizeof(uraniumTextures)/sizeof(TextureUVCoordinateSet))?0:aux];
}
