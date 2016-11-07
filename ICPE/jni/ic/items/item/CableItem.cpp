#include "CableItem.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/client/resources/I18n.h"

#include "ic/blocks/Blocks.h"

CableItem::CableItem():IC::Items("ic.cable.tin.0",IC::Items::ID::mCable-256)
{
	setCategory(CreativeItemCategory::ITEMS);
	setStackedByData(true);
	
	tinTextures[0]=getTextureUVCoordinateSet("tin_cable",0);
	tinTextures[1]=getTextureUVCoordinateSet("tin_cable",1);
	ironTextures[0]=getTextureUVCoordinateSet("iron_cable",0);
	ironTextures[1]=getTextureUVCoordinateSet("iron_cable",1);
	ironTextures[2]=getTextureUVCoordinateSet("iron_cable",2);
	ironTextures[3]=getTextureUVCoordinateSet("iron_cable",3);
	goldTextures[0]=getTextureUVCoordinateSet("gold_cable",0);
	goldTextures[1]=getTextureUVCoordinateSet("gold_cable",1);
	goldTextures[2]=getTextureUVCoordinateSet("gold_cable",2);
	copperTextures[0]=getTextureUVCoordinateSet("copper_cable",0);
	copperTextures[1]=getTextureUVCoordinateSet("copper_cable",1);
	utilTextures[0]=getTextureUVCoordinateSet("detector_cable",0);
	utilTextures[1]=getTextureUVCoordinateSet("glass_cable",0);
	utilTextures[2]=getTextureUVCoordinateSet("splitter_cable",0);
}
const std::string CableItem::buildDescriptionName(const ItemInstance&i) const
{
	switch(i.aux)
	{
	case 0:
	default:
		return I18n::get("ic.cable.tin.0");
	case 1:
		return I18n::get("ic.cable.tin.1");
	case 2:
		return I18n::get("ic.cable.iron.0");
	case 3:
		return I18n::get("ic.cable.iron.1");
	case 4:
		return I18n::get("ic.cable.iron.2");
	case 5:
		return I18n::get("ic.cable.iron.3");
	case 6:
		return I18n::get("ic.cable.gold.0");
	case 7:
		return I18n::get("ic.cable.gold.1");
	case 8:
		return I18n::get("ic.cable.gold.2");
	case 9:
		return I18n::get("ic.cable.copper.0");
	case 10:
		return I18n::get("ic.cable.copper.1");
	case 11:
		return I18n::get("ic.cable.detector");
	case 12:
		return I18n::get("ic.cable.glass");
	case 13:
		return I18n::get("ic.cable.splitter");
	}
}
const TextureUVCoordinateSet& CableItem::getIcon(int aux, int, bool) const
{
	switch(aux)
	{
	case 0:
	default:
		return tinTextures[0];
	case 1:
		return tinTextures[1];
	case 2:
		return ironTextures[0];
	case 3:
		return ironTextures[1];
	case 4:
		return ironTextures[2];
	case 5:
		return ironTextures[3];
	case 6:
		return goldTextures[0];
	case 7:
		return goldTextures[1];
	case 8:
		return goldTextures[2];
	case 9:
		return copperTextures[0];
	case 10:
		return copperTextures[1];
	case 11:
		return utilTextures[0];
	case 12:
		return utilTextures[1];
	case 13:
		return utilTextures[2];
	}
}
const std::string CableItem::buildEffectDescriptionName(const ItemInstance&i) const
{
	switch(i.aux)
	{
	case 0:
	default:
		return "§7"+I18n::get("ic.cable.uninsulated")+"\n"+"32EU/t"+"\n"+"-0.025EU/m";
	case 1:
		return "§7"+I18n::get("ic.cable.insulated.1")+"\n"+"32EU/t"+"\n"+"-0.02EU/m";
	case 2:
		return "§7"+I18n::get("ic.cable.uninsulated")+"\n"+"2048EU/t"+"\n"+"-1EU/m";
	case 3:
		return "§7"+I18n::get("ic.cable.insulated.1")+"\n"+"2048EU/t"+"\n"+"-0.95EU/m";
	case 4:
		return "§7"+I18n::get("ic.cable.insulated.2")+"\n"+"2048EU/t"+"\n"+"-0.9EU/m";
	case 5:
		return "§7"+I18n::get("ic.cable.insulated.3")+"\n"+"2048EU/t"+"\n"+"-0.8EU/m";
	case 6:
		return "§7"+I18n::get("ic.cable.uninsulated")+"\n"+"512EU/t"+"\n"+"-0.5EU/m";
	case 7:
		return "§7"+I18n::get("ic.cable.insulated.1")+"\n"+"512EU/t"+"\n"+"-0.45EU/m";
	case 8:
		return "§7"+I18n::get("ic.cable.insulated.2")+"\n"+"512EU/t"+"\n"+"-0.4EU/m";
	case 9:
		return "§7"+I18n::get("ic.cable.uninsulated")+"\n"+"128EU/t"+"\n"+"-0.3EU/m";
	case 10:
		return "§7"+I18n::get("ic.cable.insulated.1")+"\n"+"128EU/t"+"\n"+"-0.2EU/m";
	case 11:
		return "§78192EU/t\n-0.025EU/m";
	case 12:
		return "§78192EU/t\n-0.025EU/m";
	case 13:
		return "§78192EU/t\n-0.025EU/m";
	}
}
bool CableItem::useOn(ItemInstance*instance, Player*p, int x, int y, int z, signed char side, float pixelx, float pixely, float pixelz)
{
	if(!p||!instance)return false;
	
	ItemInstance cableItem(IC::Blocks::ID::mCable,instance->count,instance->aux);
	cableItem.useOn(p,x,y,z,side,pixelx,pixely,pixelz);
	
	instance->count=cableItem.count;
	if(instance->count==0)
		instance->setNull();
	return true;
}
