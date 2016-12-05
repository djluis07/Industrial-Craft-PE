#include "MovingItemRenderer.h"

#include "mcpe/client/renderer/ItemRenderer.h"

MovingItemRenderer::MovingItemRenderer(ItemInstance*_item,float xstart,float ystart,float xend,float yend,float speed,float size)
{
	this->item=*_item;
	this->xStart=xstart;
	this->yStart=ystart;
	this->xEnd=xend;
	this->yEnd=yend;
	this->size=size;
	this->speed=speed;
	this->renderProgress=0;
	
	this->lineConstK=(yEnd-yStart)/(xEnd-xStart);
	this->lineConstB=(yStart*xEnd-yEnd*xStart)/(xEnd-xStart);
}
MovingItemRenderer::MovingItemRenderer()
{
	this->item=ItemInstance();
	this->xStart=0;
	this->yStart=0;
	this->xEnd=0;
	this->yEnd=0;
	this->size=0;
	this->speed=0;
	this->renderProgress=1;
	
	this->lineConstK=0;
	this->lineConstB=0;
}
void MovingItemRenderer::onRender()
{
	if(finished())return;
	
	renderProgress+=speed;
	float renderXPosition=0;
	if(xEnd<xStart)
		renderXPosition=xStart-(xStart-xEnd)*renderProgress;
	else
		renderXPosition=xStart+(xEnd-xStart)*renderProgress;
	float renderYPosition=lineConstK*renderXPosition+lineConstB;
	
	ItemRenderer::instance->renderGuiItemNew(&item,0,renderXPosition+5,renderYPosition+2.5,size,1,1,false);
}
bool MovingItemRenderer::finished()const
{
	return renderProgress>=1;
}
