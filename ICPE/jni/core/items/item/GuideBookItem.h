#pragma once

#include "items/Items.h"

class GuideBookItem : public IC::Items
{
public:
	GuideBookItem();
public:
    virtual std::string buildEffectDescriptionName(ItemInstance const&) const;
    virtual bool isEmissive(int) const;
    virtual void useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
};
