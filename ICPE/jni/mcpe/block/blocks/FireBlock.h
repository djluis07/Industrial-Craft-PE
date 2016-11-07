#pragma once

#include "mcpe/block/Block.h"

struct FireBlock : public Block
{
	void setFlammable(BlockID,int,int);
};
