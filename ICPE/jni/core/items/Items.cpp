#include "Items.h"

#include "mcpe/item/BlockItem.h"
#include "mcpe/item/AuxDataBlockItem.h"
#include "mcpe/block/Block.h"
#include "mcpe/client/resources/I18n.h"

#include "blocks/Blocks.h"

#include "item/base/ICDefaultItem.h"
#include "item/battery/SingleUseBatteryItem.h"
#include "item/UraniumItem.h"
#include "item/RubberItem.h"
#include "item/TreeTapItem.h"
#include "item/CableItem.h"
#include "item/BrokenItem.h"
#include "item/ForgeHammerItem.h"
#include "item/ElectricTreeTapItem.h"
#include "item/ElectricHoeItem.h"
#include "item/ChainsawItem.h"
#include "item/GuideBookItem.h"

bool IC::Items::mICItems[4096];

namespace IC
{
void Items::initICAllItems()
{
	initICItems();
	initICBlockItems();
}
void Items::addICCreativeItems()
{
	Item::addCreativeItem(ID::mGuideBook,0);
	Item::addCreativeItem(IC::Blocks::ID::mOre,0);
	Item::addCreativeItem(IC::Blocks::ID::mOre,1);
	Item::addCreativeItem(IC::Blocks::ID::mOre,2);
	Item::addCreativeItem(IC::Blocks::ID::mOre,3);
	Item::addCreativeItem(IC::Blocks::ID::mRubberSapling,0);
	Item::addCreativeItem(IC::Blocks::ID::mITNT,0);
	Item::addCreativeItem(IC::Blocks::ID::mRubberWood,0);
	Item::addCreativeItem(IC::Blocks::ID::mRubberWood,1);
	Item::addCreativeItem(IC::Blocks::ID::mRubberWood,2);
	Item::addCreativeItem(IC::Blocks::ID::mRubberLeaves,0);
	Item::addCreativeItem(IC::Blocks::ID::mIronFence,0);
	Item::addCreativeItem(IC::Blocks::ID::mIronFurnace,0);
	
	Item::addCreativeItem(ID::mUranium,0);
	Item::addCreativeItem(ID::mUranium,1);
	Item::addCreativeItem(ID::mUranium,2);
	Item::addCreativeItem(ID::mUranium,3);
	Item::addCreativeItem(ID::mUranium,4);
	Item::addCreativeItem(ID::mUranium,5);
	Item::addCreativeItem(ID::mUranium,6);
	Item::addCreativeItem(ID::mUranium,7);
	Item::addCreativeItem(ID::mUranium,8);
	Item::addCreativeItem(ID::mUranium,9);
	Item::addCreativeItem(ID::mUranium,10);
	Item::addCreativeItem(ID::mUranium,11);
	Item::addCreativeItem(ID::mUranium,12);
	Item::addCreativeItem(ID::mUranium,13);
	Item::addCreativeItem(ID::mUranium,14);
	Item::addCreativeItem(ID::mUranium,15);
	Item::addCreativeItem(ID::mUranium,16);
	Item::addCreativeItem(ID::mRubber,0);
	Item::addCreativeItem(ID::mRubber,1);
	Item::addCreativeItem(ID::mTreeTap,0);
	Item::addCreativeItem(ID::mCable,0);
	Item::addCreativeItem(ID::mCable,1);
	Item::addCreativeItem(ID::mCable,2);
	Item::addCreativeItem(ID::mCable,3);
	Item::addCreativeItem(ID::mCable,4);
	Item::addCreativeItem(ID::mCable,5);
	Item::addCreativeItem(ID::mCable,6);
	Item::addCreativeItem(ID::mCable,7);
	Item::addCreativeItem(ID::mCable,8);
	Item::addCreativeItem(ID::mCable,9);
	Item::addCreativeItem(ID::mCable,10);
	Item::addCreativeItem(ID::mCable,11);
	Item::addCreativeItem(ID::mCable,12);
	Item::addCreativeItem(ID::mCable,13);
	Item::addCreativeItem(ID::mBroken,0);
	Item::addCreativeItem(ID::mBroken,1);
	Item::addCreativeItem(ID::mBroken,2);
	Item::addCreativeItem(ID::mBroken,3);
	Item::addCreativeItem(ID::mBroken,4);
	Item::addCreativeItem(ID::mBroken,5);
	Item::addCreativeItem(ID::mBroken,6);
	Item::addCreativeItem(ID::mBroken,7);
	Item::addCreativeItem(ID::mBroken,8);
	Item::addCreativeItem(ID::mBroken,9);
	Item::addCreativeItem(ID::mBroken,10);
	Item::addCreativeItem(ID::mBroken,11);
	Item::addCreativeItem(ID::mBroken,12);
	Item::addCreativeItem(ID::mBroken,13);
	Item::addCreativeItem(ID::mBroken,14);
	Item::addCreativeItem(ID::mBroken,15);
	Item::addCreativeItem(ID::mBroken,16);
	Item::addCreativeItem(ID::mBroken,17);
	Item::addCreativeItem(ID::mBroken,18);
	Item::addCreativeItem(ID::mBroken,19);
	Item::addCreativeItem(ID::mBroken,20);
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
	/*Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);*/
}
void Items::initICItems()
{
	registerItem(ID::mCircuit,"ic.circuit","icpe_circuit",0);
	registerItem(ID::mAdvancedCircuit,"ic.circuit.advanced","icpe_advanced_circuit",0);
	registerItem(ID::mElectricMotor,"ic.electricmotor","icpe_electric_motor",0);
	registerItem(ID::mPowerUnitSmall,"ic.power.unit.small","icpe_small_power_unit",0);
	registerItem(ID::mCoil,"ic.coil","icpe_coil",0);
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
	registerItem(ID::mSmallSilverDust,"ic.dust.small.sliver","icpe_small_du_silver",0);
	registerItem(ID::mSmallSulfurDust,"ic.dust.small.sulfur","icpe_small_du_sulfur",0);
	registerItem(ID::mSmallTinDust,"ic.dust.small.tin","icpe_small_du_tin",0);
	registerItem(ID::mBlankTFBP,"ic.tfbp.blank","icpe_tfbp_blank",0);
	registerItem(ID::mChillingTFBP,"ic.tfbp.chilling","icpe_tfbp_chilling",0);
	registerItem(ID::mCultivationTFBP,"ic.tfbp.cultivation","icpe_tfbp_cultivation",0);
	registerItem(ID::mDesertificationTFBP,"ic.tfbp.desertification","icpe_tfbp_desertification",0);
	registerItem(ID::mFlatificationTFBP,"ic.tfbp.flatfication","icpe_tfbp_flatification",0);
	registerItem(ID::mIrrigationTFBP,"ic.tfbp.irrigation","icpe_tfbp_irrigation",0);
	registerItem(ID::mMushroomTFBP,"ic.tfbp.mushroom","icpe_tfbp_mushroom",0);
	
	
	
	Item::mItems[ID::mGuideBook]=new GuideBookItem();
	Item::mItems[ID::mSingleUseBattery]=new SingleUseBatteryItem();
	Item::mItems[ID::mChainsaw]=new ChainsawItem();
	Item::mItems[ID::mElectricHoe]=new ElectricHoeItem();
	Item::mItems[ID::mElectricTreeTap]=new ElectricTreeTapItem();
	Item::mItems[ID::mForgeHammer]=new ForgeHammerItem();
	Item::mItems[ID::mBroken]=new BrokenItem();
	Item::mItems[ID::mUranium]=new UraniumItem();
	Item::mItems[ID::mRubber]=new RubberItem();
	Item::mItems[ID::mTreeTap]=new TreeTapItem();
	Item::mItems[ID::mCable]=new CableItem();
}
void Items::initICBlockItems()
{
	Item::mItems[IC::Blocks::ID::mIronFence]=new BlockItem("ic.ironfence",IC::Blocks::ID::mIronFence-0x100);
	Item::mItems[IC::Blocks::ID::mIronFurnace]=new AuxDataBlockItem("ic.ironfurnace",IC::Blocks::ID::mIronFurnace-0x100,Block::mBlocks[IC::Blocks::ID::mIronFurnace]);;
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
