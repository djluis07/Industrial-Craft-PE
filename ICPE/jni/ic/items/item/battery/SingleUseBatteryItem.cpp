#include "SingleUseBatteryItem.h"

#include <fstream>

SingleUseBatteryItem::SingleUseBatteryItem():BatteryItem("ic.battery.singleuse",ID::mSingleUseBattery-0x100)
{
	setIcon("single_use_battery",0);
}
unsigned int SingleUseBatteryItem::getEU(ItemInstance const&)const
{
	return 1200;
}
unsigned int SingleUseBatteryItem::getMaxEU()const
{
	return 1200;
}
