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
	UIScreenChooser()=default;
	UIScreenChooser(MinecraftClient&);
	~UIScreenChooser()=default;
public:
	void pushIronFurnaceScreen(Player&,BlockPos const&);
	void pushBatBoxScreen(BlockSource&,BlockPos const&,Player&);
};
