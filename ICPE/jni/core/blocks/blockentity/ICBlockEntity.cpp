#include "ICBlockEntity.h"

#include <stdio.h>

#include "mcpe/util/Util.h"
#include "mcpe/client/MinecraftClient.h"
#include "mcpe/client/renderer/LevelRenderer.h"

#include "ICBlockEntityManager.h"

#include "ICPE.h"

ICBlockEntity::ICBlockEntity(BlockPos pos,BlockSource&s,Block*b)
{
	position=pos;
	block=b;
	changed=false;
	source=&s;
}
void ICBlockEntity::tick(Level&l)
{
	
}
void ICBlockEntity::load()
{
	
}
void ICBlockEntity::save()
{
	changed=false;
}
void ICBlockEntity::remove()
{
	
}
void ICBlockEntity::create()
{
	setChanged();
}
void ICBlockEntity::moveTo(BlockPos const&pos)
{
	setChanged();
}
void ICBlockEntity::setChanged()
{
	changed=true;
}
void ICBlockEntity::update()
{
	ICPE::pMinecraftClient->getLevelRenderer()->onAreaChanged(*source,position,position);
}
