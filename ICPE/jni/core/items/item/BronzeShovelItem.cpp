#include "BronzeShovelItem.h"

BronzeShovelItem::BronzeShovelItem():IC::Items("ic.shovel.bronze",ID::mBronzeShovel-0x100)
{
	setCategory(CreativeItemCategory::TOOLS);
	setIcon("icpe_bronze_shovel",0);
	setMaxDamage(250);
	setHandEquipped();
	setMaxStackSize(1);
}
bool BronzeShovelItem::isValidRepairItem(ItemInstance const&, ItemInstance const&item)
{
	return item.getId()==ID::mBronzeShovel||item.getId()==ID::mBronzeIngot;
}
float BronzeShovelItem::getDestroySpeed(ItemInstance*item, Block const*block)
{
	return mShovel_iron->getDestroySpeed(item,block)*1.2;
}
void BronzeShovelItem::mineBlock(ItemInstance*item, BlockID id, int x, int y, int z, Entity*e)
{
	return mShovel_iron->mineBlock(item,id,x,y,z,e);
}
void BronzeShovelItem::useOn(ItemInstance&item, Entity&e, int x, int y, int z, signed char side, float pixelx, float pixely, float pixelz)
{
	return mShovel_iron->useOn(item,e,x,y,z,side,pixelx,pixely,pixelz);
}
int BronzeShovelItem::getEnchantSlot() const
{
	return mShovel_iron->getEnchantSlot();
}
int BronzeShovelItem::getEnchantValue() const
{
	return mShovel_iron->getEnchantValue();
}
