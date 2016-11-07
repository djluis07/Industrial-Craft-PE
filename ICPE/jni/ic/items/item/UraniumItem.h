#pragma once

#include "ic/items/Items.h"

class UraniumItem : public IC::Items
{
private:
	TextureUVCoordinateSet uraniumTextures[17];
public:
	UraniumItem();
public:
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
};
