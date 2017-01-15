#include "CableUtil.h"

#include "mcpe/level/BlockSource.h"
#include "mcpe/util/FullBlock.h"

#include "items/Items.h"
#include "blocks/Blocks.h"

#include "blocks/blockentity/CableBlockEntity.h"

bool CableUtil::isTinCable(unsigned char aux)
{
	return aux==0||aux==1;
}
bool CableUtil::isGlassCable(unsigned char aux)
{
	return aux==11;
}
bool CableUtil::isCopperCable(unsigned char aux)
{
	return aux==2||aux==3;
}
bool CableUtil::isGoldCable(unsigned char aux)
{
	return aux==4||aux==5||aux==6;
}
bool CableUtil::isIronCable(unsigned char aux)
{
	return aux==7||aux==8||aux==9||aux==10;
}
bool CableUtil::isDetectorCable(unsigned char aux)
{
	return aux==12||aux==13;
}
bool CableUtil::isSplitterCable(unsigned char aux)
{
	return aux==14||aux==15;
}
bool CableUtil::isHeavyCable(unsigned char aux)
{
	return aux==10;
}
int CableUtil::getDropItemID(unsigned char aux)
{
	if(aux==0)
		return IC::Items::ID::mTinCable0;
	else if(aux==1)
		return IC::Items::ID::mTinCable1;
	else if(aux==2)
		return IC::Items::ID::mCopperCable0;
	else if(aux==3)
		return IC::Items::ID::mCopperCable1;
	else if(aux==4)
		return IC::Items::ID::mGoldCable0;
	else if(aux==5)
		return IC::Items::ID::mGoldCable1;
	else if(aux==6)
		return IC::Items::ID::mGoldCable2;
	else if(aux==7)
		return IC::Items::ID::mIronCable0;
	else if(aux==8)
		return IC::Items::ID::mIronCable1;
	else if(aux==9)
		return IC::Items::ID::mIronCable2;
	else if(aux==10)
		return IC::Items::ID::mIronCable3;
	else if(aux==11)
		return IC::Items::ID::mGlassCable;
	else if(aux==12||aux==13)
		return IC::Items::ID::mDetectorCable;
	else if(aux==14||aux==15)
		return IC::Items::ID::mSplitterCable;
	return IC::Items::ID::mTinCable0;
}
unsigned char CableUtil::getPlaceBlockAux(int id)
{
	switch(id)
	{
	case IC::Items::ID::mTinCable0:
	default:
		return 0;
	case IC::Items::ID::mTinCable1:
		return 1;
	case IC::Items::ID::mCopperCable0:
		return 2;
	case IC::Items::ID::mCopperCable1:
		return 3;
	case IC::Items::ID::mGoldCable0:
		return 4;
	case IC::Items::ID::mGoldCable1:
		return 5;
	case IC::Items::ID::mGoldCable2:
		return 6;
	case IC::Items::ID::mIronCable0:
		return 7;
	case IC::Items::ID::mIronCable1:
		return 8;
	case IC::Items::ID::mIronCable2:
		return 9;
	case IC::Items::ID::mIronCable3:
		return 10;
	case IC::Items::ID::mGlassCable:
		return 11;
	case IC::Items::ID::mDetectorCable:
		return 12;
	case IC::Items::ID::mSplitterCable:
		return 14;
	}
	return 0;
}
bool CableUtil::canDye(unsigned char aux)
{
	return aux==1||aux==3||aux==5||aux==6||aux==8||aux==9||aux==10||aux==11;
}
unsigned char CableUtil::dye(unsigned char aux,unsigned char colorType)
{
	unsigned char addAux=colorType;
	
	if(aux==0)
		return 0;//tin
	if(aux==1)
		return 1+addAux;//tin
	if(aux==2)
		return 17;//copper
	if(aux==3)
		return 18+addAux;//copper
	if(aux==4)
		return 34;//gold
	if(aux==5)
		return 35+addAux;//gold
	if(aux==6)
		return 51+addAux;//gold
	if(aux==7)
		return 67;//iron
	if(aux==8)
		return 68+addAux;//iron
	if(aux==9)
		return 84+addAux;//iron
	if(aux==10)
		return 100+addAux;//iron
	if(aux==11)
		return 116+addAux;//glass
	if(aux==12)
		return 132;
	if(aux==13)
		return 133;
	if(aux==14)
		return 134;
	if(aux==15)
		return 135;
	return aux;
}
int CableUtil::getMaxVoltage(unsigned char aux)
{
	if(isTinCable(aux))
		return 32;
	else if(isCopperCable(aux))
		return 128;
	else if(isIronCable(aux))
		return 2048;
	else if(isGoldCable(aux))
		return 512;
	return 78192;
}
float CableUtil::getResistance(unsigned char aux)
{
	if(isUninsulated(aux))
	{
		if(isTinCable(aux))
			return 0.025;
		else if(isCopperCable(aux))
			return 0.3;
		else if(isIronCable(aux))
			return 1.0;
		else if(isGoldCable(aux))
			return 0.5;
		return 0;
	}
	if(isTinCable(aux))
		return 0.02;
	else if(isCopperCable(aux))
		return 0.2;
	else if(isIronCable(aux))
	{
		if(aux==8)
			return 0.95;
		else if(aux==9)
			return 0.9;
		return 0.8;
	}
	else if(isGoldCable(aux))
	{
		if(aux==5)
			return 0.45;
		return 0.4;
	}
	return 0.025;
}
int CableUtil::getHurt(int voltage)
{
	return 1;
}
int CableUtil::getFire(int voltage)
{
	return 20;
}
bool CableUtil::isUninsulated(unsigned char aux)
{
	return aux==0||aux==2||aux==4||aux==8;
}
bool CableUtil::canConnectTo(BlockSource&s,BlockPos const&pos1,BlockPos const&pos2)
{
	if(s.getBlock(pos2)!=Block::mBlocks[IC::Blocks::ID::mCable])
		if(IC::Blocks::mICBlocks[s.getBlock(pos2)->blockId])
			return ((IC::Blocks*)s.getBlock(pos2))->isElectricBlock();
		else
			return false;
	
	if(((CableBlockEntity*)s.getICBlockEntity(pos1))->getColor()==((CableBlockEntity*)s.getICBlockEntity(pos2))->getColor())
		return true;
	return false;
}
