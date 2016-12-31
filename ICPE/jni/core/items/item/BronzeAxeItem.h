#pragma once

#include "items/Items.h"

class BronzeAxeItem : public IC::Items
{
public:
	BronzeAxeItem();
public:
	virtual int getEnchantSlot() const;
    virtual int getEnchantValue() const;
    virtual bool isValidRepairItem(ItemInstance const&, ItemInstance const&);
    virtual float getDestroySpeed(ItemInstance*, Block const*);
    virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
};
