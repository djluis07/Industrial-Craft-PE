#pragma once

class BlockGraphics;

class TextureManager
{
public:
	static BlockGraphics* ironFurnaceUnLit0;
	static BlockGraphics* ironFurnaceUnLit1;
	static BlockGraphics* ironFurnaceUnLit2;
	static BlockGraphics* ironFurnaceUnLit3;
	static BlockGraphics* ironFurnaceLit0;
	static BlockGraphics* ironFurnaceLit1;
	static BlockGraphics* ironFurnaceLit2;
	static BlockGraphics* ironFurnaceLit3;
public:
	static void init();
	static void teardown();
};
