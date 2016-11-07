#pragma once

#include "ic/items/Items.h"

class PlateItem : public IC::Items
{
private:
	TextureUVCoordinateSet plateTextures[18];
public:
	PlateItem();
public:
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
};
