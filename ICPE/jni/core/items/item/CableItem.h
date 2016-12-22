#pragma once

#include "items/Items.h"

class CableItem : public IC::Items
{
private:
	TextureUVCoordinateSet tinTextures[2];
	TextureUVCoordinateSet ironTextures[4];
	TextureUVCoordinateSet goldTextures[3];
	TextureUVCoordinateSet copperTextures[2];
	TextureUVCoordinateSet utilTextures[3];
public:
	CableItem();
public:
	virtual std::string buildEffectDescriptionName(const ItemInstance&) const;
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	virtual void useOn(ItemInstance&instance, Entity&p, int x, int y, int z, signed char side, float pixelx, float pixely, float pixelz);
};
