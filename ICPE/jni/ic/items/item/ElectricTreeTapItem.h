#pragma once

#include "ic/items/Items.h"

class ElectricTreeTapItem : public IC::Items
{
public:
	ElectricTreeTapItem();
public:
	virtual const std::string buildEffectDescriptionName(const ItemInstance&) const;
	virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
};
