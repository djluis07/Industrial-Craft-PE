#pragma once

#include "items/Items.h"

class RubberItem : public IC::Items
{
public:
	RubberItem();
public:
	virtual void useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
};
