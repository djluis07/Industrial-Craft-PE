#pragma once

class MinecraftClient;
class IntRectangle;

namespace IC
{
class UIRenderer
{
private:
	MinecraftClient* mcClient;
private:
	
public:
	UIRenderer(MinecraftClient&);
	~UIRenderer()=default;
public:
	void renderElectricityProgress(IntRectangle const&,float);
	void renderBurnProgress(IntRectangle const&,float);
};
}
