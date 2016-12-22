#pragma once

#include "items/Items.h"

class ElectricHoeItem : public IC::Items
{
public:
	ElectricHoeItem();
public:
	virtual std::string buildEffectDescriptionName(const ItemInstance&) const;
	virtual void useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
};
