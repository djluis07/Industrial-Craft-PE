#include "ICBlockEntity.h"

#include <stdio.h>

#include "mcpe/util/Util.h"
#include "mcpe/client/MinecraftClient.h"
#include "mcpe/client/renderer/LevelRenderer.h"

#include "ICBlockEntityManager.h"

#include "ICPE.h"

ICBlockEntity::ICBlockEntity(BlockSource&s,BlockPos const&pos_,Block const*b):block(b),source(s)
{
	pos=pos_;
}
void ICBlockEntity::load(mca::ComposedTag &)
{
	
}
void ICBlockEntity::save(mca::ComposedTag&)
{
	
}
void ICBlockEntity::remove()
{
	
}
void ICBlockEntity::moveTo(BlockPos const&pos)
{
	
}
void ICBlockEntity::update()
{
	ICPE::pMinecraftClient->getLevelRenderer()->onAreaChanged(source,{pos.x-8,pos.y-8,pos.z-8},{pos.x+8,pos.y+8,pos.z+8});
}
