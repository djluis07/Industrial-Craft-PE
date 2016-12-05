#pragma once

#include "items/Items.h"

class DustItem : public IC::Items
{
private:
	TextureUVCoordinateSet dustTextures[29];
public:
	DustItem();
public:
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
};
