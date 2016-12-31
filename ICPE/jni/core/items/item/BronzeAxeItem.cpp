#include "BronzeAxeItem.h"

BronzeAxeItem::BronzeAxeItem():IC::Items("ic.axe.bronze",ID::mBronzeAxe-0x100)
{
	setCategory(CreativeItemCategory::TOOLS);
	setIcon("icpe_bronze_axe",0);
	setMaxDamage(250);
	setHandEquipped();
	setMaxStackSize(1);
}
bool BronzeAxeItem::isValidRepairItem(ItemInstance const&, ItemInstance const&item)
{
	return item.getId()==ID::mBronzeAxe||item.getId()==ID::mBronzeIngot;
}
float BronzeAxeItem::getDestroySpeed(ItemInstance*item, Block const*block)
{
	return mHatchet_iron->getDestroySpeed(item,block)*1.2;
}
void BronzeAxeItem::mineBlock(ItemInstance*item, BlockID id, int x, int y, int z, Entity*e)
{
	return mHatchet_iron->mineBlock(item,id,x,y,z,e);
}
int BronzeAxeItem::getEnchantSlot() const
{
	return mHatchet_iron->getEnchantSlot();
}
int BronzeAxeItem::getEnchantValue() const
{
	return mHatchet_iron->getEnchantValue();
}
