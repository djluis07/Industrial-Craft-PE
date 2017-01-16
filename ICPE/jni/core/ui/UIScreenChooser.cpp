#include "UIScreenChooser.h"

#include "mcpe/client/gui/screen/ScreenChooser.h"
#include "mcpe/client/gui/screen/Screen.h"

#include "ui/screen/BatteryBlockScreen.h"
#include "ui/screen/IronFurnaceScreen.h"

UIScreenChooser::UIScreenChooser(MinecraftClient&c)
{
	client=&c;
}
void UIScreenChooser::pushBatBoxScreen(BlockSource&s,BlockPos const&pos,Player&p)
{
	client->getScreenChooser()->_pushScreen(std::make_shared<BatteryBlockScreen>(*client,s,pos,p),false);
}
void UIScreenChooser::pushIronFurnaceScreen(Player&p,BlockPos const&pos)
{
	client->getScreenChooser()->_pushScreen(std::make_shared<IronFurnaceScreen>(*client,p,pos),false);
}
