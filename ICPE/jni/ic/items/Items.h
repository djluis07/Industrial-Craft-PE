#pragma once

#include "mcpe/item/Item.h"

namespace IC
{
class Items : public Item
{
public:
	class ID
	{
	public:
		static const unsigned short mGuideBook=550;
		static const unsigned short mUranium=2000;
		static const unsigned short mIngot=2001;
		static const unsigned short mRubber=2002;
		static const unsigned short mTreeTap=2003;
		static const unsigned short mCable=2004;
		static const unsigned short mCircuit=2005;
		static const unsigned short mPlate=2006;
		static const unsigned short mBroken=2007;
		static const unsigned short mDust=2008;
		static const unsigned short mAlloyPlate=500;
		static const unsigned short mSlag=2010;
		static const unsigned short mScrap=2011;
		static const unsigned short mForgeHammer=2012;
		static const unsigned short mElectricTreeTap=2013;
		static const unsigned short mTFBP=2014;
		static const unsigned short mCoil=2015;
		static const unsigned short mPowerUnitSmall=2016;
		static const unsigned short mElectricMotor=2017;
		static const unsigned short mElectricHoe=2018;
		static const unsigned short mChainsaw=2019;
		static const unsigned short mSingleUseBattery=2020;
	};
public:
	static void initICAllItems();
	static void addICCreativeItems();
private:
	static void initICItems();
	static void initICBlockItems();
public:
	static bool mICItems[4096];
public:
	Items(std::string const&,short);
public:
	virtual bool isBatteryItem()const;
	virtual unsigned int getEU(ItemInstance const&)const;
	virtual unsigned int getMaxEU()const;
};
}
