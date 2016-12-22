#pragma once

#include "items/Items.h"

class RubberItem : public IC::Items
{
private:
	TextureUVCoordinateSet rubberTextures[2];
public:
	RubberItem();
public:
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	virtual void useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
};
