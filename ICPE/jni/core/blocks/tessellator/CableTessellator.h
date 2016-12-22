#pragma once

#include "mcpe/client/renderer/BlockTessellator.h"

class CableTessellator : public BlockTessellator
{
public:
	bool tessellate(Block const&,BlockPos const&,unsigned char,bool,bool (*)(BlockTessellator*,Block const&,BlockPos const&,uchar,bool));
private:
	bool isElectricBlockAt(BlockPos const&);
};
