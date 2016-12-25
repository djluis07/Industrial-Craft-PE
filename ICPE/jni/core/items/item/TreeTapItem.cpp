#include "TreeTapItem.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/block/Block.h"
#include "mcpe/entity/player/Player.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/util/Random.h"

#include "blocks/Blocks.h"
#include "items/Items.h"

#include "ICPE.h"

TreeTapItem::TreeTapItem():IC::Items("ic.treetap",IC::Items::ID::mTreeTap-0x100)
{
	setIcon("icpe_treetap",0);
	setMaxStackSize(1);
	setCategory(CreativeItemCategory::TOOLS);
	setMaxDamage(128);
}
