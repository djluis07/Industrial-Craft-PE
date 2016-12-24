#include "ChainsawItem.h"

#include <stdlib.h>

#include "mcpe/item/ItemInstance.h"
#include "mcpe/block/Block.h"
#include "mcpe/entity/player/Player.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/util/Util.h"
#include "mcpe/client/resources/I18n.h"

ChainsawItem::ChainsawItem():IC::Items("ic.electric.chainsaw",ID::mChainsaw-0x100)
{
	setIcon("icpe_chainsaw",0);
	setMaxStackSize(1);
	setCategory(CreativeItemCategory::TOOLS);
	setMaxDamage(501);
}
std::string ChainsawItem::buildEffectDescriptionName(const ItemInstance&i) const
{
	return "§7"+I18n::get("ic.effectname.lastectricity")+Util::toString((500-i.aux)*50)+"EU/25000EU";
}
float ChainsawItem::getDestroySpeed(ItemInstance*instance, Block*block)
{
	if(!instance||instance->aux>=getMaxDamage()-1)
		return Item::getDestroySpeed(0,block);
	float speed=0;
	speed=mSword_diamond->getDestroySpeed(0,block)>speed?mSword_diamond->getDestroySpeed(0,block):speed;
	speed=mShears->getDestroySpeed(0,block)>speed?mShears->getDestroySpeed(0,block):speed;
	speed=mHatchet_diamond->getDestroySpeed(0,block)>speed?mHatchet_diamond->getDestroySpeed(0,block):speed;
	return speed;
}
bool ChainsawItem::canDestroySpecial(const Block*block) const
{
	bool canDestroy=false;
	canDestroy|=mSword_diamond->canDestroySpecial(block);
	canDestroy|=mHatchet_diamond->canDestroySpecial(block);
	canDestroy|=mShears->canDestroySpecial(block);
	return canDestroy;
}
void ChainsawItem::mineBlock(ItemInstance*instance, BlockID, int, int, int, Mob*m)
{
	if(!instance||instance->aux>=getMaxDamage()-1)
		return;
	instance->hurtAndBreak(1,m);
}
void ChainsawItem::hurtEnemy(ItemInstance*instance, Mob*m, Mob*)
{
	if(!instance||instance->aux>=getMaxDamage()-1)
		return;
	instance->hurtAndBreak(1,m);
}
int ChainsawItem::getAttackDamage()
{
	return mSword_diamond->getAttackDamage();
}
