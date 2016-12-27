#pragma once

#include "base/OreBlock.h"
#include "blocks/Blocks.h"

class ICOreBlock : public OreBlock
{
public:
	ICOreBlock();
public:
	virtual std::string buildDescriptionName(unsigned char aux) const;
	virtual int getSpawnResourcesAuxValue(unsigned char)const;
	virtual int getPlacementDataValue(Entity&, BlockPos const&, signed char, Vec3 const&, int)const;
};
