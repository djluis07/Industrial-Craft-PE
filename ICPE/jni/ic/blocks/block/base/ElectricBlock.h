#pragma once

#include "ic/blocks/Blocks.h"

class ElectricBlock : public IC::Blocks
{
public:
	ElectricBlock(const std::string&, int, const Material&);
public:
	virtual bool isElectricBlock()const;
};
