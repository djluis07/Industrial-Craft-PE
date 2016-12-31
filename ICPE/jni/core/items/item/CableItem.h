#pragma once

#include "items/Items.h"
#include "mcpe/util/FullBlock.h"

class CableItem : public IC::Items
{
private:
	int mID;
public:
	CableItem(std::string const&,short,std::string const&,int);
public:
	virtual std::string buildEffectDescriptionName(const ItemInstance&) const;
	virtual void useOn(ItemInstance&instance, Entity&p, int x, int y, int z, signed char side, float pixelx, float pixely, float pixelz);
};
