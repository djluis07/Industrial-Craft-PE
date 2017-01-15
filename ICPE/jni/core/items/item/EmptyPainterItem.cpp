#include "EmptyPainterItem.h"

EmptyPainterItem::EmptyPainterItem():IC::Items("ic.painter",IC::Items::ID::mPainter-0x100)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxStackSize(1);
	setIcon("icpe_painter",0);
}
void EmptyPainterItem::useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float)
{
	
}
