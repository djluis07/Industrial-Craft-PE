#pragma once

#include "EAbleBlock.h"

class ESpreadBlock : public EAbleBlock
{
public:
	ESpreadBlock(const std::string&, int, const Material&);
public:
	virtual bool isElectronicConductor()const;
};
