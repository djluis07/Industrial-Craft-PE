#pragma once

#include "ic/items/item/base/BatteryItem.h"

class SingleUseBatteryItem : public BatteryItem
{
public:
	SingleUseBatteryItem();
public:
	virtual unsigned int getEU(ItemInstance const&)const;
	virtual unsigned int getMaxEU()const;
};
