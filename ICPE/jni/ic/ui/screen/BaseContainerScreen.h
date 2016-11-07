#pragma once

#include <memory>
#include <vector>

#include "mcpe/util/BlockPos.h"

#include "ic/ui/uilib/UILibScreen.h"

#include "ic/ui/renderer/MovingItemRenderer.h"
#include "ic/ui/view/ItemPanel.h"

class BlockSource;
class Button;
class Screen;
class Label;
class Biome;
class Player;
class PackedScrollContainer;
class ItemInstance;
class MovingItemRenderer;

namespace Touch{class TButton;}
namespace Touch{class THeader;}
namespace IC{class ItemUIElement;}

class BaseContainerScreen : public UILibScreen
{
protected:
	std::string headerName;
	std::shared_ptr<Touch::THeader> header;
	std::shared_ptr<Touch::TButton> buttonClose;
	std::shared_ptr<PackedScrollContainer> background;
	std::shared_ptr<PackedScrollContainer> closeBackground;
	std::shared_ptr<PackedScrollContainer> closeBackgroundPressed;
	std::shared_ptr<PackedScrollContainer> itemSlotBackground;
protected:
	std::vector<std::shared_ptr<MovingItemRenderer> > movingItems;
	std::vector<std::shared_ptr<IC::ItemPanel> > itemPanels;
	int nowPanelID;
	int progressInSlot[36];
	float itemSelectProgressInSlot[36];
	float itemTextTimer;
	ItemInstance itemTextInstance;
public:
	BlockSource*source;
	Player*player;
	BlockPos pos;
public:
	BaseContainerScreen(BlockSource&,BlockPos const&,Player&,std::string const&);
	~BaseContainerScreen()=default;
public:
	virtual std::string getScreenName()const;
	virtual void buttonClicked(Button&);
	virtual void init();
	virtual void render(int,int,float,void (*)(Screen*,int,int,float));
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
public:
	void registerNewItemPanel(int x,int y,ItemInstance const&);
	std::shared_ptr<Button> getButtonByID(int);
};
