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
		static const unsigned char mOre=200;
		static const unsigned char mMachine=201;
		static const unsigned char mAdvancedMachine=36;
		static const unsigned char mRubberWood=202;
		static const unsigned char mRubberLeaves=203;
		static const unsigned char mRubberSapling=204;
		static const unsigned char mITNT=206;
		static const unsigned char mResin=207;
		static const unsigned char mCable=208;
		static const unsigned char mIronFurnace=209;
		static const unsigned char mIronFence=210;
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
	virtual int getNowVoltage(BlockSource&,BlockPos const&);
};
}
