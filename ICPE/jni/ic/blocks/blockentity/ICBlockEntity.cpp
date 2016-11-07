#include "ICBlockEntity.h"

#include <stdio.h>

#include "mcpe/util/Util.h"
#include "mcpe/client/MinecraftClient.h"
#include "mcpe/client/renderer/LevelRenderer.h"

#include "ICBlockEntityManager.h"
#include "ic/client/ICClient.h"

ICBlockEntity::ICBlockEntity(BlockPos pos,BlockSource&s,Block*b,std::string p)
{
	position=pos;
	path=p;
	block=b;
	changed=false;
	source=&s;
	
	ICClient::mInstance.getBlockEntityManager().addNew(this);
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
	::remove(("/sdcard/games/com.mojang/minecraftWorlds/"+path+"/db/exnihilo/BE"+Util::toString(position.x)+"_"+Util::toString(position.y)+"_"+Util::toString(position.z)+".BEdb").c_str());
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
	ICClient::mInstance.getMinecraftClient()->getLevelRenderer()->onAreaChanged(*source,position,position);
}
void ICBlockEntity::onRemove()
{
	
}
