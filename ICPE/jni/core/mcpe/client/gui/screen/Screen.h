#pragma once

#include <memory>
#include <vector>
#include "../GuiComponent.h"
#include "BaseScreen.h"

namespace Touch { class TButton; };


class StickDirection;
class MinecraftClient;
class Button;
class TextBox;
class GuiElement;
class MCOEvent;
class MojangConnectionStatus;
class ControllerButtonRenderer;
class ItemInstance;

// Size : 160
class Screen : public BaseScreen, public GuiComponent
{
public:
	//void* vtable; // 8
	int width; // 12
	int height; // 16
	MinecraftClient* mcClient; // 20
	std::vector<std::shared_ptr<Button>> buttonList; // 24
	std::vector<std::shared_ptr<TextBox>> textboxList; // 36
	std::vector<std::shared_ptr<Button>> tabButtonList; // 48
	std::vector<std::shared_ptr<GuiElement>> tabElementList; // 60
	std::vector<std::shared_ptr<GuiElement>> guiElementList; // 72
	int tabButtonIndex; // 84
	int tabElementIndex; // 88
	std::unique_ptr<ControllerButtonRenderer> buttonRenderer; // 92
	Font* font; // 96
	Button* buttonClicked; // 100
	char screen_vars6[32]; // 104

	Screen(MinecraftClient&);

    virtual ~Screen();
    virtual void _init(int, int);
    virtual void setSize(int, int);
    virtual void onSetKeyboardHeight(float);
    virtual void setAssociatedBlockPos(BlockPos const&);
    virtual void onInternetUpdate();
    virtual void onFocusGained();
    virtual void onFocusLost();
    virtual void terminate();
    virtual void tick();
    virtual void tick(int, int);
    virtual void updateEvents();
    virtual void render(ScreenContext&);
    virtual void handleInputModeChanged(InputMode);
    virtual void handleHoloInputModeChanged(HoloUIInputMode);
    virtual void handleButtonPress(short, FocusImpact);
    virtual void handleButtonRelease(short, FocusImpact);
    virtual void handleRawInputEvent(int, RawInputType, ButtonState, bool);
    virtual void handlePointerLocation(short, short, FocusImpact);
    virtual void handlePointerPressed(bool);
    virtual void handleDirection(DirectionId, float, float, FocusImpact);
    virtual void handleBackEvent(bool);
    virtual void handleTextChar(std::string const&, bool, FocusImpact);
    virtual void handleCaretLocation(int, FocusImpact);
    virtual void setTextboxText(std::string const&);
    virtual void handleLicenseChanged();
    virtual void handleIdentityGained();
    virtual void handleIdentityLost();
    virtual void handleGazeGestureInput(short, float, float, float, FocusImpact);
    virtual void handleDictationEvent();
    virtual void handleCommandEvent(VoiceCommand const&);
    virtual bool renderGameBehind() const;
    virtual bool absorbsInput() const;
    virtual bool closeOnPlayerHurt() const;
    virtual int getWidth();
    virtual int getHeight();
    virtual std::string getScreenName() const;
    virtual std::string getScreenNameW() const;
    virtual void toGUICoordinate(int, int, int&, int&);
    virtual void render(int, int, float);
    virtual void init();
    virtual void setupPositions();
    virtual void checkForPointerEvent();
    virtual void controllerEvent();
    virtual void renderBackground(int);
    virtual void renderDirtBackground();
    virtual void renderMenuBackground(float);
    virtual void confirmResult(bool, int);
    virtual void supppressedBySubWindow();
    virtual void onTextBoxUpdated(int);
    virtual void onMojangConnectorStatus(MojangConnectionStatus);
    virtual void handleButtonPress(short);
    virtual void handleButtonRelease(short);
    virtual void handleTextChar(std::string const&, bool);
    virtual void handleCaretLocation(int);
    virtual void handlePointerLocation(short, short);
    virtual void handleDirection(DirectionId, float, float);
    virtual void handleScrollWheel(float);
    virtual void handleGazeGestureInput(short, float, float, float);
    virtual void _handlePointerAction(int, int, bool);
    virtual void _updateTabButtonSelection();
    virtual void _buttonClicked(Button&);
    virtual void _guiElementClicked(GuiElement&);
    virtual void _pointerPressed(int, int);
    virtual void _pointerReleased(int, int);
    virtual void _controllerDirectionChanged(int, StickDirection);
    virtual void _controllerDirectionHeld(int, StickDirection);

	int _getCursorMoveThrottle();
	void _processControllerDirection(int);
	void _renderSlot(int, int, int, float);
	void _tabNext();
	void _tabPrev();
	void renderOnSelectItemNameText(int, Font*, int);
	void renderProgressBar(float);
	void renderSlotText(const ItemInstance*, float, float, bool, bool, bool, bool);
	void renderToolBar(float, float, bool);
	void setButtonIndex(int);
};
