#pragma once

#include "BaseContainerScreen.h"

class BatteryBlockScreen : public BaseContainerScreen
{
protected:
	std::shared_ptr<GuiElement> electricityBackground;
	BlockPos blockPos;
public:
	BatteryBlockScreen(MinecraftClient&,BlockSource&,BlockPos const&,Player&);
	~BatteryBlockScreen()=default;
public:
	virtual void onItemPanelChanged(IC::ItemPanel&);
	virtual void onRegisterPanels(int,int);
public:
	virtual std::string getScreenName()const;
	virtual void onInit();
	virtual void onRender();
};
