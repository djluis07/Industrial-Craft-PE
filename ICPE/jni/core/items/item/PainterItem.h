#pragma once

#include "items/Items.h"

class PainterItem : public IC::Items
{
public:
	PainterItem(std::string const&,int,std::string const&);
public:
	virtual std::string buildEffectDescriptionName(ItemInstance const&) const;
};
