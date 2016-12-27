#include "PainterItem.h"

#include "mcpe/client/resources/I18n.h"

PainterItem::PainterItem(std::string const&name,int id,std::string const&tex):IC::Items(name,id)
{
	setCategory(CreativeItemCategory::ITEMS);
	setMaxDamage(33);
	setIcon(tex,0);
	setMaxStackSize(1),
}
/*
	textures[0]=getTextureUVCoordinateSet("icpe_painter_black",0);
	textures[1]=getTextureUVCoordinateSet("icpe_painter_red",0);
	textures[2]=getTextureUVCoordinateSet("icpe_painter_green",0);
	textures[3]=getTextureUVCoordinateSet("icpe_painter_brown",0);
	textures[4]=getTextureUVCoordinateSet("icpe_painter_blue",0);
	textures[5]=getTextureUVCoordinateSet("icpe_painter_purple",0);
	textures[6]=getTextureUVCoordinateSet("icpe_painter_cyan",0);
	textures[7]=getTextureUVCoordinateSet("icpe_painter_light_gray",0);
	textures[8]=getTextureUVCoordinateSet("icpe_painter_gray",0);
	textures[9]=getTextureUVCoordinateSet("icpe_painter_pink",0);
	textures[10]=getTextureUVCoordinateSet("icpe_painter_lime",0);
	textures[11]=getTextureUVCoordinateSet("icpe_painter_yellow",0);
	textures[12]=getTextureUVCoordinateSet("icpe_painter_light_blue",0);
	textures[13]=getTextureUVCoordinateSet("icpe_painter_magenta",0);
	textures[14]=getTextureUVCoordinateSet("icpe_painter_orange",0);
	textures[15]=getTextureUVCoordinateSet("icpe_painter",0);
	textures[16]=getTextureUVCoordinateSet("icpe_painter",0);
*/
std::string PainterItem::buildEffectDescriptionName(ItemInstance const&) const
{
	return "§7"+I18n::get("ic.effectname.lastuses")+":"+Util::toString(32-i.aux)+"/32";
}
