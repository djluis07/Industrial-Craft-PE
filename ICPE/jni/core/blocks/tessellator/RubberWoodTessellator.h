#pragma once

#include "mcpe/client/renderer/BlockTessellator.h"

class RubberWoodTessellator : public BlockTessellator
{
public:
	bool tessellate(Block const&,BlockPos const&,unsigned char,bool);
};
