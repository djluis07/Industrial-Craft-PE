#pragma once

#include "items/Items.h"

class GuideBookItem : public IC::Items
{
public:
	GuideBookItem();
public:
    virtual std::string buildEffectDescriptionName(ItemInstance const&) const;
    virtual bool isEmissive(int) const;
    virtual void useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
};
