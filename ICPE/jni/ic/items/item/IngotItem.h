#pragma once

#include "ic/items/Items.h"

class IngotItem : public IC::Items
{
private:
	TextureUVCoordinateSet ingotTextures[6];
public:
	IngotItem();
public:
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
};
