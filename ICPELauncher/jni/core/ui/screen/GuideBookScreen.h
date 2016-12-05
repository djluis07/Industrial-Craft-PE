#pragma once

#include <memory>
#include <string>

#include "ui/uilib/UILibScreen.h"

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
	virtual void buttonClicked(Button&);
	virtual void render(int,int,float,void (*)(Screen*,int,int,float));
	virtual std::string getScreenName()const;
	virtual void init();
};
