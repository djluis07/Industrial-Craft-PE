#include "IronFurnaceScreen.h"

#include <math.h>

#include "mcpe/entity/player/Player.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/util/BlockPos.h"
#include "mcpe/client/resources/I18n.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/client/MinecraftClient.h"
#include "mcpe/client/gui/screen/ScreenChooser.h"
#include "mcpe/client/gui/GuiData.h"
#include "mcpe/client/gui/GuiElement.h"
#include "mcpe/item/ItemInstance.h"
#include "mcpe/client/gui/IntRectangle.h"

#include "blocks/blockentity/IronFurnaceBlockEntity.h"
#include "util/Log.h"
IronFurnaceScreen::IronFurnaceScreen(MinecraftClient&client,Player&p,BlockPos const&pos_):BaseContainerScreen(client,p.getRegion(),p,I18n::get("ic.ui.title.iron_furnace"))
{
	ironFurnace=(IronFurnaceBlockEntity*)source.getICBlockEntity(pos_);
	pos=pos_;
	block=p.getRegion().getBlock(pos_);
}
std::string IronFurnaceScreen::getScreenName()const
{
	return "ic_furnace_iron_screen";
}
std::string IronFurnaceScreen::getScreenNameW()const
{
	return "ic_furnace_iron_screen";
}
void IronFurnaceScreen::_buttonClicked(Button&b)
{
	BaseContainerScreen::_buttonClicked(b);
}
void IronFurnaceScreen::onInit()
{
	int width=mcClient->getGuiData()->getScreenWidth();
	int height=mcClient->getGuiData()->getScreenHeight();
	
	fireBackground_empty=std::make_shared<GuiElement>(false,false,0,0,0,0);
	fireBackground_empty->xPosition=width/2+7;
	fireBackground_empty->yPosition=height/2-10;
	fireBackground_empty->width=20;
	fireBackground_empty->height=20;
	fireBackground_empty->setBackground(mcClient,"textures/gui/spritesheet",{40,20,16,16},0,0);
	tabElementList.emplace_back(fireBackground_empty);
	
	fireBackground_filled=std::make_shared<GuiElement>(false,false,0,0,0,0);
	fireBackground_filled->xPosition=width/2+7;
	fireBackground_filled->yPosition=height/2-10;
	fireBackground_filled->width=20;
	fireBackground_filled->height=20;
	fireBackground_filled->setBackground(mcClient,"textures/gui/spritesheet",{56,20,16,16},0,0);
	tabElementList.emplace_back(fireBackground_filled);
	
	progress_empty=std::make_shared<GuiElement>(false,false,0,0,0,0);
	progress_empty->xPosition=35+width/2+((width/2-120)/2);
	progress_empty->yPosition=height/2-10;
	progress_empty->width=36;
	progress_empty->height=20;
	progress_empty->setBackground(mcClient,"textures/gui/spritesheet",{73,20,22,15},0,0);
	tabElementList.emplace_back(progress_empty);
	
	progress_filled=std::make_shared<GuiElement>(false,false,0,0,0,0);
	progress_filled->xPosition=35+width/2+((width/2-120)/2);
	progress_filled->yPosition=height/2-10;
	progress_filled->width=36;
	progress_filled->height=20;
	progress_filled->setBackground(mcClient,"textures/gui/spritesheet",{73,36,22,15},0,0);
	tabElementList.emplace_back(progress_filled);
}
void IronFurnaceScreen::onRender()
{
	setUIProgress();
}
void IronFurnaceScreen::onItemPanelChanged(IC::ItemPanel&p)
{
	ItemInstance item=p.getItem();
	if(!item.isNull())
		ironFurnace->setSlot(p.getID(),&item);
	else
		ironFurnace->setSlot(p.getID(),0);
}
void IronFurnaceScreen::onRegisterPanels(int w,int h)
{
	registerNewItemPanel(w/2,h/2-60,ItemInstance());
	registerNewItemPanel(w/2,h/2+25,ItemInstance());
	registerNewItemPanel(w-50,h/2-17,ItemInstance());
}
void IronFurnaceScreen::tick()
{
	BaseContainerScreen::tick();
	
	if(source.getBlock(pos)!=block)
	{
		mcClient->getScreenChooser()->schedulePopScreen(1);
		return;
	}
	for(int i=0;i<3;++i)
	{
		if(ironFurnace->getSlot(i))
			itemPanels[i]->item=*ironFurnace->getSlot(i);
	}
}
unsigned char IronFurnaceScreen::getAddItemToItemPanelCount(ItemInstance const&i,IC::ItemPanel&p)
{
	if(!ironFurnace->canPushInItem(p.getID(),i))
		return 0;
	return BaseContainerScreen::getAddItemToItemPanelCount(i,p);
}
void IronFurnaceScreen::setUIProgress()
{
	int progressWidth=(int)(((float)22)*(float)ironFurnace->getBurnProgress());
	int sizeWidth=(int)(((float)36)*(float)ironFurnace->getBurnProgress());
	progress_filled->setBackground(mcClient,"textures/gui/spritesheet",{73,36,progressWidth,15},0,0);
	progress_filled->width=sizeWidth;
	
	float fireProgress=floor(ironFurnace->getFireProgress()*((float)16))/((float)16);
	int fireHeight=(int)(fireProgress*((float)16));
	int sizeHeight=((int)(fireProgress*((float)20)));
	fireBackground_filled->setBackground(mcClient,"textures/gui/spritesheet",{56,36-fireHeight,16,fireHeight},0,0);
	fireBackground_filled->height=sizeHeight;
	fireBackground_filled->yPosition=(mcClient->getGuiData()->getScreenHeight()/2+10-sizeHeight);
}
