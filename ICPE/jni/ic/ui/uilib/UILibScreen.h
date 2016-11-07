#pragma once

#include <string>

class Screen;
class Button;

class UILibScreen
{
public:
	Screen*scr;
public:
	UILibScreen()=default;
	~UILibScreen()=default;
public:
	virtual void buttonClicked(Button&);
	virtual void render(int,int,float,void (*)(Screen*,int,int,float));
	virtual std::string getScreenName()const;
	virtual void init();
};
