#include "ICBlockEntityManager.h"

#include "mcpe/util/ChunkBlockPos.h"
#include "mcpe/util/Util.h"
#include "mcpe/util/BlockPos.h"
#include "mcpe/level/ChunkPos.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/client/MinecraftClient.h"
#include "UTIL/LOG.H"
#include "blocks/block/base/ICEntityBlock.h"
#include "blocks/Blocks.h"
#include "ICPE.h"

ICBlockEntityManager::ICBlockEntityManager(std::string const&path)
{
	localTag=mca::Database(getLocalPath()+"/games/com.mojang/minecraftWorlds/"+path+"/db/icdb.db","BlockEntityDB",ICPE::localKeyCode);
	localTag.reread();
}
ICBlockEntityManager::~ICBlockEntityManager()
{
	save();
}
ICBlockEntity* ICBlockEntityManager::getBlockEntity(BlockSource&s,BlockPos const&pos)
{
	for(std::shared_ptr<ICBlockEntity> be : mBlockEntities)
		if(be.get()&&be->pos.x==pos.x&&be->pos.z==pos.z&&be->pos.y==pos.y)
			return be.get();
	LOG_W("NPE: get block entity"+Util::toString(pos.x)+"_"+Util::toString(pos.y)+"_"+Util::toString(pos.z));
	if(IC::Blocks::mBlocks[s.getBlockID(pos).id]&&((IC::Blocks*)s.getBlock(pos))->isICEntityBlock())
	{
		addNew(((ICEntityBlock*)s.getBlock(pos))->getBlockEntity(s,pos));
		return getBlockEntity(s,pos);
	}
	LOG_E("NPE: get block entity"+Util::toString(pos.x)+"_"+Util::toString(pos.y)+"_"+Util::toString(pos.z));
	return 0;
}
void ICBlockEntityManager::addNew(std::shared_ptr<ICBlockEntity>ent)
{
	LOG_P("ADD NEW"+Util::toString((int)ent.get()));
	for(std::shared_ptr<ICBlockEntity>& be : mBlockEntities)
		if(be.get()&&be->pos.x==ent->pos.x&&be->pos.z==ent->pos.z&&be->pos.y==ent->pos.y)
		{
			be=ent;
			return;
		}
	mBlockEntities.emplace_back(ent);
	mca::ComposedTag newTag("blockTag_"+Util::toString(ent->pos.x)+"_"+Util::toString(ent->pos.y)+"_"+Util::toString(ent->pos.z));
	ent->save(newTag);
	localTag.addTag(newTag);
}
void ICBlockEntityManager::removeBlockEntity(BlockPos const&pos)
{
	for(std::shared_ptr<ICBlockEntity>& be : mBlockEntities)
		if(be.get()&&be->pos.x==pos.x&&be->pos.z==pos.z&&be->pos.y==pos.y)
		{
			be->remove();
			be.reset();
		}
	localTag.removeTag("blockTag_"+Util::toString(pos.x)+"_"+Util::toString(pos.y)+"_"+Util::toString(pos.z));
}
void ICBlockEntityManager::save()
{
	for(std::shared_ptr<ICBlockEntity>& blockEntity : mBlockEntities)
		if(blockEntity.get()&&localTag.hasTag("blockTag_"+Util::toString(blockEntity->pos.x)+"_"+Util::toString(blockEntity->pos.y)+"_"+Util::toString(blockEntity->pos.z)))
		{
			blockEntity->save(localTag.getTag("blockTag_"+Util::toString(blockEntity->pos.x)+"_"+Util::toString(blockEntity->pos.y)+"_"+Util::toString(blockEntity->pos.z)));
			blockEntity.reset();
		}
		else if(blockEntity.get())
		{
			localTag.addTag(mca::ComposedTag("blockTag_"+Util::toString(blockEntity->pos.x)+"_"+Util::toString(blockEntity->pos.y)+"_"+Util::toString(blockEntity->pos.z)));
			blockEntity->save(localTag.getTag("blockTag_"+Util::toString(blockEntity->pos.x)+"_"+Util::toString(blockEntity->pos.y)+"_"+Util::toString(blockEntity->pos.z)));
			blockEntity.reset();
		}
	localTag.save();
}
void ICBlockEntityManager::load(BlockSource&s,BlockPos const&cpos)
{
	if(localTag.hasTag("blockTag_"+Util::toString(cpos.x)+"_"+Util::toString(cpos.y)+"_"+Util::toString(cpos.z)))
	{
		mBlockEntities.emplace_back(((ICEntityBlock*)s.getBlock(cpos))->getBlockEntity(s,cpos));
		if(getBlockEntity(s,cpos))
			getBlockEntity(s,cpos)->load(localTag.getTag("blockTag_"+Util::toString(cpos.x)+"_"+Util::toString(cpos.y)+"_"+Util::toString(cpos.z)));
		else
			addNew(((ICEntityBlock*)s.getBlock(cpos))->getBlockEntity(s,cpos));
	}
	else
		addNew(((ICEntityBlock*)s.getBlock(cpos))->getBlockEntity(s,cpos));
}
std::string ICBlockEntityManager::getLocalPath()
{
	if(access("/mnt/sdcard/games/com.mojang"))
		return "/mnt/sdcard";
	else if(access("/mnt/external_sd/games/com.mojang"))
		return "/mnt/external_sd";
	else if(access("/storage/sdcard/games/com.mojang"))
		return "/storage/sdcard";
	else if(access("/storage/sdcard0/games/com.mojang"))
		return "/storage/sdcard0";
	else if(access("/storage/sdcard1/games/com.mojang"))
		return "/storage/sdcard1";
	else if(access("/storage/emulated/0/games/com.mojang"))
		return "/storage/emulated/0";
	else if(access("/storage/emulated/1/games/com.mojang"))
		return "/storage/emulated/1";
	else if(access("/storage/emulated/legacy/games/com.mojang"))
		return "/storage/emulated/legacy";
	else if(access("/sdcard/games/com.mojang"))
		return "/sdcard";
	return "/sdcard";
}
bool ICBlockEntityManager::access(std::string const& path)
{
	std::ofstream ifs(path+"/minecraftpe/options.txt",std::ios::app);
	return ifs.is_open();
}
