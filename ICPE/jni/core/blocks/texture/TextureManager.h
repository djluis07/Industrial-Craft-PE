#pragma once

class BlockGraphics;

class TextureManager
{
public:
	static BlockGraphics* ironFurnaceUnLit[4];
	static BlockGraphics* ironFurnaceLit[4];
	static BlockGraphics* rubberWood[11];
public:
	static void init();
	static void teardown();
};
