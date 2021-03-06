#include "Items.h"

#include "mcpe/item/BlockItem.h"
#include "mcpe/item/AuxDataBlockItem.h"
#include "mcpe/block/Block.h"
#include "mcpe/client/resources/I18n.h"

#include "blocks/Blocks.h"
#include "util/Log.h"

#include "item/base/ICDefaultItem.h"
#include "item/battery/SingleUseBatteryItem.h"
#include "item/RubberItem.h"
#include "item/ResinItem.h"
#include "item/TreeTapItem.h"
#include "item/CableItem.h"
#include "item/ForgeHammerItem.h"
#include "item/ElectricTreeTapItem.h"
#include "item/ElectricHoeItem.h"
#include "item/ChainsawItem.h"
#include "item/PainterItem.h"
#include "item/EmptyPainterItem.h"
#include "item/BronzeShovelItem.h"
#include "item/BronzeHoeItem.h"
#include "item/BronzeSwordItem.h"
#include "item/BronzePickAxeItem.h"
#include "item/BronzeAxeItem.h"

bool IC::Items::mICItems[4096];

namespace IC
{
void Items::initICAllItems()
{
	for(bool & item : mICItems)
		item=false;
	initICItems();
	initICBlockItems();
}
void Items::addICCreativeItems()
{
	Item::addCreativeItem(IC::Blocks::ID::mOre,0);
	Item::addCreativeItem(IC::Blocks::ID::mOre,1);
	Item::addCreativeItem(IC::Blocks::ID::mOre,2);
	Item::addCreativeItem(IC::Blocks::ID::mOre,3);
	Item::addCreativeItem(IC::Blocks::ID::mOre,4);
	Item::addCreativeItem(IC::Blocks::ID::mRubberSapling,0);
	Item::addCreativeItem(IC::Blocks::ID::mITNT,0);
	Item::addCreativeItem(IC::Blocks::ID::mRubberWood,0);
	Item::addCreativeItem(IC::Blocks::ID::mRubberLeaves,0);
	Item::addCreativeItem(IC::Blocks::ID::mIronFence,0);
	Item::addCreativeItem(IC::Blocks::ID::mFurnace,0);
	Item::addCreativeItem(IC::Blocks::ID::mMetal,0);
	Item::addCreativeItem(IC::Blocks::ID::mMetal,1);
	Item::addCreativeItem(IC::Blocks::ID::mMetal,2);
	Item::addCreativeItem(IC::Blocks::ID::mMetal,3);
	Item::addCreativeItem(IC::Blocks::ID::mMetal,4);
	Item::addCreativeItem(IC::Blocks::ID::mMetal,5);
	Item::addCreativeItem(IC::Blocks::ID::mMetal,6);
	Item::addCreativeItem(IC::Blocks::ID::mMetal,7);
	
	Item::addCreativeItem(ID::mPainter,0);
	Item::addCreativeItem(ID::mResin,0);
	Item::addCreativeItem(ID::mRubber,0);
	Item::addCreativeItem(ID::mTreeTap,0);
	Item::addCreativeItem(ID::mICCoin,0);
	Item::addCreativeItem(ID::mTinCable0,0);
	Item::addCreativeItem(ID::mTinCable1,0);
	Item::addCreativeItem(ID::mIronCable0,0);
	Item::addCreativeItem(ID::mIronCable1,0);
	Item::addCreativeItem(ID::mIronCable2,0);
	Item::addCreativeItem(ID::mIronCable3,0);
	Item::addCreativeItem(ID::mGoldCable0,0);
	Item::addCreativeItem(ID::mGoldCable1,0);
	Item::addCreativeItem(ID::mGoldCable2,0);
	Item::addCreativeItem(ID::mCopperCable0,0);
	Item::addCreativeItem(ID::mCopperCable1,0);
	Item::addCreativeItem(ID::mDetectorCable,0);
	Item::addCreativeItem(ID::mGlassCable,0);
	Item::addCreativeItem(ID::mSplitterCable,0);
	Item::addCreativeItem(ID::mScrap,0);
	Item::addCreativeItem(ID::mSlag,0);
	Item::addCreativeItem(ID::mForgeHammer,0);
	Item::addCreativeItem(ID::mElectricTreeTap,0);
	Item::addCreativeItem(ID::mElectricTreeTap,200);
	Item::addCreativeItem(ID::mElectricHoe,0);
	Item::addCreativeItem(ID::mElectricHoe,500);
	Item::addCreativeItem(ID::mChainsaw,0);
	Item::addCreativeItem(ID::mChainsaw,500);
	Item::addCreativeItem(ID::mCoil,0);
	Item::addCreativeItem(ID::mPowerUnitSmall,0);
	Item::addCreativeItem(ID::mElectricMotor,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mTinIngot,0);
	Item::addCreativeItem(ID::mSteelIngot,0);
	Item::addCreativeItem(ID::mCopperIngot,0);
	Item::addCreativeItem(ID::mLeadIngot,0);
	Item::addCreativeItem(ID::mBronzeIngot,0);
	Item::addCreativeItem(ID::mAlloyIngot,0);
	Item::addCreativeItem(ID::mCircuit,0);
	Item::addCreativeItem(ID::mAdvancedCircuit,0);
	Item::addCreativeItem(ID::mBronzePlate,0);
	Item::addCreativeItem(ID::mCopperPlate,0);
	Item::addCreativeItem(ID::mGoldPlate,0);
	Item::addCreativeItem(ID::mIronPlate,0);
	Item::addCreativeItem(ID::mLapisPlate,0);
	Item::addCreativeItem(ID::mLeadPlate,0);
	Item::addCreativeItem(ID::mObsidianPlate,0);
	Item::addCreativeItem(ID::mSteelPlate,0);
	Item::addCreativeItem(ID::mTinPlate,0);
	Item::addCreativeItem(ID::mDenseBronzePlate,0);
	Item::addCreativeItem(ID::mDenseCopperPlate,0);
	Item::addCreativeItem(ID::mDenseGoldPlate,0);
	Item::addCreativeItem(ID::mDenseIronPlate,0);
	Item::addCreativeItem(ID::mDenseLapisPlate,0);
	Item::addCreativeItem(ID::mDenseLeadPlate,0);
	Item::addCreativeItem(ID::mDenseObsidianPlate,0);
	Item::addCreativeItem(ID::mDenseSteelPlate,0);
	Item::addCreativeItem(ID::mDenseTinPlate,0);
	Item::addCreativeItem(ID::mBronzeDust,0);
	Item::addCreativeItem(ID::mClayDust,0);
	Item::addCreativeItem(ID::mCoalDust,0);
	Item::addCreativeItem(ID::mCoalFuelDust,0);
	Item::addCreativeItem(ID::mCopperDust,0);
	Item::addCreativeItem(ID::mDiamondDust,0);
	Item::addCreativeItem(ID::mEnergiumDust,0);
	Item::addCreativeItem(ID::mGoldDust,0);
	Item::addCreativeItem(ID::mIronDust,0);
	Item::addCreativeItem(ID::mLapisDust,0);
	Item::addCreativeItem(ID::mLeadDust,0);
	Item::addCreativeItem(ID::mLithiumDust,0);
	Item::addCreativeItem(ID::mObsidianDust,0);
	Item::addCreativeItem(ID::mSiliconDioxideDust,0);
	Item::addCreativeItem(ID::mSilverDust,0);
	Item::addCreativeItem(ID::mStoneDust,0);
	Item::addCreativeItem(ID::mSulfurDust,0);
	Item::addCreativeItem(ID::mTinDust,0);
	Item::addCreativeItem(ID::mSmallBronzeDust,0);
	Item::addCreativeItem(ID::mSmallCopperDust,0);
	Item::addCreativeItem(ID::mSmallGoldDust,0);
	Item::addCreativeItem(ID::mSmallIronDust,0);
	Item::addCreativeItem(ID::mSmallLapisDust,0);
	Item::addCreativeItem(ID::mSmallLeadDust,0);
	Item::addCreativeItem(ID::mSmallObsidianDust,0);
	Item::addCreativeItem(ID::mSmallLithiumDust,0);
	Item::addCreativeItem(ID::mSmallSilverDust,0);
	Item::addCreativeItem(ID::mSmallSulfurDust,0);
	Item::addCreativeItem(ID::mSmallTinDust,0);
	Item::addCreativeItem(ID::mBlankTFBP,0);
	Item::addCreativeItem(ID::mChillingTFBP,0);
	Item::addCreativeItem(ID::mCultivationTFBP,0);
	Item::addCreativeItem(ID::mDesertificationTFBP,0);
	Item::addCreativeItem(ID::mFlatificationTFBP,0);
	Item::addCreativeItem(ID::mIrrigationTFBP,0);
	Item::addCreativeItem(ID::mMushroomTFBP,0);
	Item::addCreativeItem(ID::mCrushedCopper,0);
	Item::addCreativeItem(ID::mCrushedGold,0);
	Item::addCreativeItem(ID::mCrushedIron,0);
	Item::addCreativeItem(ID::mCrushedLead,0);
	Item::addCreativeItem(ID::mCrushedSilver,0);
	Item::addCreativeItem(ID::mCrushedTin,0);
	Item::addCreativeItem(ID::mCrushedUranium,0);
	Item::addCreativeItem(ID::mPurifiedCopper,0);
	Item::addCreativeItem(ID::mPurifiedGold,0);
	Item::addCreativeItem(ID::mPurifiedIron,0);
	Item::addCreativeItem(ID::mPurifiedLead,0);
	Item::addCreativeItem(ID::mPurifiedSilver,0);
	Item::addCreativeItem(ID::mPurifiedTin,0);
	Item::addCreativeItem(ID::mPurifiedUranium,0);
	Item::addCreativeItem(ID::mCasingBronze,0);
	Item::addCreativeItem(ID::mCasingCopper,0);
	Item::addCreativeItem(ID::mCasingGold,0);
	Item::addCreativeItem(ID::mCasingIron,0);
	Item::addCreativeItem(ID::mCasingLead,0);
	Item::addCreativeItem(ID::mCasingSteel,0);
	Item::addCreativeItem(ID::mCasingTin,0);
	Item::addCreativeItem(ID::mPainterBlack,0);
	Item::addCreativeItem(ID::mPainterRed,0);
	Item::addCreativeItem(ID::mPainterBrown,0);
	Item::addCreativeItem(ID::mPainterGreen,0);
	Item::addCreativeItem(ID::mPainterBlue,0);
	Item::addCreativeItem(ID::mPainterPurple,0);
	Item::addCreativeItem(ID::mPainterCyan,0);
	Item::addCreativeItem(ID::mPainterGray,0);
	Item::addCreativeItem(ID::mPainterLightGray,0);
	Item::addCreativeItem(ID::mPainterPink,0);
	Item::addCreativeItem(ID::mPainterLime,0);
	Item::addCreativeItem(ID::mPainterYellow,0);
	Item::addCreativeItem(ID::mPainterLightBlue,0);
	Item::addCreativeItem(ID::mPainterMagenta,0);
	Item::addCreativeItem(ID::mPainterOrange,0);
	Item::addCreativeItem(ID::mPainterWhite,0);
	Item::addCreativeItem(ID::mBronzeShovel,0);
	Item::addCreativeItem(ID::mBronzePickAxe,0);
	Item::addCreativeItem(ID::mBronzeAxe,0);
	Item::addCreativeItem(ID::mBronzeSword,0);
	Item::addCreativeItem(ID::mBronzeHoe,0);
	Item::addCreativeItem(ID::mEjector,0);
	Item::addCreativeItem(ID::mEjectorUp,0);
	Item::addCreativeItem(ID::mEjectorDown,0);
	Item::addCreativeItem(ID::mEjectorEast,0);
	Item::addCreativeItem(ID::mEjectorWest,0);
	Item::addCreativeItem(ID::mEjectorNorth,0);
	Item::addCreativeItem(ID::mEjectorSouth,0);
	Item::addCreativeItem(ID::mFluidEjector,0);
	Item::addCreativeItem(ID::mFluidEjectorUp,0);
	Item::addCreativeItem(ID::mFluidEjectorDown,0);
	Item::addCreativeItem(ID::mFluidEjectorEast,0);
	Item::addCreativeItem(ID::mFluidEjectorWest,0);
	Item::addCreativeItem(ID::mFluidEjectorNorth,0);
	Item::addCreativeItem(ID::mFluidEjectorSouth,0);
	Item::addCreativeItem(ID::mPulling,0);
	Item::addCreativeItem(ID::mPullingUp,0);
	Item::addCreativeItem(ID::mPullingDown,0);
	Item::addCreativeItem(ID::mPullingEast,0);
	Item::addCreativeItem(ID::mPullingWest,0);
	Item::addCreativeItem(ID::mPullingNorth,0);
	Item::addCreativeItem(ID::mPullingSouth,0);
	Item::addCreativeItem(ID::mFluidPulling,0);
	Item::addCreativeItem(ID::mFluidPullingUp,0);
	Item::addCreativeItem(ID::mFluidPullingDown,0);
	Item::addCreativeItem(ID::mFluidPullingEast,0);
	Item::addCreativeItem(ID::mFluidPullingWest,0);
	Item::addCreativeItem(ID::mFluidPullingNorth,0);
	Item::addCreativeItem(ID::mFluidPullingSouth,0);
	Item::addCreativeItem(ID::mTransformer,0);
	Item::addCreativeItem(ID::mRedstoneInverter,0);
	Item::addCreativeItem(ID::mOverclocker,0);
	Item::addCreativeItem(ID::mEnergyStorage,0);
}
void Items::initICItems()
{
	registerItem(ID::mCircuit,"ic.circuit","icpe_circuit",0);
	registerItem(ID::mAdvancedCircuit,"ic.circuit.advanced","icpe_advanced_circuit",0);
	registerItem(ID::mElectricMotor,"ic.electricmotor","icpe_electric_motor",0);
	registerItem(ID::mPowerUnitSmall,"ic.power.unit.small","icpe_small_power_unit",0);
	registerItem(ID::mCoil,"ic.coil","icpe_coil",0);
	registerItem(ID::mICCoin,"ic.coin","icpe_ic_coin",0);
	registerItem(ID::mScrap,"ic.scrap","icpe_scrap",0);
	registerItem(ID::mSlag,"ic.slag","icpe_slag",0);
	registerItem(ID::mTinIngot,"ic.ingot.tin","icpe_tin",0);
	registerItem(ID::mSteelIngot,"ic.ingot.steel","icpe_steel",0);
	registerItem(ID::mCopperIngot,"ic.ingot.copper","icpe_copper",0);
	registerItem(ID::mLeadIngot,"ic.ingot.lead","icpe_iclead",0);
	registerItem(ID::mAlloyIngot,"ic.ingot.alloy","icpe_alloy",0);
	registerItem(ID::mBronzeIngot,"ic.ingot.bronze","icpe_bronze",0);
	registerItem(ID::mBronzePlate,"ic.plate.bronze","icpe_pl_bronze",0);
	registerItem(ID::mCopperPlate,"ic.plate.copper","icpe_pl_copper",0);
	registerItem(ID::mGoldPlate,"ic.plate.gold","icpe_pl_gold",0);
	registerItem(ID::mIronPlate,"ic.plate.iron","icpe_pl_iron",0);
	registerItem(ID::mLapisPlate,"ic.plate.lapis","icpe_pl_lapis",0);
	registerItem(ID::mLeadPlate,"ic.plate.lead","icpe_pl_lead",0);
	registerItem(ID::mObsidianPlate,"ic.plate.obsidian","icpe_pl_obsidian",0);
	registerItem(ID::mSteelPlate,"ic.plate.steel","icpe_pl_steel",0);
	registerItem(ID::mTinPlate,"ic.plate.tin","icpe_pl_tin",0);
	registerItem(ID::mDenseBronzePlate,"ic.plate.dense.bronze","icpe_dense_bronze",0);
	registerItem(ID::mDenseCopperPlate,"ic.plate.dense.copper","icpe_dense_copper",0);
	registerItem(ID::mDenseGoldPlate,"ic.plate.dense.gold","icpe_dense_gold",0);
	registerItem(ID::mDenseIronPlate,"ic.plate.dense.iron","icpe_dense_iron",0);
	registerItem(ID::mDenseLapisPlate,"ic.plate.dense.lapis","icpe_dense_lapis",0);
	registerItem(ID::mDenseLeadPlate,"ic.plate.dense.lead","icpe_dense_lead",0);
	registerItem(ID::mDenseObsidianPlate,"ic.plate.dense.obsidian","icpe_dense_obsidian",0);
	registerItem(ID::mDenseSteelPlate,"ic.plate.dense.steel","icpe_dense_steel",0);
	registerItem(ID::mDenseTinPlate,"ic.plate.dense.tin","icpe_dense_tin",0);
	registerItem(ID::mBronzeDust,"ic.dust.bronze","icpe_du_bronze",0);
	registerItem(ID::mClayDust,"ic.dust.clay","icpe_du_clay",0);
	registerItem(ID::mCoalDust,"ic.dust.coal","icpe_du_coal",0);
	registerItem(ID::mCoalFuelDust,"ic.dust.coal_fuel","icpe_du_coal_fuel",0);
	registerItem(ID::mCopperDust,"ic.dust.copper","icpe_du_copper",0);
	registerItem(ID::mDiamondDust,"ic.dust.diamond","icpe_du_diamond",0);
	registerItem(ID::mEnergiumDust,"ic.dust.energium","icpe_du_energium",0);
	registerItem(ID::mGoldDust,"ic.dust.gold","icpe_du_gold",0);
	registerItem(ID::mIronDust,"ic.dust.iron","icpe_du_iron",0);
	registerItem(ID::mLapisDust,"ic.dust.lapis","icpe_du_lapis",0);
	registerItem(ID::mLeadDust,"ic.dust.lead","icpe_du_lead",0);
	registerItem(ID::mLithiumDust,"ic.dust.lithium","icpe_du_lithium",0);
	registerItem(ID::mObsidianDust,"ic.dust.obsidian","icpe_du_obsidian",0);
	registerItem(ID::mSiliconDioxideDust,"ic.dust.silicon_dioxide","icpe_du_silicon_dioxide",0);
	registerItem(ID::mSilverDust,"ic.dust.silver","icpe_du_silver",0);
	registerItem(ID::mStoneDust,"ic.dust.stone","icpe_du_stone",0);
	registerItem(ID::mSulfurDust,"ic.dust.sulfur","icpe_du_sulfur",0);
	registerItem(ID::mTinDust,"ic.dust.tin","icpe_du_tin",0);
	registerItem(ID::mSmallBronzeDust,"ic.dust.small.bronze","icpe_small_du_bronze",0);
	registerItem(ID::mSmallCopperDust,"ic.dust.small.copper","icpe_small_du_copper",0);
	registerItem(ID::mSmallGoldDust,"ic.dust.small.gold","icpe_small_du_gold",0);
	registerItem(ID::mSmallIronDust,"ic.dust.small.iron","icpe_small_du_iron",0);
	registerItem(ID::mSmallLapisDust,"ic.dust.small.lapis","icpe_small_du_lapis",0);
	registerItem(ID::mSmallLeadDust,"ic.dust.small.lead","icpe_small_du_lead",0);
	registerItem(ID::mSmallObsidianDust,"ic.dust.small.obsidian","icpe_small_du_obsidian",0);
	registerItem(ID::mSmallLithiumDust,"ic.dust.small.lithium","icpe_small_du_lithium",0);
	registerItem(ID::mSmallSilverDust,"ic.dust.small.silver","icpe_small_du_silver",0);
	registerItem(ID::mSmallSulfurDust,"ic.dust.small.sulfur","icpe_small_du_sulfur",0);
	registerItem(ID::mSmallTinDust,"ic.dust.small.tin","icpe_small_du_tin",0);
	registerItem(ID::mBlankTFBP,"ic.tfbp.blank","icpe_tfbp_blank",0);
	registerItem(ID::mChillingTFBP,"ic.tfbp.chilling","icpe_tfbp_chilling",0);
	registerItem(ID::mCultivationTFBP,"ic.tfbp.cultivation","icpe_tfbp_cultivation",0);
	registerItem(ID::mDesertificationTFBP,"ic.tfbp.desertification","icpe_tfbp_desertification",0);
	registerItem(ID::mFlatificationTFBP,"ic.tfbp.flatification","icpe_tfbp_flatification",0);
	registerItem(ID::mIrrigationTFBP,"ic.tfbp.irrigation","icpe_tfbp_irrigation",0);
	registerItem(ID::mMushroomTFBP,"ic.tfbp.mushroom","icpe_tfbp_mushroom",0);
	registerItem(ID::mCrushedCopper,"ic.crushed.copper","icpe_cr_copper",0);
	registerItem(ID::mCrushedGold,"ic.crushed.gold","icpe_cr_gold",0);
	registerItem(ID::mCrushedIron,"ic.crushed.iron","icpe_cr_iron",0);
	registerItem(ID::mCrushedLead,"ic.crushed.lead","icpe_cr_lead",0);
	registerItem(ID::mCrushedSilver,"ic.crushed.silver","icpe_cr_silver",0);
	registerItem(ID::mCrushedTin,"ic.crushed.tin","icpe_cr_tin",0);
	registerItem(ID::mCrushedUranium,"ic.crushed.uranium","icpe_pu_uranium",0);
	registerItem(ID::mPurifiedCopper,"ic.purified.copper","icpe_pu_copper",0);
	registerItem(ID::mPurifiedGold,"ic.purified.gold","icpe_pu_gold",0);
	registerItem(ID::mPurifiedIron,"ic.purified.iron","icpe_pu_iron",0);
	registerItem(ID::mPurifiedLead,"ic.purified.lead","icpe_pu_lead",0);
	registerItem(ID::mPurifiedSilver,"ic.purified.silver","icpe_pu_silver",0);
	registerItem(ID::mPurifiedTin,"ic.purified.tin","icpe_pu_tin",0);
	registerItem(ID::mPurifiedUranium,"ic.purified.uranium","icpe_pu_uranium",0);
	registerItem(ID::mCasingBronze,"ic.casing.bronze","icpe_ca_bronze",0);
	registerItem(ID::mCasingCopper,"ic.casing.copper","icpe_ca_copper",0);
	registerItem(ID::mCasingGold,"ic.casing.gold","icpe_ca_gold",0);
	registerItem(ID::mCasingIron,"ic.casing.iron","icpe_ca_iron",0);
	registerItem(ID::mCasingLead,"ic.casing.lead","icpe_ca_lead",0);
	registerItem(ID::mCasingSteel,"ic.casing.steel","icpe_ca_steel",0);
	registerItem(ID::mCasingTin,"ic.casing.tin","icpe_ca_tin",0);
	registerItem(ID::mEjector,"ic.ejector","icpe_ejector",0);
	registerItem(ID::mEjectorUp,"ic.ejector.up","icpe_ejector_up",0);
	registerItem(ID::mEjectorDown,"ic.ejector.down","icpe_ejector_down",0);
	registerItem(ID::mEjectorWest,"ic.ejector.west","icpe_ejector_west",0);
	registerItem(ID::mEjectorNorth,"ic.ejector.north","icpe_ejector_north",0);
	registerItem(ID::mEjectorSouth,"ic.ejector.south","icpe_ejector_south",0);
	registerItem(ID::mEjectorEast,"ic.ejector.east","icpe_ejector_east",0);
	registerItem(ID::mFluidEjector,"ic.ejector.fluid","icpe_fluid_ejector",0);
	registerItem(ID::mFluidEjectorUp,"ic.ejector.fluid.up","icpe_fluid_ejector_up",0);
	registerItem(ID::mFluidEjectorDown,"ic.ejector.fluid.down","icpe_fluid_ejector_down",0);
	registerItem(ID::mFluidEjectorWest,"ic.ejector.fluid.west","icpe_fluid_ejector_west",0);
	registerItem(ID::mFluidEjectorNorth,"ic.ejector.fluid.north","icpe_fluid_ejector_north",0);
	registerItem(ID::mFluidEjectorSouth,"ic.ejector.fluid.south","icpe_fluid_ejector_south",0);
	registerItem(ID::mFluidEjectorEast,"ic.ejector.fluid.east","icpe_fluid_ejector_east",0);
	registerItem(ID::mFluidPulling,"ic.pulling.fluid","icpe_fluid_pulling",0);
	registerItem(ID::mFluidPullingUp,"ic.pulling.fluid.up","icpe_fluid_pulling_up",0);
	registerItem(ID::mFluidPullingDown,"ic.pulling.fluid.down","icpe_fluid_pulling_down",0);
	registerItem(ID::mFluidPullingWest,"ic.pulling.fluid.west","icpe_fluid_pulling_west",0);
	registerItem(ID::mFluidPullingNorth,"ic.pulling.fluid.north","icpe_fluid_pulling_north",0);
	registerItem(ID::mFluidPullingSouth,"ic.pulling.fluid.south","icpe_fluid_pulling_south",0);
	registerItem(ID::mFluidPullingEast,"ic.pulling.fluid.east","icpe_fluid_pulling_east",0);
	registerItem(ID::mPulling,"ic.pulling","icpe_pulling",0);
	registerItem(ID::mPullingUp,"ic.pulling.up","icpe_pulling_up",0);
	registerItem(ID::mPullingDown,"ic.pulling.down","icpe_pulling_down",0);
	registerItem(ID::mPullingWest,"ic.pulling.west","icpe_pulling_west",0);
	registerItem(ID::mPullingNorth,"ic.pulling.north","icpe_pulling_north",0);
	registerItem(ID::mPullingSouth,"ic.pulling.south","icpe_pulling_south",0);
	registerItem(ID::mPullingEast,"ic.pulling.east","icpe_pulling_east",0);
	registerItem(ID::mTransformer,"ic.transformer","icpe_transformer",0);
	registerItem(ID::mRedstoneInverter,"ic.redstone_inverter","icpe_redstone_inverter",0);
	registerItem(ID::mOverclocker,"ic.overclocker","icpe_overclocker",0);
	registerItem(ID::mEnergyStorage,"ic.energy_storage","icpe_energy_storage",0);
	
	Item::mItems[ID::mPainterMagenta]=new PainterItem("ic.painter.magenta",ID::mPainterMagenta-0x100,"icpe_painter_magenta");
	Item::mItems[ID::mPainterPurple]=new PainterItem("ic.painter.purple",ID::mPainterPurple-0x100,"icpe_painter_purple");
	Item::mItems[ID::mPainterBrown]=new PainterItem("ic.painter.brown",ID::mPainterBrown-0x100,"icpe_painter_brown");
	Item::mItems[ID::mPainterCyan]=new PainterItem("ic.painter.cyan",ID::mPainterCyan-0x100,"icpe_painter_cyan");
	Item::mItems[ID::mPainterLime]=new PainterItem("ic.painter.lime",ID::mPainterLime-0x100,"icpe_painter_lime");
	Item::mItems[ID::mPainterLightGray]=new PainterItem("ic.painter.light_gray",ID::mPainterLightGray-0x100,"icpe_painter_light_gray");
	Item::mItems[ID::mPainterLightBlue]=new PainterItem("ic.painter.light_blue",ID::mPainterLightBlue-0x100,"icpe_painter_light_blue");
	Item::mItems[ID::mPainterRed]=new PainterItem("ic.painter.red",ID::mPainterRed-0x100,"icpe_painter_red");
	Item::mItems[ID::mPainterYellow]=new PainterItem("ic.painter.yellow",ID::mPainterYellow-0x100,"icpe_painter_yellow");
	Item::mItems[ID::mPainterGray]=new PainterItem("ic.painter.gray",ID::mPainterGray-0x100,"icpe_painter_gray");
	Item::mItems[ID::mPainterWhite]=new PainterItem("ic.painter.white",ID::mPainterWhite-0x100,"icpe_painter");
	Item::mItems[ID::mPainterPink]=new PainterItem("ic.painter.pink",ID::mPainterPink-0x100,"icpe_painter_pink");
	Item::mItems[ID::mPainterGreen]=new PainterItem("ic.painter.green",ID::mPainterGreen-0x100,"icpe_painter_green");
	Item::mItems[ID::mPainterOrange]=new PainterItem("ic.painter.orange",ID::mPainterOrange-0x100,"icpe_painter_orange");
	Item::mItems[ID::mPainterBlue]=new PainterItem("ic.painter.blue",ID::mPainterBlue-0x100,"icpe_painter_blue");
	Item::mItems[ID::mPainterBlack]=new PainterItem("ic.painter.black",ID::mPainterBlack-0x100,"icpe_painter_black");
	Item::mItems[ID::mPainter]=new EmptyPainterItem();
	Item::mItems[ID::mSingleUseBattery]=new SingleUseBatteryItem();
	Item::mItems[ID::mChainsaw]=new ChainsawItem();
	Item::mItems[ID::mElectricHoe]=new ElectricHoeItem();
	Item::mItems[ID::mElectricTreeTap]=new ElectricTreeTapItem();
	Item::mItems[ID::mForgeHammer]=new ForgeHammerItem();
	Item::mItems[ID::mRubber]=new RubberItem();
	Item::mItems[ID::mResin]=new ResinItem();
	Item::mItems[ID::mTreeTap]=new TreeTapItem();
	Item::mItems[ID::mBronzeShovel]=new BronzeShovelItem();
	Item::mItems[ID::mBronzeHoe]=new BronzeHoeItem();
	Item::mItems[ID::mBronzeSword]=new BronzeSwordItem();
	Item::mItems[ID::mBronzePickAxe]=new BronzePickAxeItem();
	Item::mItems[ID::mBronzeAxe]=new BronzeAxeItem();
	Item::mItems[ID::mTinCable0]=new CableItem("ic.cable.tin.0",ID::mTinCable0-0x100,"icpe_tin_cable",0);
	Item::mItems[ID::mTinCable1]=new CableItem("ic.cable.tin.1",ID::mTinCable1-0x100,"icpe_tin_cable",1);
	Item::mItems[ID::mIronCable0]=new CableItem("ic.cable.iron.0",ID::mIronCable0-0x100,"icpe_iron_cable",0);
	Item::mItems[ID::mIronCable1]=new CableItem("ic.cable.iron.1",ID::mIronCable1-0x100,"icpe_iron_cable",1);
	Item::mItems[ID::mIronCable2]=new CableItem("ic.cable.iron.2",ID::mIronCable2-0x100,"icpe_iron_cable",2);
	Item::mItems[ID::mIronCable3]=new CableItem("ic.cable.iron.3",ID::mIronCable3-0x100,"icpe_iron_cable",3);
	Item::mItems[ID::mGoldCable0]=new CableItem("ic.cable.gold.0",ID::mGoldCable0-0x100,"icpe_gold_cable",0);
	Item::mItems[ID::mGoldCable1]=new CableItem("ic.cable.gold.1",ID::mGoldCable1-0x100,"icpe_gold_cable",1);
	Item::mItems[ID::mGoldCable2]=new CableItem("ic.cable.gold.2",ID::mGoldCable2-0x100,"icpe_gold_cable",2);
	Item::mItems[ID::mCopperCable0]=new CableItem("ic.cable.copper.0",ID::mCopperCable0-0x100,"icpe_copper_cable",0);
	Item::mItems[ID::mCopperCable1]=new CableItem("ic.cable.copper.1",ID::mCopperCable1-0x100,"icpe_copper_cable",1);
	Item::mItems[ID::mDetectorCable]=new CableItem("ic.cable.detector",ID::mDetectorCable-0x100,"icpe_detector_cable",0);
	Item::mItems[ID::mGlassCable]=new CableItem("ic.cable.glass",ID::mGlassCable-0x100,"icpe_glass_cable",0);
	Item::mItems[ID::mSplitterCable]=new CableItem("ic.cable.splitter",ID::mSplitterCable-0x100,"icpe_splitter_cable",0);
}
void Items::initICBlockItems()
{
	Item::mItems[IC::Blocks::ID::mMetal]=new AuxDataBlockItem("ic.metal",IC::Blocks::ID::mMetal-0x100,Block::mBlocks[IC::Blocks::ID::mMetal]);
	Item::mItems[IC::Blocks::ID::mIronFence]=new BlockItem("ic.ironfence",IC::Blocks::ID::mIronFence-0x100);
	Item::mItems[IC::Blocks::ID::mFurnace]=new AuxDataBlockItem("ic.ironfurnace",IC::Blocks::ID::mFurnace-0x100,Block::mBlocks[IC::Blocks::ID::mFurnace]);
	Item::mItems[IC::Blocks::ID::mCable]=new AuxDataBlockItem("ic.cable",IC::Blocks::ID::mCable-0x100,Block::mBlocks[IC::Blocks::ID::mCable]);
	Item::mItems[IC::Blocks::ID::mRubberLeaves]=new BlockItem("ic.rubber.leaves",IC::Blocks::ID::mRubberLeaves-0x100);
	Item::mItems[IC::Blocks::ID::mResin]=new AuxDataBlockItem("ic.resin",IC::Blocks::ID::mResin-0x100,Block::mBlocks[IC::Blocks::ID::mResin]);
	Item::mItems[IC::Blocks::ID::mRubberWood]=new AuxDataBlockItem("ic.rubber.wood",IC::Blocks::ID::mRubberWood-0x100,Block::mBlocks[IC::Blocks::ID::mRubberWood]);
	Item::mItems[IC::Blocks::ID::mITNT]=new BlockItem("ic.itnt",IC::Blocks::ID::mITNT-0x100);
	Item::mItems[IC::Blocks::ID::mRubberSapling]=new BlockItem("ic.rubber.sapling",IC::Blocks::ID::mRubberSapling-0x100);
	Item::mItems[IC::Blocks::ID::mOre]=new AuxDataBlockItem("ic.ore.tin",IC::Blocks::ID::mOre-0x100,Block::mBlocks[IC::Blocks::ID::mOre]);
}
Items::Items(std::string const&name,short id):Item(name,id)
{
	LOG_P("Item defined:name="+name+",id="+Util::toString(id+0x100));
	
	mICItems[id]=true;
}
bool Items::isBatteryItem()const
{
	return false;
}
unsigned int Items::getEU(ItemInstance const&)const
{
	return 0;
}
unsigned int Items::getMaxEU()const
{
	return 0;
}
void Items::registerItem(short id,std::string const&name,std::string const&tex,int a)
{
	Item::mItems[id]=new ICDefaultItem(name,id-0x100,tex,a);
}
void Items::registerItem(short id,std::string const&name,TextureUVCoordinateSet const&tex)
{
	Item::mItems[id]=new ICDefaultItem(name,id-0x100,tex);
}
}
