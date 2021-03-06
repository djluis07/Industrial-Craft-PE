#include "BaseContainerScreen.h"

#include <sstream>

#include "mcpe/client/MinecraftClient.h"
#include "mcpe/client/gui/GuiData.h"
#include "mcpe/client/gui/THeader.h"
#include "mcpe/client/gui/TButton.h"
#include "mcpe/client/gui/Label.h"
#include "mcpe/client/gui/GuiElement.h"
#include "mcpe/client/gui/IntRectangle.h"
#include "mcpe/client/gui/Font.h"
#include "mcpe/client/gui/screen/Screen.h"
#include "mcpe/client/gui/screen/ScreenChooser.h"
#include "mcpe/client/renderer/ScreenRenderer.h"
#include "mcpe/client/renderer/ItemRenderer.h"
#include "mcpe/client/settings/Options.h"
#include "mcpe/util/Color.h"
#include "mcpe/util/Util.h"
#include "mcpe/entity/player/LocalPlayer.h"
#include "mcpe/entity/player/Inventory.h"
#include "mcpe/inventory/InventoryMenu.h"
#include "mcpe/item/ItemInstance.h"
#include "mcpe/item/Item.h"
#include "mcpe/block/Block.h"

BaseContainerScreen::BaseContainerScreen(MinecraftClient&c,BlockSource&s,Player&p,std::string const&n):Screen(c),source(s),player(p)
{
	headerName=n;
	itemTextTimer=0;
	itemTextHover="";
	itemTextEffect="";
	nowPanelID=0;
	for(int &progress : progressInSlot)
		progress=-10;
	for(float &progress : itemSelectProgressInSlot)
		progress=0;
}
void BaseContainerScreen::init()
{
	Screen::init();
	
	unsigned int posInInv=0;
	for(unsigned int yPos=35;posInInv<36;yPos+=25)
		for(unsigned int xPos=getItemSlotsStartPos();xPos<(width/2-30)&&posInInv<36;xPos+=25)
		{
			std::shared_ptr<Touch::TButton> newBtn=std::make_shared<Touch::TButton>(posInInv++,"",mcClient,false,0);
			newBtn->xPosition=xPos;
			newBtn->yPosition=yPos;
			newBtn->width=25;
			newBtn->height=25;
			newBtn->setVisible(false);
			buttonList.push_back(newBtn);
		}
	int currentID=100;
	
	background=std::make_shared<GuiElement>(false,false,0,0,0,0);
	background->xPosition=0;
	background->yPosition=0;
	background->width=width;
	background->height=height;
	background->setBackground(mcClient,"textures/gui/spritesheet",{34,43,14,14},3,3);
	tabElementList.push_back(background);
	
	header=std::make_shared<Touch::THeader>(++currentID,headerName);
	header->xPosition=0;
	header->yPosition=0;
	header->width=width;
	header->height=25;
	tabElementList.push_back(header);
	
	buttonClose=std::make_shared<Touch::TButton>(++currentID,"",mcClient,false,0);
	buttonClose->xPosition=width-20;
	buttonClose->yPosition=0;
	buttonClose->width=20;
	buttonClose->height=20;
	buttonClose->setVisible(false);
	buttonList.push_back(buttonClose);
	
	closeBackground=std::make_shared<GuiElement>(false,false,0,0,0,0);
	closeBackground->xPosition=width-20;
	closeBackground->yPosition=0;
	closeBackground->width=20;
	closeBackground->height=20;
	closeBackground->setVisible(false);
	closeBackground->setBackground(mcClient,"textures/gui/spritesheet",{60,0,18,18},0,0);
	tabElementList.push_back(closeBackground);
	
	backgroundSelected=std::make_shared<GuiElement>(false,false,0,0,0,0);
	backgroundSelected->xPosition=-50;
	backgroundSelected->yPosition=-50;
	backgroundSelected->width=0;
	backgroundSelected->height=0;
	backgroundSelected->setBackground(mcClient,"textures/gui/gui",{0,22,24,24},3,3);
	tabElementList.push_back(backgroundSelected);
	
	itemSlotDarkBackground=std::make_shared<GuiElement>(false,false,0,0,0,0);
	itemSlotDarkBackground->width=width/2-10;
	itemSlotDarkBackground->height=height-35;
	itemSlotDarkBackground->xPosition=5;
	itemSlotDarkBackground->yPosition=30;
	itemSlotDarkBackground->setBackground(Color(0.25,0.25,0.25,1.0));
	tabElementList.push_back(itemSlotDarkBackground);

	posInInv=0;
	for(unsigned int yPos=35;posInInv<36;yPos+=25)
		for(unsigned int xPos=getItemSlotsStartPos();xPos<(width/2-30)&&posInInv<36;xPos+=25,++posInInv)
		{
			std::shared_ptr<GuiElement> itemSlotBackground=std::make_shared<GuiElement>(false,false,0,0,0,0);
			itemSlotBackground->width=25;
			itemSlotBackground->height=25;
			itemSlotBackground->xPosition=xPos;
			itemSlotBackground->yPosition=yPos;
			itemSlotBackground->setBackground(mcClient,"textures/gui/gui",{200,46,16,16},2,2);
			tabElementList.push_back(itemSlotBackground);
		}
	
	onInit();
	
	onRegisterPanels(width,height);
	if(itemPanels.size()>0)
		itemPanels[0]->setSelected(true);
}
void BaseContainerScreen::tick()
{
	Screen::tick();
	InventoryMenu* invMenu=mcClient->getLocalPlayer()->getInventoryMenu();
	int width=mcClient->getGuiData()->getScreenWidth();
	int height=mcClient->getGuiData()->getScreenHeight();
	
	for(std::shared_ptr<Button>& btn : buttonList)
	{
		//inv
		
		if(btn.get()&&btn->id<36&&invMenu->getSlot(btn->id)&&btn->msg==""&&btn->pressed)
		{
			if(progressInSlot[btn->id]<1)
				++progressInSlot[btn->id];
			else if(progressInSlot[btn->id]>=1&&progressInSlot[btn->id]<invMenu->getSlot(btn->id)->count)
			{
				float itemProgress=invMenu->getSlot(btn->id)->count;
				if(itemSelectProgressInSlot[btn->id]<1)
					itemSelectProgressInSlot[btn->id]+=((float)itemProgress/64.0F);
				else if(itemSelectProgressInSlot[btn->id]>=1)
					++progressInSlot[btn->id],itemSelectProgressInSlot[btn->id]=0;
			}
			else if(progressInSlot[btn->id]==invMenu->getSlot(btn->id)->count)
				onSlotMove(btn->xPosition,btn->yPosition,btn->id,itemPanels[nowPanelID]->xPosition,itemPanels[nowPanelID]->yPosition,nowPanelID,progressInSlot[btn->id],true),progressInSlot[btn->id]=-10;
		}
		else if(btn.get()&&btn->id<36&&invMenu->getSlot(btn->id)&&btn->msg==""&&!btn->pressed)
		{
			if(progressInSlot[btn->id]>-10&&progressInSlot[btn->id]<2)
				onSlotMove(btn->xPosition,btn->yPosition,btn->id,itemPanels[nowPanelID]->xPosition,itemPanels[nowPanelID]->yPosition,nowPanelID,1,true),progressInSlot[btn->id]=-10;
			else if(progressInSlot[btn->id]>1&&progressInSlot[btn->id]<invMenu->getSlot(btn->id)->count)
				onSlotMove(btn->xPosition,btn->yPosition,btn->id,itemPanels[nowPanelID]->xPosition,itemPanels[nowPanelID]->yPosition,nowPanelID,progressInSlot[btn->id],true),progressInSlot[btn->id]=-10;
		}
		//panels
		
		if(btn.get()&&btn->id>=1000&&btn->id-1000==nowPanelID&&itemPanels[btn->id-1000]->item.count>0&&btn->msg==""&&btn->pressed)
		{
			if(itemPanels[btn->id-1000]->selectedCount<1)
				++itemPanels[btn->id-1000]->selectedCount;
			else if(itemPanels[btn->id-1000]->selectedCount>=1&&itemPanels[btn->id-1000]->selectedCount<itemPanels[btn->id-1000]->item.count)
			{
				float itemProgress=itemPanels[btn->id-1000]->item.count;
				if(itemPanels[btn->id-1000]->selectedProgress<1)
					itemPanels[btn->id-1000]->selectedProgress+=((float)itemProgress/64.0F);
				else if(itemPanels[btn->id-1000]->selectedProgress>=1)
					++itemPanels[btn->id-1000]->selectedCount,itemPanels[btn->id-1000]->selectedProgress=0;
			}
			else if(itemPanels[btn->id-1000]->selectedCount==itemPanels[btn->id-1000]->item.count)
				onSlotMove(btn->xPosition,btn->yPosition,btn->id-1000,0,0,0,itemPanels[btn->id-1000]->selectedCount,false),itemPanels[btn->id-1000]->selectedCount=-10;
		}
		else if(btn.get()&&btn->id>=1000&&btn->id-1000==nowPanelID&&itemPanels[btn->id-1000]->item.count>0&btn->msg==""&&!btn->pressed)
		{
			if(itemPanels[btn->id-1000]->selectedCount>-10&&itemPanels[btn->id-1000]->selectedCount<2)
				onSlotMove(btn->xPosition,btn->yPosition,btn->id-1000,0,0,0,1,false),itemPanels[btn->id-1000]->selectedCount=-10;
			else if(itemPanels[btn->id-1000]->selectedCount>1&&itemPanels[btn->id-1000]->selectedCount<itemPanels[btn->id-1000]->item.count)
				onSlotMove(btn->xPosition,btn->yPosition,btn->id-1000,0,0,0,itemPanels[btn->id-1000]->selectedCount,false),itemPanels[btn->id-1000]->selectedCount=-10;
		}
	}
}
void BaseContainerScreen::render(int int1,int int2,float floatvalue)
{
	InventoryMenu* invMenu=mcClient->getLocalPlayer()->getInventoryMenu();
	closeBackground->setBackground(mcClient,"textures/gui/spritesheet",{buttonClose->pressed?78:60,0,18,18},0,0);
	
	for(std::shared_ptr<IC::ItemPanel>& panel : itemPanels)
		if(panel->getSelected())
		{
			backgroundSelected->xPosition=panel->xPosition-3;
			backgroundSelected->yPosition=panel->yPosition-3;
			backgroundSelected->width=36;
			backgroundSelected->height=36;
		}
	
	//render background
	Screen::render(int1,int2,floatvalue);

	//render inventory items
	unsigned int posInInv=0;
	for(unsigned int yPos=35;posInInv<36;yPos+=25)
	{
		for(unsigned int xPos=getItemSlotsStartPos();xPos<(width/2-30)&&posInInv<36;xPos+=25)
		{
			drawSlotItemAt(xPos,yPos,invMenu->getSlot(posInInv++));
			if(progressInSlot[posInInv-1]>=1&&progressInSlot[posInInv-1]<=invMenu->getSlot(posInInv-1)->count)
			{
				ScreenRenderer::singletonPtr->fill(xPos+5,yPos+3,xPos+20,yPos+5,Color(0.4,0.4,0.4,1.0));
				float fprogressInSlot=(float)progressInSlot[posInInv-1];
				float fItemsCount=(float)invMenu->getSlot(posInInv-1)->count;
				float progress=(fprogressInSlot)/(fItemsCount);
				ScreenRenderer::singletonPtr->fill(xPos+5,yPos+3,xPos+5+(15*progress),yPos+5,Color(0.1,1.0,0.1,1.0));
			}
			if(invMenu->getSlot(posInInv-1)&&invMenu->getSlot(posInInv-1)->isDamaged())
			{
				ScreenRenderer::singletonPtr->fill(xPos+5,yPos+19,xPos+20,yPos+20,Color::BLACK);
				float fprogressMaxDamage=(float)invMenu->getSlot(posInInv-1)->getMaxDamage();
				float fprogressDamage=(float)fprogressMaxDamage-invMenu->getSlot(posInInv-1)->getDamageValue();
				float progress=(fprogressDamage)/(fprogressMaxDamage);
				ScreenRenderer::singletonPtr->fill(xPos+5,yPos+19,xPos+5+(15*progress),yPos+20,Color(1.0F-1.0F*progress,1.0F*progress,0.1F,1.0F));
			}
		}
	}
	//render panels
	for(std::shared_ptr<IC::ItemPanel>& panel : itemPanels)
		panel->render(*mcClient);
	
	onRender();
	onRenderMovingItem();
}
std::string BaseContainerScreen::getScreenName()const
{
	return "ic_base_container_screen";
}
std::string BaseContainerScreen::getScreenNameW()const
{
	return "ic_base_container_screen";
}
void BaseContainerScreen::_buttonClicked(Button&btn)
{
	if(buttonClose.get()==&btn)
		mcClient->getScreenChooser()->schedulePopScreen(1);
	if(btn.id>=1000&&nowPanelID!=btn.id-1000)
	{
		itemPanels[nowPanelID]->setSelected(false);
		nowPanelID=btn.id-1000;
		itemPanels[nowPanelID]->setSelected(true);
	}
}
void BaseContainerScreen::drawSlotItemAt(int x,int y,ItemInstance* item)
{
	if(item)ItemRenderer::instance->renderGuiItemNew(item,0,x+5,y+2.5,2,1,1,false);
	if(item&&item->count>1)
		mcClient->getFont()->drawShadow(item->count>99?"99+":Util::toString(item->count),x+((item->count>9)?10:15),y+15,Color::WHITE,false,0);
}
void BaseContainerScreen::startRenderMovingItem(ItemInstance *item,float xStart,float yStart,float xEnd,float yEnd,float speed,float size)
{
	std::shared_ptr<MovingItemRenderer> newRenderer=std::make_shared<MovingItemRenderer>(item,xStart,yStart,xEnd,yEnd,speed,size);
	movingItems.push_back(newRenderer);
}
void BaseContainerScreen::onRenderMovingItem()
{
	for(std::shared_ptr<MovingItemRenderer>&item : movingItems)
		if(item.get()&&item->finished())
			item.reset();
		else if(item.get())
			item->onRender();
}
void BaseContainerScreen::onInit()
{
	
}
void BaseContainerScreen::onRender()
{
	
}
void BaseContainerScreen::onSlotMove(float startPosX,float startPosY,int startSlot,float endPosX,float endPosY,int endSlot,unsigned char count,bool isInv)
{
	if(count<1)return;
	if(itemPanels.size()<1)return;
	
	if(isInv)
	{
		InventoryMenu* invMenu=mcClient->getLocalPlayer()->getInventoryMenu();
		ItemInstance* item=invMenu->getSlot(startSlot);
		if(!item||item->isNull())
			return;
		ItemInstance copyItem=*ItemInstance::clone(item);
		copyItem.count=count;
		ItemInstance addItem=*ItemInstance::clone(item);
		addItem.count=count;
		
		if(getAddItemToItemPanelCount(addItem,*itemPanels[endSlot].get())>0)
		{
			item->remove((int)getAddItemToItemPanelCount(addItem,*itemPanels[endSlot].get()));
			addItem.count=getAddItemToItemPanelCount(addItem,*itemPanels[endSlot].get())+itemPanels[endSlot]->item.count;
			itemPanels[endSlot]->item=addItem;
			startRenderMovingItem(&copyItem,startPosX,startPosY,endPosX,endPosY,0.05,1.5);
		}
		onItemPanelChanged(*itemPanels[endSlot].get());
	}
	else
	{
		if(itemPanels[startSlot]->item.isNull())
			return;
		ItemInstance& item=itemPanels[startSlot]->item;
		ItemInstance copyItem;
		copyItem=*ItemInstance::clone(&itemPanels[startSlot]->item);
		copyItem.count=count;
		InventoryMenu* invMenu=mcClient->getLocalPlayer()->getInventoryMenu();
		ItemInstance* itemsInv[36];
		int itemsLeft=count;
		for(unsigned char i=0;i<36;++i)
			itemsInv[i]=invMenu->getSlot(i);
		for(unsigned char i=0;i<36&&itemsLeft>0;++i)
		{
			if(itemsInv[i]&&!itemsInv[i]->isNull()&&isSameItemInstance(itemsInv[i],&copyItem))
			{
				if(itemsInv[i]->count<copyItem.getMaxStackSize())
				{
					itemsLeft-=copyItem.getMaxStackSize()-itemsInv[i]->count;
					startRenderMovingItem(&copyItem,startPosX,startPosY,getButtonByID(i)->xPosition,getButtonByID(i)->yPosition,0.05,1.5);
				}
			}
		}
		for(unsigned char i=0;i<36&&itemsLeft>0;++i)
		{
			if(!itemsInv[i])
			{
				itemsLeft-=copyItem.getMaxStackSize()>itemsLeft?itemsLeft:copyItem.getMaxStackSize();
				startRenderMovingItem(&copyItem,startPosX,startPosY,getButtonByID(i)->xPosition,getButtonByID(i)->yPosition,0.05,1.5);
			}
		}
		item.remove(count);
		ItemInstance item_=copyItem;
		item_.count=count;
		player.add(item_);
		if(!item_.isNull())
			player.drop(item_,false);
		onItemPanelChanged(*itemPanels[startSlot].get());
	}
}
void BaseContainerScreen::onItemPanelChanged(IC::ItemPanel&)
{
	
}
bool BaseContainerScreen::isSameItemInstance(ItemInstance const*i,ItemInstance const*ii)const
{
	if(!i->sameItemAndAux(ii))
		return false;
	if(!i->hasSameUserData(*ii))
		return false;
	return true;
}
unsigned char BaseContainerScreen::getAddItemToItemPanelCount(ItemInstance const&i,IC::ItemPanel&panel)
{
	if(panel.item.isNull())
		return i.getMaxStackSize()<i.count?i.getMaxStackSize():i.count;
	if(!panel.item.sameItemAndAux(&i))
		return 0;
	if(panel.item.getMaxStackSize()>i.count)
		return panel.item.getMaxStackSize()-panel.item.count>i.count?i.count:panel.item.getMaxStackSize()-panel.item.count;
	return 0;
}
void BaseContainerScreen::onRegisterPanels(int,int)
{
	
}
void BaseContainerScreen::registerNewItemPanel(int x,int y,ItemInstance const&item)
{
	std::shared_ptr<IC::ItemPanel> newPanel=std::make_shared<IC::ItemPanel>(itemPanels.size(),item,x,y,*mcClient);
	buttonList.push_back(newPanel->getNewButton(*mcClient));
	itemPanels.push_back(newPanel);
	tabElementList.push_back(newPanel->getBackground());
}
std::shared_ptr<Button> BaseContainerScreen::getButtonByID(int id)
{
	for(std::shared_ptr<Button>& btn : buttonList)
		if(btn.get()&&btn->id==id)
			return btn;
}
int BaseContainerScreen::getItemSlotsStartPos()const
{
	int left = ((width/2-30)%25)/2;
	return left+15;
}
