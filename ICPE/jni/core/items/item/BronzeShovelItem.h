#pragma once

#include "items/Items.h"

class BronzeShovelItem : public IC::Items
{
public:
	BronzeShovelItem();
public:
	virtual int getEnchantSlot() const;
    virtual int getEnchantValue() const;
    virtual bool isValidRepairItem(ItemInstance const&, ItemInstance const&);
    virtual float getDestroySpeed(ItemInstance*, Block const*);
    virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
    virtual void useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
};
