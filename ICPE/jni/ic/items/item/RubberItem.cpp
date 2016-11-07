#include "RubberItem.h"

#include "mcpe/client/resources/I18n.h"

#include "ic/blocks/Blocks.h"

RubberItem::RubberItem():IC::Items("ic.rubber.0",IC::Items::ID::mRubber-0x100)
{
	setCategory(CreativeItemCategory::ITEMS);
	setStackedByData(true);
	
	rubberTextures[0]=getTextureUVCoordinateSet("resin",0);
	rubberTextures[1]=getTextureUVCoordinateSet("rubber",0);
}
std::string RubberItem::buildDescriptionName(const ItemInstance&i) const
{
	switch(i.aux)
	{
	case 0:
	default:
		return I18n::get("ic.rubber.0");
	case 1:
		return I18n::get("ic.rubber.1");
	}
}
const TextureUVCoordinateSet& RubberItem::getIcon(int aux, int, bool) const
{
	return rubberTextures[aux>=(sizeof(rubberTextures)/sizeof(TextureUVCoordinateSet))?0:aux];
}
void RubberItem::useOn(ItemInstance*instance, Player*p, int x, int y, int z, signed char side, float pixelx, float pixely, float pixelz)
{
	if(!p||!instance)
		return;
	
	ItemInstance resinItem(IC::Blocks::ID::mResin,instance->count,instance->aux);
	resinItem.useOn(p,x,y,z,side,pixelx,pixely,pixelz);
	
	instance->count=resinItem.count;
	if(instance->count==0)
		instance->setNull();
}
