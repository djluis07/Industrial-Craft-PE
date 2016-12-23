#include "GuideBookScreen.h"

#include "mcpe/client/gui/PackedScrollContainer.h"
#include "mcpe/client/gui/GuiData.h"
#include "mcpe/client/gui/IntRectangle.h"
#include "mcpe/client/gui/screen/Screen.h"
#include "mcpe/client/MinecraftClient.h"

GuideBookScreen::GuideBookScreen(MinecraftClient&c):Screen(c)
{
	
}
std::string GuideBookScreen::getScreenName()const
{
	return "ic_guide_screen";
}
std::string GuideBookScreen::getScreenNameW()const
{
	return "ic_guide_screen";
}
void GuideBookScreen::init()
{
	int width=mcClient->getGuiData()->getScreenWidth();
	int height=mcClient->getGuiData()->getScreenHeight();
	
	guideBookBackground=std::make_shared<PackedScrollContainer>(false,false);
	guideBookBackground->width=304;
	guideBookBackground->height=368;
	guideBookBackground->xPosition=width/2-152;
	guideBookBackground->yPosition=height/2-184;
	guideBookBackground->setBackground(mcClient,"textures/gui/book",{8,0,152,184},0,0);
	tabElementList.push_back(guideBookBackground);
}
void GuideBookScreen::render(int i,int i2,float f)
{
	Screen::render(i,i2,f);
}
void GuideBookScreen::_buttonClicked(Button&btn)
{
	
}
