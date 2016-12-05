#pragma once

#include "items/Items.h"

class ElectricTreeTapItem : public IC::Items
{
public:
	ElectricTreeTapItem();
public:
	virtual std::string buildEffectDescriptionName(const ItemInstance&) const;
	virtual void useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
};
