#pragma once

class MinecraftClient;
class BlockSource;
class BlockPos;
class Player;

class UIScreenChooser
{
private:
	MinecraftClient* client;
public:
	UIScreenChooser(MinecraftClient&);
	~UIScreenChooser()=default;
public:
	void pushGuideBookScreen();
	void pushBatteryBlockScreen(BlockSource&,BlockPos const&,Player&);
};
