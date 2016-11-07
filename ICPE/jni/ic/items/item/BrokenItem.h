#pragma once

#include "ic/items/Items.h"

class BrokenItem : public IC::Items
{
private:
	TextureUVCoordinateSet brokenTextures[21];
public:
	BrokenItem();
public:
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
};
