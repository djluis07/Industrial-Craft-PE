#include "CableUtil.h"

#include "mcpe/level/BlockSource.h"
#include "mcpe/util/FullBlock.h"

#include "items/Items.h"
#include "blocks/Blocks.h"

bool CableUtil::isTinCable(unsigned char aux)
{
	return aux>=0&&aux<=16;
}
int CableUtil::getDropItemID(unsigned char aux)
{
	if(aux==0)
		return IC::Items::ID::mTinCable0;
	else if(aux>=1&&aux<=16)
		return IC::Items::ID::mTinCable1;
	else if(aux==17)
		return IC::Items::ID::mCopperCable0;
	else if(aux>=18&&aux<=33)
		return IC::Items::ID::mCopperCable1;
	else if(aux==34)
		return IC::Items::ID::mGoldCable0;
	else if(aux>=35&&aux<=50)
		return IC::Items::ID::mGoldCable1;
	else if(aux>=51&&aux<=66)
		return IC::Items::ID::mGoldCable2;
	else if(aux==67)
		return IC::Items::ID::mIronCable0;
	else if(aux>=68&&aux<=83)
		return IC::Items::ID::mIronCable1;
	else if(aux>=84&&aux<=99)
		return IC::Items::ID::mIronCable2;
	else if(aux>=100&&aux<=115)
		return IC::Items::ID::mIronCable3;
	else if(aux>=116&&aux<=131)
		return IC::Items::ID::mGlassCable;
	else if(aux==132&&aux==133)
		return IC::Items::ID::mDetectorCable;
	else if(aux==134&&aux==135)
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
		return 16;
	case IC::Items::ID::mCopperCable0:
		return 17;
	case IC::Items::ID::mCopperCable1:
		return 33;
	case IC::Items::ID::mGoldCable0:
		return 34;
	case IC::Items::ID::mGoldCable1:
		return 50;
	case IC::Items::ID::mGoldCable2:
		return 66;
	case IC::Items::ID::mIronCable0:
		return 67;
	case IC::Items::ID::mIronCable1:
		return 83;
	case IC::Items::ID::mIronCable2:
		return 99;
	case IC::Items::ID::mIronCable3:
		return 115;
	case IC::Items::ID::mGlassCable:
		return 131;
	case IC::Items::ID::mDetectorCable:
		return 132;
	case IC::Items::ID::mSplitterCable:
		return 134;
	}
	return 0;
}
bool CableUtil::isGlassCable(unsigned char aux)
{
	return aux>=116&&aux<=131;
}
bool CableUtil::isCopperCable(unsigned char aux)
{
	return aux>=17&&aux<=33;
}
bool CableUtil::isGoldCable(unsigned char aux)
{
	return aux>=34&&aux<=66;
}
bool CableUtil::isIronCable(unsigned char aux)
{
	return aux>=67&&aux<=115;
}
unsigned char CableUtil::dye(unsigned char aux,PaletteColor colorType)
{
	unsigned char addAux=(unsigned char)colorType;
	if(aux>=1&&aux<=16)
		return 1+addAux;
	if(aux>=18&&aux<=33)
		return 18+addAux;
	if(aux>=35&&aux<=50)
		return 35+addAux;
	if(aux>=51&&aux<=66)
		return 51+addAux;
	if(aux>=68&&aux<=83)
		return 68+addAux;
	if(aux>=84&&aux<=99)
		return 84+addAux;
	if(aux>=100&&aux<=115)
		return 100+addAux;
	if(aux>=116&&aux<=131)
		return 116+addAux;
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
		if(aux>=68&&aux<=83)
			return 0.95;
		else if(aux>=84&&aux<=99)
			return 0.9;
		return 0.8;
	}
	else if(isGoldCable(aux))
	{
		if(aux>=35&&aux<=50)
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
	return aux==0||aux==17||aux==34||aux==67;
}
void CableUtil::doDye(BlockSource&s,BlockPos const&pos,PaletteColor color)
{
	s.setBlockAndData(pos,s.getBlockID(pos),dye(s.getData(pos),color),3,0);
}
bool CableUtil::canConnectTo(BlockSource&s,BlockPos const&pos1,BlockPos const&pos2)
{
	if(s.getBlock(pos2)!=Block::mBlocks[IC::Blocks::ID::mCable])
		if(IC::Blocks::mICBlocks[s.getBlock(pos2)->blockId])
			return ((IC::Blocks*)s.getBlock(pos2))->isElectricBlock();
		else
			return false;
	
	unsigned char aux1=s.getData(pos1);
	unsigned char aux2=s.getData(pos2);
	
	if(getColor(aux1)==getColor(aux2))
		return true;
	return false;
}
bool CableUtil::isDetectorCable(unsigned char aux)
{
	return aux==132||aux==133;
}
bool CableUtil::isSplitterCable(unsigned char aux)
{
	return aux==134||aux==135;
}
PaletteColor CableUtil::getColor(unsigned char aux)
{
	if(aux>=1&&aux<=16)
		return (PaletteColor)(aux-1);
	else if(aux>=18&&aux<=33)
		return (PaletteColor)(aux-18);
	else if(aux>=35&&aux<=50)
		return (PaletteColor)(aux-35);
	else if(aux>=51&&aux<=66)
		return (PaletteColor)(aux-51);
	else if(aux>=68&&aux<=83)
		return (PaletteColor)(aux-68);
	else if(aux>=84&&aux<=99)
		return (PaletteColor)(aux-84);
	else if(aux>=100&&aux<=115)
		return (PaletteColor)(aux-100);
	else if(aux>=116&&aux<=131)
		return (PaletteColor)(aux-116);
	return PaletteColor::BLACK;
}
