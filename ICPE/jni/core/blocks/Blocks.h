#pragma once

#include "mcpe/block/Block.h"

namespace IC
{
class Blocks : public Block
{
public:
	class ID
	{
	public:
		static const unsigned char mOre=36;
		static const unsigned char mMachine=210;
		static const unsigned char mAdvancedMachine=211;
		static const unsigned char mRubberWood=212;
		static const unsigned char mRubberLeaves=213;
		static const unsigned char mRubberSapling=214;
		static const unsigned char mITNT=215;
		static const unsigned char mResin=216;
		static const unsigned char mCable=220;
		static const unsigned char mIronFurnace=218;
		static const unsigned char mIronFence=219;
		static const unsigned char mMetal=221;
	};
public:
	static bool mICBlocks[256];
public:
	static void initICBlocks();
public:
	Blocks(std::string const&,int,Material const&);
public:
	virtual bool isElectricBlock()const;
	virtual bool isElectricProvider()const;
	virtual bool isElectricRecevier()const;
	virtual bool isElectricConductor()const;
	virtual bool shouldExplodeOutOfVoltage()const;
	virtual int getElectricResistance()const;
	virtual int getMaxVoltage()const;
	virtual int getNowVoltage(BlockSource&,BlockPos const&)const;
	virtual bool isAnyAuxValueInRecipe()const;
};
}
