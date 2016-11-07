#pragma once

#include "ic/items/Items.h"

class CircuitItem : public IC::Items
{
private:
	TextureUVCoordinateSet circuitTextures[2];
public:
	CircuitItem();
public:
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
};
