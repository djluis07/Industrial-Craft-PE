#pragma once

#include "items/Items.h"

class ChainsawItem : public IC::Items
{
public:
	ChainsawItem();
public:
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual int getAttackDamage();
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
	virtual std::string buildEffectDescriptionName(const ItemInstance&) const;
	virtual bool canDestroySpecial(const Block*) const;
	virtual float getDestroySpeed(ItemInstance*, Block*);
};
