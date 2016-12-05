#pragma once

#include "blocks/Blocks.h"

class ICOreBlock : public IC::Blocks
{
public:
	ICOreBlock();
public:
	virtual std::string buildDescriptionName(unsigned char aux) const;
	virtual int getSpawnResourcesAuxValue(unsigned char);
	virtual int getPlacementDataValue(Mob&, BlockPos const&, signed char, Vec3 const&, int);
};
