#include "ElectricHoeItem.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/block/Block.h"
#include "mcpe/entity/player/Player.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/util/Util.h"
#include "mcpe/client/resources/I18n.h"

ElectricHoeItem::ElectricHoeItem():IC::Items("ic.electric.hoe",IC::Items::ID::mElectricHoe-0x100)
{
	setIcon("electric_hoe",0);
	setMaxStackSize(1);
	setCategory(CreativeItemCategory::TOOLS);
	setMaxDamage(501);
}
std::string ElectricHoeItem::buildEffectDescriptionName(const ItemInstance&i) const
{
	return "§7"+I18n::get("ic.effectname.lastectricity")+Util::toString((500-i.aux)*50)+"EU/25000EU";
}
void ElectricHoeItem::useOn(ItemInstance*instance, Player*p, int x, int y, int z, signed char side, float px, float py, float pz)
{
	if(!(instance&&p)||instance->aux>=getMaxDamage()-1)
		return ;
	mHoe_iron->useOn(instance,p,x,y,z,side,px,py,pz);
}
