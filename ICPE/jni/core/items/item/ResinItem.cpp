#include "ResinItem.h"

#include "mcpe/client/resources/I18n.h"

#include "blocks/Blocks.h"

ResinItem::ResinItem():IC::Items("ic.resin",IC::Items::ID::mResin-0x100)
{
	setCategory(CreativeItemCategory::ITEMS);
	setIcon("icpe_resin",0);
}
void ResinItem::useOn(ItemInstance&instance, Entity&p, int x, int y, int z, signed char side, float pixelx, float pixely, float pixelz)
{
	ItemInstance resinItem(IC::Blocks::ID::mResin,instance.count,0);
	resinItem.useOn(p,x,y,z,side,pixelx,pixely,pixelz);
	
	instance.count=resinItem.count;
	if(instance.count==0)
		instance.setNull();
}
