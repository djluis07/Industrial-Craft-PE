#pragma once

#include <memory>

#include "mcpe/item/ItemInstance.h"

class MovingItemRenderer
{
private:
	ItemInstance item;
	float speed;
	float xStart;
	float yStart;
	float xEnd;
	float yEnd;
	float size;
	double renderProgress;
	double lineConstK;
	double lineConstB;
public:
	MovingItemRenderer();
	MovingItemRenderer(ItemInstance*,float xstart,float ystart,float xend,float yend,float speed,float size);
	~MovingItemRenderer()=default;
public:
	void onRender();
	bool finished()const;
};
