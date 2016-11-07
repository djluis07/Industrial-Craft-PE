#include "BatteryItem.h"

#include "mcpe/client/resources/I18n.h"
#include "mcpe/util/Util.h"

BatteryItem::BatteryItem(std::string const&name,short id):IC::Items(name,id)
{
	setCategory(CreativeItemCategory::TOOLS);
}
bool BatteryItem::isBatteryItem()const
{
	return true;
}
const std::string BatteryItem::buildEffectDescriptionName(const ItemInstance&i) const
{
	return "§7"+I18n::get("ic.effectname.lastectricity")+Util::toString(getEU(i))+"EU/"+Util::toString(getMaxEU())+"EU";
}
