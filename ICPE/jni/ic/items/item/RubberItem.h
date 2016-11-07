#pragma once

#include "ic/items/Items.h"

class RubberItem : public IC::Items
{
private:
	TextureUVCoordinateSet rubberTextures[2];
public:
	RubberItem();
public:
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	virtual void useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
};
