#pragma once

#include "items/Items.h"

class BatteryItem : public IC::Items
{
public:
	BatteryItem(std::string const&,short);
public:
	virtual bool isBatteryItem()const;
	virtual std::string buildEffectDescriptionName(const ItemInstance&) const;
};
