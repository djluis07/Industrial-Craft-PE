#pragma once

#include "ic/items/Items.h"

class ElectricHoeItem : public IC::Items
{
public:
	ElectricHoeItem();
public:
	virtual const std::string buildEffectDescriptionName(const ItemInstance&) const;
	virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
};
