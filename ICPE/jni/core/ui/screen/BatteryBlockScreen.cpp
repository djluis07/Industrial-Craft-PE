#include "BatteryBlockScreen.h"

#include "mcpe/client/gui/PackedScrollContainer.h"
#include "mcpe/client/gui/GuiData.h"
#include "mcpe/client/gui/IntRectangle.h"
#include "mcpe/client/gui/screen/Screen.h"
#include "mcpe/client/MinecraftClient.h"

BatteryBlockScreen::BatteryBlockScreen(BlockSource&s,BlockPos const&pos,Player&p):BaseContainerScreen(s,pos,p,"IC Battery Screen")
{
	
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
	int width=scr->mcClient->getGuiData()->getScreenWidth();
	int height=scr->mcClient->getGuiData()->getScreenHeight();
	
	electricityBackground=std::make_shared<PackedScrollContainer>(false,false);
	electricityBackground->width=width;
	electricityBackground->height=height;
	electricityBackground->xPosition=0;
	electricityBackground->yPosition=0;
	electricityBackground->setBackground(scr->mcClient,"textures/gui/ic_common",{0,0,256,256},0,0);
}
void BatteryBlockScreen::onRender()
{
	//electricityBackground->render(scr->mcClient,electricityBackground->xPosition,electricityBackground->yPosition);
}
std::string BatteryBlockScreen::getScreenName()const
{
	return "ic_battery_block_screen";
}
