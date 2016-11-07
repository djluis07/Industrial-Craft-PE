#pragma once

#include "ic/blocks/Blocks.h"

class EAbleBlock : public IC::Blocks
{
public:
	EAbleBlock(const std::string&, int, const Material&);
public:
	virtual bool isElectronicBlock()const;
};
