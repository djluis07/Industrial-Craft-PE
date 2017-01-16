#pragma once

#include "BaseContainerScreen.h"

class IronFurnaceBlockEntity;

class IronFurnaceScreen : public BaseContainerScreen
{
private:
	IronFurnaceBlockEntity*ironFurnace;
	BlockPos pos;
	Block const*block;
private:
	std::shared_ptr<GuiElement> fireBackground_empty;
	std::shared_ptr<GuiElement> fireBackground_filled;
	std::shared_ptr<GuiElement> progress_empty;
	std::shared_ptr<GuiElement> progress_filled;
public:
	IronFurnaceScreen(MinecraftClient&,Player&,BlockPos const&);
	~IronFurnaceScreen()=default;
public:
	virtual std::string getScreenName()const;
	virtual std::string getScreenNameW()const;
	virtual void _buttonClicked(Button&);
	virtual void onInit();
    virtual void tick();
	virtual void onRender();
	virtual void onItemPanelChanged(IC::ItemPanel&);
	virtual void onRegisterPanels(int,int);
	virtual unsigned char getAddItemToItemPanelCount(ItemInstance const&,IC::ItemPanel&);
};
