/****************************
 * UILib by MCAL Team
 * Targets MCPE 0.16
 * Copyright © 2016 MCAL Team
 ****************************/

#pragma once

#include <string>
#include <vector>
#include <memory>

class UILibScreen;
class Screen;
class MinecraftClient;

class UILib
{
private:
	static std::vector<std::shared_ptr<UILibScreen> >mScreens;
public:
	//please perform it in JNI_OnLoad.
	static void setup();
public:
	static std::string (*_UILib_getScreenName_)(Screen const*const);
	static std::string _UILib_getScreenName(Screen const*const);
	static void (*_UILib_renderScreen_)(Screen*,int,int,float);
	static void _UILib_renderScreen(Screen*self,int i,int ii,float f);
	static void (*_UILib_deleteScreen_)(Screen*);
	static void _UILib_deleteScreen(Screen*self);
	static void (*_UILib__pointerPressed_)(Screen*,int,int);
	static void _UILib__pointerPressed(Screen*self,int x,int y);
public:
	static void deleteScreen(Screen*);
	static std::string getScreenName(Screen const*const);
	static void render(Screen*,int,int,float,void (*)(Screen*,int,int,float));
	static void pointerPressed(Screen*,int,int);
	static bool haveScreenInList(Screen const*const);
public:
	static std::shared_ptr<Screen> createUILibScreen(std::shared_ptr<UILibScreen>,MinecraftClient&);
};
