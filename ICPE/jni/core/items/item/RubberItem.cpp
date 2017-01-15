#include "RubberItem.h"

#include "mcpe/client/resources/I18n.h"

#include "blocks/Blocks.h"

RubberItem::RubberItem():IC::Items("ic.rubber",IC::Items::ID::mRubber-0x100)
{
	setCategory(CreativeItemCategory::ITEMS);
	setIcon("icpe_rubber",0);
}
void RubberItem::useOn(ItemInstance&instance, Entity&p, int x, int y, int z, signed char side, float pixelx, float pixely, float pixelz)
{
	ItemInstance resinItem(IC::Blocks::ID::mResin,instance.count,1);
	resinItem.useOn(p,x,y,z,side,pixelx,pixely,pixelz);
	
	instance.count=resinItem.count;
	if(instance.count==0)
		instance.setNull();
}
