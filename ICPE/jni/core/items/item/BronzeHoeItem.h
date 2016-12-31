#pragma once

#include "items/Items.h"

class BronzeHoeItem : public IC::Items
{
public:
	BronzeHoeItem();
public:
    virtual int getEnchantSlot() const;
    virtual int getEnchantValue() const;
    virtual bool isValidRepairItem(ItemInstance const&, ItemInstance const&);
    virtual void useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
};
