#pragma once

#include <memory>
#include <vector>

#include "mcpe/util/BlockPos.h"
#include "mcpe/client/gui/screen/Screen.h"

#include "ui/renderer/MovingItemRenderer.h"
#include "ui/view/ItemPanel.h"

class BlockSource;
class Button;
class Label;
class Player;
class GuiElement;
class ItemInstance;
class MovingItemRenderer;

namespace Touch{class TButton;}
namespace Touch{class THeader;}

class BaseContainerScreen : public Screen
{
protected:
	std::string headerName;
	std::shared_ptr<Touch::THeader> header;
	std::shared_ptr<Touch::TButton> buttonClose;
	std::shared_ptr<GuiElement> background;
	std::shared_ptr<GuiElement> closeBackground;
	std::shared_ptr<GuiElement> closeBackground_pressed;
	std::shared_ptr<GuiElement> backgroundSelected;
	std::shared_ptr<GuiElement> itemSlotDarkBackground;
protected:
	std::vector<std::shared_ptr<MovingItemRenderer> > movingItems;
	std::vector<std::shared_ptr<IC::ItemPanel> > itemPanels;
	int nowPanelID;
	int progressInSlot[36];
	float itemSelectProgressInSlot[36];
	float itemTextTimer;
	ItemInstance itemTextInstance;
public:
	BlockSource&source;
	Player&player;
public:
	BaseContainerScreen(MinecraftClient&,BlockSource&,Player&,std::string const&);
	~BaseContainerScreen()=default;
public:
	virtual std::string getScreenName()const;
	virtual std::string getScreenNameW()const;
	virtual void _buttonClicked(Button&);
	virtual void init();
	virtual void render(int,int,float);
public:
	void drawSlotItemAt(int,int,ItemInstance*);
	void startRenderMovingItem(ItemInstance *,float,float,float,float,float,float);
	void onRenderMovingItem();
	void onSlotMove(float,float,int,float,float,int,unsigned char,bool);
	void onRenderItemText();
	void startRenderItemText(ItemInstance const&);
public:
	virtual void onInit();
	virtual void onRender();
	virtual void onItemPanelChanged(IC::ItemPanel&);
	virtual void onRegisterPanels(int,int);
	virtual unsigned char getAddItemToItemPanelCount(ItemInstance const&,IC::ItemPanel&);
protected:
	void registerNewItemPanel(int x,int y,ItemInstance const&);
	std::shared_ptr<Button> getButtonByID(int);
};
