#pragma once

#include <memory>

#include "mcpe/item/ItemInstance.h"
#include "mcpe/client/gui/TButton.h"

class PackedScrollContainer;
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
	std::shared_ptr<PackedScrollContainer>background;
	std::shared_ptr<PackedScrollContainer>backgroundSelected;
public:
	ItemPanel(int,ItemInstance const&,int x,int y,MinecraftClient&c);
	~ItemPanel()=default;
public:
	std::shared_ptr<Touch::TButton> getNewButton(MinecraftClient&);
	int getTargetButtonID()const;
	void render(MinecraftClient&);
	void setSelected(bool);
};
}
