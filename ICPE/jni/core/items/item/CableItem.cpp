#include "CableItem.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/client/resources/I18n.h"

#include "blocks/Blocks.h"

CableItem::CableItem(std::string const&name,short id,FullBlock const&b,std::string const&texture,int textaux):IC::Items(name,id)
{
	setCategory(CreativeItemCategory::ITEMS);
	setIcon(texture,textaux);
	placeBlock=b;
}
std::string CableItem::buildEffectDescriptionName(const ItemInstance&i) const
{
	switch(i.getId())
	{
	case ID::mTinCable0:
	default:
		return "§7"+I18n::get("ic.cable.uninsulated")+"\n"+"32EU/t"+"\n"+"-0.025EU/m";
	case ID::mTinCable1:
		return "§7"+I18n::get("ic.cable.insulated.1")+"\n"+"32EU/t"+"\n"+"-0.02EU/m";
	case ID::mIronCable0:
		return "§7"+I18n::get("ic.cable.uninsulated")+"\n"+"2048EU/t"+"\n"+"-1EU/m";
	case ID::mIronCable1:
		return "§7"+I18n::get("ic.cable.insulated.1")+"\n"+"2048EU/t"+"\n"+"-0.95EU/m";
	case ID::mIronCable2:
		return "§7"+I18n::get("ic.cable.insulated.2")+"\n"+"2048EU/t"+"\n"+"-0.9EU/m";
	case ID::mIronCable3:
		return "§7"+I18n::get("ic.cable.insulated.3")+"\n"+"2048EU/t"+"\n"+"-0.8EU/m";
	case ID::mGoldCable0:
		return "§7"+I18n::get("ic.cable.uninsulated")+"\n"+"512EU/t"+"\n"+"-0.5EU/m";
	case ID::mGoldCable1:
		return "§7"+I18n::get("ic.cable.insulated.1")+"\n"+"512EU/t"+"\n"+"-0.45EU/m";
	case ID::mGoldCable2:
		return "§7"+I18n::get("ic.cable.insulated.2")+"\n"+"512EU/t"+"\n"+"-0.4EU/m";
	case ID::mCopperCable0:
		return "§7"+I18n::get("ic.cable.uninsulated")+"\n"+"128EU/t"+"\n"+"-0.3EU/m";
	case ID::mCopperCable1:
		return "§7"+I18n::get("ic.cable.insulated.1")+"\n"+"128EU/t"+"\n"+"-0.2EU/m";
	case ID::mDetectorCable:
		return "§78192EU/t\n-0.025EU/m";
	case ID::mGlassCable:
		return "§78192EU/t\n-0.025EU/m";
	case ID::mSplitterCable:
		return "§78192EU/t\n-0.025EU/m";
	}
}
void CableItem::useOn(ItemInstance&instance, Entity&p, int x, int y, int z, signed char side, float pixelx, float pixely, float pixelz)
{
	ItemInstance cableItem(placeBlock.id.id,instance.count,placeBlock.aux);
	cableItem.useOn(p,x,y,z,side,pixelx,pixely,pixelz);
	
	instance.count=cableItem.count;
	if(instance.count==0)
		instance.setNull();
	return;
}
