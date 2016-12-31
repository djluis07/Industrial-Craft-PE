#include "BronzePickAxeItem.h"

BronzePickAxeItem::BronzePickAxeItem():IC::Items("ic.pickaxe.bronze",ID::mBronzePickAxe-0x100)
{
	setCategory(CreativeItemCategory::TOOLS);
	setIcon("icpe_bronze_pickaxe",0);
	setMaxDamage(250);
	setHandEquipped();
	setMaxStackSize(1);
}
bool BronzePickAxeItem::isValidRepairItem(ItemInstance const&, ItemInstance const&item)
{
	return item.getId()==ID::mBronzePickAxe||item.getId()==ID::mBronzeIngot;
}
float BronzePickAxeItem::getDestroySpeed(ItemInstance*item, Block const*block)
{
	return mPickAxe_iron->getDestroySpeed(item,block)*1.2;
}
void BronzePickAxeItem::mineBlock(ItemInstance*item, BlockID id, int x, int y, int z, Entity*e)
{
	return mPickAxe_iron->mineBlock(item,id,x,y,z,e);
}
int BronzePickAxeItem::getEnchantSlot() const
{
	return mPickAxe_iron->getEnchantSlot();
}
int BronzePickAxeItem::getEnchantValue() const
{
	return mPickAxe_iron->getEnchantValue();
}
bool BronzePickAxeItem::canDestroySpecial(Block const*b) const
{
	return mPickAxe_iron->canDestroySpecial(b);
}
