#include "BronzeHoeItem.h"

BronzeHoeItem::BronzeHoeItem():IC::Items("ic.hoe.bronze",ID::mBronzeHoe-0x100)
{
	setCategory(CreativeItemCategory::TOOLS);
	setIcon("icpe_bronze_hoe",0);
	setMaxDamage(250);
	setHandEquipped();
	setMaxStackSize(1);
}
bool BronzeHoeItem::isValidRepairItem(ItemInstance const&, ItemInstance const&item)
{
	return item.getId()==ID::mBronzeHoe||item.getId()==ID::mBronzeIngot;
}
void BronzeHoeItem::useOn(ItemInstance&item, Entity&e, int x, int y, int z, signed char side, float pixelx, float pixely, float pixelz)
{
	return mHoe_iron->useOn(item,e,x,y,z,side,pixelx,pixely,pixelz);
}
int BronzeHoeItem::getEnchantSlot() const
{
	return mHoe_iron->getEnchantSlot();
}
int BronzeHoeItem::getEnchantValue() const
{
	return mHoe_iron->getEnchantValue();
}
