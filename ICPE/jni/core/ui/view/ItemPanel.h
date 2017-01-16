#pragma once

#include <memory>

#include "mcpe/item/ItemInstance.h"
#include "mcpe/client/gui/TButton.h"

class GuiElement;
class IntRectangle;
class MinecraftClient;

namespace IC
{
class ItemPanel
{
public:
	ItemInstance item;
	int xPosition;
	int yPosition;
	int selectedCount;
	float selectedProgress;
	int id;
	bool selected;
protected:
	std::shared_ptr<GuiElement>background;
public:
	ItemPanel(int,ItemInstance const&,int x,int y,MinecraftClient&c);
	~ItemPanel()=default;
public:
	std::shared_ptr<Touch::TButton> getNewButton(MinecraftClient&);
	int getTargetButtonID()const;
	void render(MinecraftClient&);
	void setSelected(bool);
	bool getSelected()const;
	std::shared_ptr<GuiElement> getBackground();
	int getID()const;
	ItemInstance getItem()const;
};
}
