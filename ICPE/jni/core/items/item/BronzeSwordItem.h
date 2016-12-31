#pragma once

#include "items/Items.h"

class BronzeSwordItem : public IC::Items
{
public:
	BronzeSwordItem();
public:
	virtual int getEnchantSlot() const;
    virtual int getEnchantValue() const;
    virtual bool isValidRepairItem(ItemInstance const&, ItemInstance const&);
    virtual float getDestroySpeed(ItemInstance*, Block const*);
    virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
    virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
    virtual int getAttackDamage();
    virtual bool canDestroySpecial(Block const*) const;
};
