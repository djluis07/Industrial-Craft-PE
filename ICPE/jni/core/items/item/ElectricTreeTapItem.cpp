#include "ElectricTreeTapItem.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/block/Block.h"
#include "mcpe/entity/player/Player.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/util/Util.h"
#include "mcpe/client/resources/I18n.h"
#include "mcpe/util/Random.h"

#include "blocks/Blocks.h"
#include "items/Items.h"

#include "ICPE.h"

ElectricTreeTapItem::ElectricTreeTapItem():IC::Items("ic.electric.treetap",IC::Items::ID::mElectricTreeTap-0x100)
{
	setIcon("icpe_electric_treetap",0);
	setMaxStackSize(1);
	setCategory(CreativeItemCategory::TOOLS);
	setMaxDamage(201);
}
std::string ElectricTreeTapItem::buildEffectDescriptionName(const ItemInstance&i) const
{
	return "§7"+I18n::get("ic.effectname.lastectricity")+Util::toString(((((Item*)this)->getMaxDamage()-1)-i.aux)*50)+"EU/10000EU";
}
