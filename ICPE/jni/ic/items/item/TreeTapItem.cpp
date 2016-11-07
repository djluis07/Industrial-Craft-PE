#include "TreeTapItem.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/block/Block.h"
#include "mcpe/entity/player/Player.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/util/FullBlock.h"

#include "ic/blocks/Blocks.h"
#include "ic/items/Items.h"
#include "ic/client/ICClient.h"
#include "ic/util/ICRandom.h"

TreeTapItem::TreeTapItem():IC::Items("ic.treetap",IC::Items::ID::mTreeTap-0x100)
{
	setIcon("treetap",0);
	setMaxStackSize(1);
	setCategory(CreativeItemCategory::TOOLS);
	setMaxDamage(128);
}
void TreeTapItem::useOn(ItemInstance*instance, Player*p, int x, int y, int z, signed char side, float, float, float)
{
	if(!(instance&&p))
		return;
	if(p->getRegion().getBlock(x,y,z)==Block::mBlocks[IC::Blocks::ID::mRubberWood]&&p->getRegion().getData(x,y,z)>0)
	{
		p->getRegion().setBlockAndData(x,y,z,FullBlock(IC::Blocks::ID::mRubberWood,p->getRegion().getData(x,y,z)-1),3);
		instance->hurtAndBreak(1,p);
		switch(side)
		{
		case 0:
			Block::mBlocks[IC::Blocks::ID::mRubberWood]->popResource(p->getRegion(),BlockPos(x,y-1,z),ItemInstance(IC::Items::ID::mRubber,1+ICClient::mInstance.getRandom().nextInt(3),0));
		break;
		case 1:
			Block::mBlocks[IC::Blocks::ID::mRubberWood]->popResource(p->getRegion(),BlockPos(x,y+1,z),ItemInstance(IC::Items::ID::mRubber,1+ICClient::mInstance.getRandom().nextInt(3),0));
		break;
		case 2:
			Block::mBlocks[IC::Blocks::ID::mRubberWood]->popResource(p->getRegion(),BlockPos(x,y,z-1),ItemInstance(IC::Items::ID::mRubber,1+ICClient::mInstance.getRandom().nextInt(3),0));
		break;
		case 3:
			Block::mBlocks[IC::Blocks::ID::mRubberWood]->popResource(p->getRegion(),BlockPos(x,y,z+1),ItemInstance(IC::Items::ID::mRubber,1+ICClient::mInstance.getRandom().nextInt(3),0));
		break;
		case 4:
			Block::mBlocks[IC::Blocks::ID::mRubberWood]->popResource(p->getRegion(),BlockPos(x-1,y,z),ItemInstance(IC::Items::ID::mRubber,1+ICClient::mInstance.getRandom().nextInt(3),0));
		break;
		case 5:
			Block::mBlocks[IC::Blocks::ID::mRubberWood]->popResource(p->getRegion(),BlockPos(x+1,y,z),ItemInstance(IC::Items::ID::mRubber,1+ICClient::mInstance.getRandom().nextInt(3),0));
		break;
		}
	}
}
