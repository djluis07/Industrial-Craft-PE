#include "TFBPItem.h"

#include "mcpe/client/resources/I18n.h"

TFBPItem::TFBPItem():IC::Items("ic.tfbp.tin",IC::Items::ID::mTFBP-0x100)
{
	setCategory(CreativeItemCategory::ITEMS);
	setStackedByData(true);
	
	tfbpTextures[0]=getTextureUVCoordinateSet("icpe_tfbp_blank",0);
	tfbpTextures[1]=getTextureUVCoordinateSet("icpe_tfbp_chilling",0);
	tfbpTextures[2]=getTextureUVCoordinateSet("icpe_tfbp_cultivation",0);
	tfbpTextures[3]=getTextureUVCoordinateSet("icpe_tfbp_desertification",0);
	tfbpTextures[4]=getTextureUVCoordinateSet("icpe_tfbp_flatification",0);
	tfbpTextures[5]=getTextureUVCoordinateSet("icpe_tfbp_irrigation",0);
	tfbpTextures[6]=getTextureUVCoordinateSet("icpe_tfbp_mushroom",0);
}
std::string TFBPItem::buildDescriptionName(const ItemInstance&i) const
{
	switch(i.aux)
	{
	case 0:
	default:
		return I18n::get("ic.tfbp.blank");
	case 1:
		return I18n::get("ic.tfbp.chilling");
	case 2:
		return I18n::get("ic.tfbp.cultivation");
	case 3:
		return I18n::get("ic.tfbp.desertification");
	case 4:
		return I18n::get("ic.tfbp.flatification");
	case 5:
		return I18n::get("ic.tfbp.irrigation");
	case 6:
		return I18n::get("ic.tfbp.mushroom");
	}
}
const TextureUVCoordinateSet& TFBPItem::getIcon(int aux, int, bool) const
{
	return tfbpTextures[aux>=(sizeof(tfbpTextures)/sizeof(TextureUVCoordinateSet))?0:aux];
}
