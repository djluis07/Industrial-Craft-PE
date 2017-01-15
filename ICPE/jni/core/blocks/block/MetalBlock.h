#pragma once

#include "blocks/Blocks.h"

class MetalBlock : public IC::Blocks
{
public:
	MetalBlock();
public:
	virtual bool isAnyAuxValueInRecipe()const;
	virtual std::string buildDescriptionName(unsigned char) const;
};
