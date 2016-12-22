#include "ItemPanel.h"

#include "mcpe/client/MinecraftClient.h"
#include "mcpe/client/gui/IntRectangle.h"
#include "mcpe/client/gui/Font.h"
#include "mcpe/client/gui/PackedScrollContainer.h"
#include "mcpe/client/renderer/ItemRenderer.h"
#include "mcpe/util/Util.h"

namespace IC
{
ItemPanel::ItemPanel(int ID,ItemInstance const&i,int x,int y,MinecraftClient&c)
{
	id=ID;
	item=i;
	xPosition=x;
	yPosition=y;
	selectedCount=-10;
	selectedProgress=0;
	selected=false;
	
	background=std::make_shared<PackedScrollContainer>(false,false);
	background->xPosition=xPosition;
	background->yPosition=yPosition;
	background->width=30;
	background->height=30;
	background->setBackground(&c,"textures/gui/gui",{229,0,6,6},2,2);
}
std::shared_ptr<Touch::TButton> ItemPanel::getNewButton(MinecraftClient&c)
{
	std::shared_ptr<Touch::TButton> newBtn=std::make_shared<Touch::TButton>(getTargetButtonID(),"",&c,false,0);
	newBtn->xPosition=xPosition;
	newBtn->yPosition=yPosition;
	newBtn->width=30;
	newBtn->height=30;
	newBtn->setVisible(false);
	return newBtn;
}
int ItemPanel::getTargetButtonID()const
{
	return id+1000;
}
bool ItemPanel::getSelected()const
{
	return selected;
}
std::shared_ptr<PackedScrollContainer> ItemPanel::getBackground()
{
	return background;
}
void ItemPanel::render(MinecraftClient&client)
{
	if(item.count==0)return;
	
	ItemRenderer::instance->renderGuiItemNew(&item,0,xPosition+7.5,yPosition+5,10,1,1,false);
	if(selectedCount>=1&&selectedCount<=item.count)
	{
		ScreenRenderer::singletonPtr->fill(xPosition+5,yPosition+3,xPosition+25,yPosition+5,Color(0.4,0.4,0.4,1.0));
		float fprogressInSlot=(float)selectedCount;
		float fItemsCount=(float)item.count;
		float progress=(fprogressInSlot)/(fItemsCount);
		ScreenRenderer::singletonPtr->fill(xPosition+5,yPosition+3,xPosition+5+(20*progress),yPosition+5,Color(0.1,1.0,0.1,1.0));
	}
	if(item.isDamaged())
	{
		ScreenRenderer::singletonPtr->fill(xPosition+5,yPosition+22,xPosition+25,yPosition+23,Color::BLACK);
		float fprogressMaxDamage=(float)item.getMaxDamage();
		float fprogressDamage=(float)fprogressMaxDamage-item.getDamageValue();
		float progress=(fprogressDamage)/(fprogressMaxDamage);
		ScreenRenderer::singletonPtr->fill(xPosition+5,yPosition+22,xPosition+5+(20*progress),yPosition+23,Color(1.0F-1.0F*progress,1.0F*progress,0.1F,1.0F));
	}
	if(item.count>1)
		client.getFont()->drawShadow(item.count>99?"99+":Util::toString(item.count),xPosition+((item.count>9)?15:20),yPosition+20,Color::WHITE,false,0);
}
void ItemPanel::setSelected(bool b)
{
	selected=b;
}
}
