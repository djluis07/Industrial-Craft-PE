#pragma once

#include "ic/items/Items.h"

class TreeTapItem : public IC::Items
{
public:
	TreeTapItem();
public:
	virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
};
