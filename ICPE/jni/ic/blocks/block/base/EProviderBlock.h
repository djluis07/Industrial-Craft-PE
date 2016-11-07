#pragma once

#include "EAbleBlock.h"

class EProviderBlock : public EAbleBlock
{
public:
	EProviderBlock(const std::string&, int, const Material&);
public:
	virtual bool isElectronicProvider()const;
};
