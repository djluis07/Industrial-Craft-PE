#include "Items.h"

#include "mcpe/item/BlockItem.h"
#include "mcpe/item/AuxDataBlockItem.h"
#include "mcpe/block/Block.h"
#include "mcpe/client/resources/I18n.h"

#include "ic/blocks/Blocks.h"

#include "item/base/ICDefaultItem.h"
#include "item/battery/SingleUseBatteryItem.h"
#include "item/UraniumItem.h"
#include "item/IngotItem.h"
#include "item/RubberItem.h"
#include "item/TreeTapItem.h"
#include "item/CableItem.h"
#include "item/CircuitItem.h"
#include "item/PlateItem.h"
#include "item/BrokenItem.h"
#include "item/DustItem.h"
#include "item/ForgeHammerItem.h"
#include "item/ElectricTreeTapItem.h"
#include "item/ElectricHoeItem.h"
#include "item/TFBPItem.h"
#include "item/ChainsawItem.h"

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
	/*Item::addCreativeItem(IC::Blocks::ID::mOre,0);
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
	Item::addCreativeItem(ID::mIngot,0);
	Item::addCreativeItem(ID::mIngot,1);
	Item::addCreativeItem(ID::mIngot,2);
	Item::addCreativeItem(ID::mIngot,3);
	Item::addCreativeItem(ID::mIngot,4);
	Item::addCreativeItem(ID::mIngot,5);
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
	Item::addCreativeItem(ID::mCircuit,0);
	Item::addCreativeItem(ID::mCircuit,1);
	Item::addCreativeItem(ID::mPlate,0);
	Item::addCreativeItem(ID::mPlate,1);
	Item::addCreativeItem(ID::mPlate,2);
	Item::addCreativeItem(ID::mPlate,3);
	Item::addCreativeItem(ID::mPlate,4);
	Item::addCreativeItem(ID::mPlate,5);
	Item::addCreativeItem(ID::mPlate,6);
	Item::addCreativeItem(ID::mPlate,7);
	Item::addCreativeItem(ID::mPlate,8);
	Item::addCreativeItem(ID::mPlate,9);
	Item::addCreativeItem(ID::mPlate,10);
	Item::addCreativeItem(ID::mPlate,11);
	Item::addCreativeItem(ID::mPlate,12);
	Item::addCreativeItem(ID::mPlate,13);
	Item::addCreativeItem(ID::mPlate,14);
	Item::addCreativeItem(ID::mPlate,15);
	Item::addCreativeItem(ID::mPlate,16);
	Item::addCreativeItem(ID::mPlate,17);
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
	Item::addCreativeItem(ID::mDust,0);
	Item::addCreativeItem(ID::mDust,1);
	Item::addCreativeItem(ID::mDust,2);
	Item::addCreativeItem(ID::mDust,3);
	Item::addCreativeItem(ID::mDust,4);
	Item::addCreativeItem(ID::mDust,5);
	Item::addCreativeItem(ID::mDust,6);
	Item::addCreativeItem(ID::mDust,7);
	Item::addCreativeItem(ID::mDust,8);
	Item::addCreativeItem(ID::mDust,9);
	Item::addCreativeItem(ID::mDust,10);
	Item::addCreativeItem(ID::mDust,11);
	Item::addCreativeItem(ID::mDust,12);
	Item::addCreativeItem(ID::mDust,13);
	Item::addCreativeItem(ID::mDust,14);
	Item::addCreativeItem(ID::mDust,15);
	Item::addCreativeItem(ID::mDust,16);
	Item::addCreativeItem(ID::mDust,17);
	Item::addCreativeItem(ID::mDust,18);
	Item::addCreativeItem(ID::mDust,19);
	Item::addCreativeItem(ID::mDust,20);
	Item::addCreativeItem(ID::mDust,21);
	Item::addCreativeItem(ID::mDust,22);
	Item::addCreativeItem(ID::mDust,23);
	Item::addCreativeItem(ID::mDust,24);
	Item::addCreativeItem(ID::mDust,25);
	Item::addCreativeItem(ID::mDust,26);
	Item::addCreativeItem(ID::mDust,27);
	Item::addCreativeItem(ID::mDust,28);
	Item::addCreativeItem(ID::mScrap,0);
	Item::addCreativeItem(ID::mSlag,0);
	Item::addCreativeItem(ID::mAlloyPlate,0);
	Item::addCreativeItem(ID::mForgeHammer,0);
	Item::addCreativeItem(ID::mElectricTreeTap,0);
	Item::addCreativeItem(ID::mElectricTreeTap,200);
	Item::addCreativeItem(ID::mElectricHoe,0);
	Item::addCreativeItem(ID::mElectricHoe,500);
	Item::addCreativeItem(ID::mChainsaw,0);
	Item::addCreativeItem(ID::mChainsaw,500);
	Item::addCreativeItem(ID::mTFBP,0);
	Item::addCreativeItem(ID::mTFBP,1);
	Item::addCreativeItem(ID::mTFBP,2);
	Item::addCreativeItem(ID::mTFBP,3);
	Item::addCreativeItem(ID::mTFBP,4);
	Item::addCreativeItem(ID::mTFBP,5);
	Item::addCreativeItem(ID::mTFBP,6);
	Item::addCreativeItem(ID::mCoil,0);
	Item::addCreativeItem(ID::mPowerUnitSmall,0);
	Item::addCreativeItem(ID::mElectricMotor,0);
	Item::addCreativeItem(ID::mSingleUseBattery,0);*/
}
void Items::initICItems()
{
	//registerCommonItem("ic.electricmotor",ID::mElectricMotor,"electric_motor",0,CreativeItemCategory::ITEMS);
	registerCommonItem("guide_book",ID::mGuideBook,"alloy",0,CreativeItemCategory::ITEMS);
	
	/*Item::mItems[ID::mElectricMotor]=new ICDefaultItem("ic.electricmotor",ID::mElectricMotor-0x100,"electric_motor",0);
	Item::mItems[ID::mPowerUnitSmall]=new ICDefaultItem("ic.power.unit.small",ID::mPowerUnitSmall-0x100,"small_power_unit",0);
	Item::mItems[ID::mCoil]=new ICDefaultItem("ic.coil",ID::mCoil-0x100,"coil",0);
	Item::mItems[ID::mScrap]=new ICDefaultItem("ic.scrap",ID::mScrap-0x100,"scrap",0);
	Item::mItems[ID::mSlag]=new ICDefaultItem("ic.slag",ID::mSlag-0x100,"slag",0);
	Item::mItems[ID::mAlloyPlate]=new ICDefaultItem("ic.plate.alloy",ID::mAlloyPlate-0x100,"apple",0);
	
	Item::mItems[ID::mSingleUseBattery]=new SingleUseBatteryItem();
	Item::mItems[ID::mChainsaw]=new ChainsawItem();
	Item::mItems[ID::mElectricHoe]=new ElectricHoeItem();
	Item::mItems[ID::mTFBP]=new TFBPItem();
	Item::mItems[ID::mElectricTreeTap]=new ElectricTreeTapItem();
	Item::mItems[ID::mForgeHammer]=new ForgeHammerItem();
	Item::mItems[ID::mDust]=new DustItem();
	Item::mItems[ID::mBroken]=new BrokenItem();
	Item::mItems[ID::mUranium]=new UraniumItem();
	Item::mItems[ID::mIngot]=new IngotItem();
	Item::mItems[ID::mRubber]=new RubberItem();
	Item::mItems[ID::mTreeTap]=new TreeTapItem();
	Item::mItems[ID::mCable]=new CableItem();
	Item::mItems[ID::mCircuit]=new CircuitItem();
	Item::mItems[ID::mPlate]=new PlateItem();*/
}
void Items::initICBlockItems()
{
	/*Item::mItems[IC::Blocks::ID::mIronFence]=new BlockItem("ic.ironfence",IC::Blocks::ID::mIronFence-0x100);
	Item::mItems[IC::Blocks::ID::mIronFurnace]=new AuxDataBlockItem("ic.ironfurnace",IC::Blocks::ID::mIronFurnace-0x100,Block::mBlocks[IC::Blocks::ID::mIronFurnace]);;
	Item::mItems[IC::Blocks::ID::mCable]=new AuxDataBlockItem("ic.cable",IC::Blocks::ID::mCable-0x100,Block::mBlocks[IC::Blocks::ID::mCable]);
	Item::mItems[IC::Blocks::ID::mRubberLeaves]=new BlockItem("ic.rubber.leaves",IC::Blocks::ID::mRubberLeaves-0x100);
	Item::mItems[IC::Blocks::ID::mResin]=new AuxDataBlockItem("ic.resin",IC::Blocks::ID::mResin-0x100,Block::mBlocks[IC::Blocks::ID::mResin]);
	Item::mItems[IC::Blocks::ID::mRubberWood]=new AuxDataBlockItem("ic.rubber.wood",IC::Blocks::ID::mRubberWood-0x100,Block::mBlocks[IC::Blocks::ID::mRubberWood]);
	Item::mItems[IC::Blocks::ID::mITNT]=new BlockItem("ic.itnt",IC::Blocks::ID::mITNT-0x100);
	Item::mItems[IC::Blocks::ID::mRubberSapling]=new BlockItem("ic.rubber.sapling",IC::Blocks::ID::mRubberSapling-0x100);
	Item::mItems[IC::Blocks::ID::mOre]=new AuxDataBlockItem("ic.ore.tin",IC::Blocks::ID::mOre-0x100,Block::mBlocks[IC::Blocks::ID::mOre]);
*/}
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
void Items::registerCommonItem(std::string const&name,short id,std::string const&icon,int iconIndex,CreativeItemCategory category)
{
	Item::mItems[id]=new Item(name,id-256);
	Item::mItems[id]->setIcon(icon,iconIndex);
	Item::mItems[id]->setCategory(category);
}
}
