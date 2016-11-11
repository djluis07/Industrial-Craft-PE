#pragma once

#include "mcpe/client/renderer/BlockTessellator.h"

class CableTessellator : public BlockTessellator
{
public:
	bool tessellate(Block&,BlockPos const&,unsigned char,bool,bool (*)(BlockTessellator*,Block&,BlockPos const&,uchar,bool));
private:
	bool isElectricBlockAt(BlockPos const&);
};
