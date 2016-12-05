#pragma once

#include "items/Items.h"

class TreeTapItem : public IC::Items
{
public:
	TreeTapItem();
public:
	virtual void useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
};
