#include "UILib.h"

#include <dlfcn.h>
#include "Substrate.h"
#include "UILibScreen.h"

#include "mcpe/client/gui/screen/Screen.h"
#include "mcpe/client/gui/Button.h"

std::vector<std::shared_ptr<UILibScreen> > UILib::mScreens;

void UILib::setup()
{
	void* image=dlopen("libminecraftpe.so",RTLD_LAZY);
	MSHookFunction(dlsym(image,"_ZN6Screen6renderEiif"),(void*)&_UILib_renderScreen,(void**)&_UILib_renderScreen_);
	MSHookFunction(dlsym(image,"_ZN6ScreenD1Ev"),(void*)&_UILib_deleteScreen,(void**)&_UILib_deleteScreen_);
	MSHookFunction(dlsym(image,"_ZN6Screen16_pointerReleasedEii"),(void*)&_UILib__pointerPressed,(void**)&_UILib__pointerPressed_);
	MSHookFunction(dlsym(image,"_ZNK6Screen13getScreenNameEv"),(void*)&_UILib_getScreenName,(void**)&_UILib_getScreenName_);
}
std::string (*UILib::_UILib_getScreenName_)(Screen const*const);
std::string UILib::_UILib_getScreenName(Screen const*const self)
{
	if(_UILib_getScreenName_(self)=="screen")
		return getScreenName(self);
	return "screen";
}
void (*UILib::_UILib_renderScreen_)(Screen*,int,int,float);
void UILib::_UILib_renderScreen(Screen*self,int i,int ii,float f)
{
	if(haveScreenInList(self))
		render(self,i,ii,f,_UILib_renderScreen_);
	else
		_UILib_renderScreen_(self,i,ii,f);
}
void (*UILib::_UILib_deleteScreen_)(Screen*);
void UILib::_UILib_deleteScreen(Screen*self)
{
	_UILib_deleteScreen_(self);
	
	deleteScreen(self);
}
void (*UILib::_UILib__pointerPressed_)(Screen*,int,int);
void UILib::_UILib__pointerPressed(Screen*self,int x,int y)
{
	pointerPressed(self,x,y);
	_UILib__pointerPressed_(self,x,y);
}
void UILib::deleteScreen(Screen*scr)
{
	for(std::shared_ptr<UILibScreen>&bes : mScreens)
		if(bes.get())
			if(bes->scr==scr)
				bes.reset();
}
std::string UILib::getScreenName(Screen const*const scr)
{
	for(std::shared_ptr<UILibScreen>&bes : mScreens)
		if(bes.get())
			if(bes->scr==scr)
				return bes->getScreenName();
	return "screen";
}
void UILib::render(Screen*scr,int i,int ii,float f,void (*function)(Screen*,int,int,float) )
{
	for(std::shared_ptr<UILibScreen>&bes : mScreens)
		if(bes.get())
			if(bes->scr==scr)
				return bes->render(i,ii,f,function);
}
void UILib::pointerPressed(Screen*scr,int x,int y)
{
	for(std::shared_ptr<UILibScreen>&bes : mScreens)
		if(bes.get())
			if(bes->scr==scr)
				for(std::shared_ptr<Button>&btn : scr->buttonList)
					if(btn->xPosition<=x&&btn->yPosition<=y&&x<=(btn->xPosition+btn->width)&&y<=(btn->yPosition+btn->height))
						bes->buttonClicked(*btn.get());
}
bool UILib::haveScreenInList(Screen const*const scr)
{
	for(std::shared_ptr<UILibScreen>&bes : mScreens)
		if(bes.get())
			if(bes->scr==scr)
				return true;
	return false;
}
std::shared_ptr<Screen> UILib::createUILibScreen(std::shared_ptr<UILibScreen>screen,MinecraftClient&c)
{
	Screen * mcpeScreen=new Screen(c);
	screen->scr=mcpeScreen;
	screen->init();
	mScreens.push_back(screen);
	return std::shared_ptr<Screen>(mcpeScreen);
}
