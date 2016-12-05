#include "GuideBookScreen.h"

#include "mcpe/client/gui/PackedScrollContainer.h"
#include "mcpe/client/gui/GuiData.h"
#include "mcpe/client/gui/IntRectangle.h"
#include "mcpe/client/gui/screen/Screen.h"
#include "mcpe/client/MinecraftClient.h"

GuideBookScreen::GuideBookScreen()
{
	
}
std::string GuideBookScreen::getScreenName()const
{
	return "ic_guide_screen";
}
void GuideBookScreen::init()
{
	int width=scr->mcClient->getGuiData()->getScreenWidth();
	int height=scr->mcClient->getGuiData()->getScreenHeight();
	
	guideBookBackground=std::make_shared<PackedScrollContainer>(false,false);
	guideBookBackground->width=304;
	guideBookBackground->height=368;
	guideBookBackground->xPosition=width/2-152;
	guideBookBackground->yPosition=height/2-184;
	guideBookBackground->setBackground(scr->mcClient,"textures/gui/book",{8,0,152,184},0,0);
}
void GuideBookScreen::render(int,int,float,void (*)(Screen*,int,int,float))
{
	guideBookBackground->render(scr->mcClient,guideBookBackground->xPosition,guideBookBackground->yPosition);
}
void GuideBookScreen::buttonClicked(Button&btn)
{
	
}
