#pragma once

#include "items/Items.h"

class PainterItem : public IC::Items
{
public:
	PainterItem(std::string const&,int,std::string const&);
public:
    virtual void interactEnemy(ItemInstance*, Mob*, Player*);
    virtual void useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
	virtual std::string buildEffectDescriptionName(ItemInstance const&) const;
};
