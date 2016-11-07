#pragma once

#include "EAbleBlock.h"

class EReceiverBlock : public EAbleBlock
{
public:
	EReceiverBlock(const std::string&, int, const Material&);
public:
	virtual bool isElectronicRecevier()const;
};
