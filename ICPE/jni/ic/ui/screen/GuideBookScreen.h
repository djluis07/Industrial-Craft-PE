#pragma once

#include <memory>
#include <string>

#include "ic/ui/uilib/UILibScreen.h"

class Button;
class PackedScrollContainer;

class GuideBookScreen : public UILibScreen
{
protected:
	std::shared_ptr<PackedScrollContainer> guideBookBackground;
public:
	GuideBookScreen();
	~GuideBookScreen()=default;
public:
	virtual std::string getScreenName()const;
	virtual void init();
	virtual void buttonClicked(Button&);
	virtual void render(int,int,float,void (*)(int,int,float));
};
