#pragma once

#include "mcpe/item/Item.h"

class TextureUVCoordinateSet;

namespace IC
{
class Items : public Item
{
public:
	class ID
	{
	public:
		static const short mUranium=500;
		static const short mPainter=501;
		static const short mRubber=502;
		static const short mTreeTap=503;
		static const short mCable=504;
		static const short mSlag=510;
		static const short mScrap=511;
		static const short mForgeHammer=512;
		static const short mElectricTreeTap=513;
		static const short mCoil=515;
		static const short mPowerUnitSmall=516;
		static const short mElectricMotor=517;
		static const short mElectricHoe=518;
		static const short mChainsaw=519;
		static const short mSingleUseBattery=520;
		static const short mGuideBook=521;
		static const short mTinIngot=522;
		static const short mSteelIngot=523;
		static const short mCopperIngot=524;
		static const short mLeadIngot=525;
		static const short mBronzeIngot=526;
		static const short mAlloyIngot=527;
		static const short mCircuit=528;
		static const short mAdvancedCircuit=529;
		static const short mBronzePlate=530;
		static const short mCopperPlate=531;
		static const short mGoldPlate=532;
		static const short mIronPlate=533;
		static const short mLapisPlate=534;
		static const short mLeadPlate=535;
		static const short mObsidianPlate=536;
		static const short mSteelPlate=537;
		static const short mTinPlate=538;
		static const short mDenseBronzePlate=539;
		static const short mDenseCopperPlate=540;
		static const short mDenseGoldPlate=541;
		static const short mDenseIronPlate=542;
		static const short mDenseLapisPlate=543;
		static const short mDenseLeadPlate=544;
		static const short mDenseObsidianPlate=545;
		static const short mDenseSteelPlate=546;
		static const short mDenseTinPlate=547;
		static const short mBronzeDust=548;
		static const short mClayDust=549;
		static const short mCoalDust=550;
		static const short mCoalFuelDust=551;
		static const short mCopperDust=552;
		static const short mDiamondDust=553;
		static const short mEnergiumDust=554;
		static const short mGoldDust=555;
		static const short mIronDust=556;
		static const short mLapisDust=557;
		static const short mLeadDust=558;
		static const short mLithiumDust=559;
		static const short mObsidianDust=560;
		static const short mSiliconDioxideDust=561;
		static const short mSilverDust=562;
		static const short mStoneDust=563;
		static const short mSulfurDust=564;
		static const short mTinDust=565;
		static const short mSmallBronzeDust=567;
		static const short mSmallCopperDust=568;
		static const short mSmallGoldDust=569;
		static const short mSmallIronDust=570;
		static const short mSmallLapisDust=571;
		static const short mSmallLeadDust=572;
		static const short mSmallObsidianDust=573;
		static const short mSmallLithiumDust=574;
		static const short mSmallSilverDust=575;
		static const short mSmallSulfurDust=576;
		static const short mSmallTinDust=577;
		static const short mBlankTFBP=578;
		static const short mChillingTFBP=579;
		static const short mCultivationTFBP=580;
		static const short mDesertificationTFBP=581;
		static const short mFlatificationTFBP=582;
		static const short mIrrigationTFBP=583;
		static const short mMushroomTFBP=584;
		static const short mCrushedCopper=585;
		static const short mCrushedGold=586;
		static const short mCrushedIron=587;
		static const short mCrushedLead=588;
		static const short mCrushedSilver=589;
		static const short mCrushedTin=590;
		static const short mCrushedUranium=591;
		static const short mPurifiedCopper=592;
		static const short mPurifiedGold=593;
		static const short mPurifiedIron=594;
		static const short mPurifiedLead=595;
		static const short mPurifiedSilver=596;
		static const short mPurifiedTin=597;
		static const short mPurifiedUranium=598;
		static const short mCasingBronze=599;
		static const short mCasingCopper=600;
		static const short mCasingGold=601;
		static const short mCasingIron=602;
		static const short mCasingLead=603;
		static const short mCasingSteel=604;
		static const short mCasingTin=605;
		static const short mPainterBlack=606;
		
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
public:
	static void registerItem(short,std::string const&,std::string const&,int);
	static void registerItem(short,std::string const&,TextureUVCoordinateSet const&);
};
}
