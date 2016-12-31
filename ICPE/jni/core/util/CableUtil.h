#pragma once

#include <string>

#include "mcpe/entity/PaletteColor.h"

class BlockSource;
class BlockPos;

class CableUtil
{
public:
	static bool isTinCable(unsigned char);
	static int getDropItemID(unsigned char);
	static bool isGlassCable(unsigned char);
	static bool isCopperCable(unsigned char);
	static bool isGoldCable(unsigned char);
	static bool isIronCable(unsigned char);
	static unsigned char dye(unsigned char,PaletteColor);
	static int getMaxVoltage(unsigned char);
	static float getResistance(unsigned char);
	static int getHurt(int);
	static int getFire(int);
	static bool isUninsulated(unsigned char);
	static void doDye(BlockSource&,BlockPos const&,PaletteColor);
	static bool canConnectTo(BlockSource&,BlockPos const&,BlockPos const&);
	static bool isDetectorCable(unsigned char);
	static bool isSplitterCable(unsigned char);
	static PaletteColor getColor(unsigned char);
	static unsigned char getPlaceBlockAux(int);
};
