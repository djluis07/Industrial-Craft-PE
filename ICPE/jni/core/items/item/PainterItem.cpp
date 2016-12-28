#include "PainterItem.h"

#include "mcpe/client/resources/I18n.h"
#include "mcpe/util/Util.h"
#include "mcpe/entity/Mob.h"
#include "mcpe/entity/EntityType.h"
#include "mcpe/entity/EntityClassTree.h"

PainterItem::PainterItem(std::string const&name,int id,std::string const&tex):IC::Items(name,id)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxDamage(32);
	setIcon(tex,0);
	setMaxStackSize(1);
}
void PainterItem::useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float)
{
	
}
std::string PainterItem::buildEffectDescriptionName(ItemInstance const&i) const
{
	return "§7"+I18n::get("ic.effectname.lastuses")+":"+Util::toString(32-i.aux)+"/32";
}
void PainterItem::interactEnemy(ItemInstance*item, Mob*mob, Player*player)
{
	if(!mob||!EntityClassTree::isInstanceOf(*mob,EntityType::SHEEP))
		return;
	mob->setColor((PaletteColor)(16-(item->getId()-ID::mPainterBlack)));
	ItemInstance item_(351,1,16-(item->getId()-ID::mPainterBlack));
	mDye_powder->interactEnemy(&item_,mob,player);
	if(item->aux<(getMaxDamage()-1))
		item->hurtAndBreak(1,0);
	else
		(*item)=ItemInstance(ID::mPainter,1,0);
}
