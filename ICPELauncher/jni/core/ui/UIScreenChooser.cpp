#include "UIScreenChooser.h"

#include "mcpe/client/gui/screen/ScreenChooser.h"
#include "mcpe/client/gui/screen/Screen.h"
#include "ui/uilib/UILib.h"

#include "ui/screen/BatteryBlockScreen.h"
#include "ui/screen/GuideBookScreen.h"

UIScreenChooser::UIScreenChooser(MinecraftClient&c)
{
	client=&c;
}
void UIScreenChooser::pushBatteryBlockScreen(BlockSource&s,BlockPos const&pos,Player&p)
{
	client->getScreenChooser()->_pushScreen(UILib::createUILibScreen(std::make_shared<BatteryBlockScreen>(s,pos,p),*client),false);
}
void UIScreenChooser::pushGuideBookScreen()
{
	client->getScreenChooser()->_pushScreen(UILib::createUILibScreen(std::make_shared<GuideBookScreen>(),*client),false);
}
