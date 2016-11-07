#pragma once

#include "ic/items/Items.h"

class TFBPItem : public IC::Items
{
private:
	TextureUVCoordinateSet tfbpTextures[7];
public:
	TFBPItem();
public:
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
};
