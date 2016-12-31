#include "BlockEntityChunkContainer.h"

#include "ICBlockEntity.h"
#include "mcpe/util/Util.h"

#include "ICPE.h"

BlockEntityChunkContainer::BlockEntityChunkContainer(std::string const&path,ChunkPos const&pos,BlockSource&s)
{
	this->pos=pos;
	this->s=&s;
	
	localTag=mca::Database("/sdcard/games/com.mojang/minecraftWorlds/"+path+"/icdb/chunkdb_"+Util::toString(pos.x)+"-"+Util::toString(pos.z)+".db","chunkdb_"+Util::toString(pos.x)+"-"+Util::toString(pos.z),ICPE::localKeyCode);
}
void BlockEntityChunkContainer::tick(Level&lv)
{
	for(unsigned char posX=0;posX<16;++posX)
		for(unsigned char posY=0;posY<256;++posY)
			for(unsigned char posZ=0;posZ<16;++posZ)
				if(mBlockEntities[posX][posY][posZ].get())
					mBlockEntities[posX][posY][posZ]->tick(lv);
}
void BlockEntityChunkContainer::load()
{
	localTag.reread();
	
	for(unsigned char posX=0;posX<16;++posX)
		for(unsigned char posY=0;posY<256;++posY)
			for(unsigned char posZ=0;posZ<16;++posZ)
				;//if(hasTag(
}
void BlockEntityChunkContainer::save()
{
	localTag.save();
}
void BlockEntityChunkContainer::addNew(ChunkBlockPos const&,std::unique_ptr<ICBlockEntity>)
{
	
}
void BlockEntityChunkContainer::remove(ChunkBlockPos const&)
{
	
}
std::unique_ptr<ICBlockEntity>& BlockEntityChunkContainer::getICBlockEntity(ChunkBlockPos const&)
{
	
}
