#pragma once

#include <memory>
#include <string>

#include "mcpe/client/gui/screen/Screen.h"

class Button;
class PackedScrollContainer;

class GuideBookScreen : public Screen
{
protected:
	std::shared_ptr<PackedScrollContainer> guideBookBackground;
public:
	GuideBookScreen(MinecraftClient&);
	~GuideBookScreen()=default;
public:
	virtual void _buttonClicked(Button&);
	virtual void render(int,int,float);
	virtual std::string getScreenName()const;
	virtual std::string getScreenNameW()const;
	virtual void init();
};
