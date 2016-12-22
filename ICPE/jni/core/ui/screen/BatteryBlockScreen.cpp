#include "BatteryBlockScreen.h"

#include "mcpe/client/gui/PackedScrollContainer.h"
#include "mcpe/client/gui/GuiData.h"
#include "mcpe/client/gui/IntRectangle.h"
#include "mcpe/client/gui/screen/Screen.h"
#include "mcpe/client/MinecraftClient.h"

BatteryBlockScreen::BatteryBlockScreen(MinecraftClient&c,BlockSource&s,BlockPos const&pos,Player&p):BaseContainerScreen(c,s,p,"IC Battery Screen")
{
	blockPos=pos;
}
void BatteryBlockScreen::onItemPanelChanged(IC::ItemPanel&)
{
	
}
void BatteryBlockScreen::onRegisterPanels(int width,int height)
{
	registerNewItemPanel(200,height/2+40,ItemInstance());
	registerNewItemPanel(200,height/2-40,ItemInstance());
}
void BatteryBlockScreen::onInit()
{
	int width=mcClient->getGuiData()->getScreenWidth();
	int height=mcClient->getGuiData()->getScreenHeight();
	
	electricityBackground=std::make_shared<PackedScrollContainer>(false,false);
	electricityBackground->width=width;
	electricityBackground->height=height;
	electricityBackground->xPosition=0;
	electricityBackground->yPosition=0;
	electricityBackground->setBackground(mcClient,"textures/gui/ic_common",{0,0,256,256},0,0);
}
void BatteryBlockScreen::onRender()
{
	
}
std::string BatteryBlockScreen::getScreenName()const
{
	return "ic_battery_block_screen";
}
