#pragma once

#include "items/Items.h"

class ResinItem : public IC::Items
{
public:
	ResinItem();
public:
	virtual void useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
};
