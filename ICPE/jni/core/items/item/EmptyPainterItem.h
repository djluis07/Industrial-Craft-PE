#pragma once

#include "items/Items.h"

class EmptyPainterItem : public IC::Items
{
public:
	EmptyPainterItem();
public:
    virtual void useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
};
