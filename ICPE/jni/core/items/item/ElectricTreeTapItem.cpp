#include "ElectricTreeTapItem.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/block/Block.h"
#include "mcpe/entity/player/Player.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/util/Util.h"
#include "mcpe/client/resources/I18n.h"
#include "mcpe/util/Random.h"

#include "blocks/Blocks.h"
#include "items/Items.h"

#include "ICPE.h"

ElectricTreeTapItem::ElectricTreeTapItem():IC::Items("ic.electric.treetap",IC::Items::ID::mElectricTreeTap-0x100)
{
	setIcon("icpe_electric_treetap",0);
	setMaxStackSize(1);
	setCategory(CreativeItemCategory::TOOLS);
	setMaxDamage(201);
}
std::string ElectricTreeTapItem::buildEffectDescriptionName(const ItemInstance&i) const
{
	return "§7"+I18n::get("ic.effectname.lastectricity")+Util::toString((200-i.aux)*50)+"EU/10000EU";
}
void ElectricTreeTapItem::useOn(ItemInstance&instance, Entity&p, int x, int y, int z, signed char side, float, float, float)
{
	if(instance.aux<201&&p.getRegion().getBlock(x,y,z)==Block::mBlocks[IC::Blocks::ID::mRubberWood]&&p.getRegion().getData(x,y,z)>0)
	{
		p.getRegion().setBlockAndData(x,y,z,FullBlock(IC::Blocks::ID::mRubberWood,p.getRegion().getData(x,y,z)-1),3);
		instance.hurtAndBreak(1,0);
		switch(side)
		{
		case 0:
			p.getRegion().getBlock(x,y-1,z)->popResource(p.getRegion(),BlockPos(x,y-1,z),ItemInstance(IC::Items::ID::mRubber,1+ICPE::mRandom.nextInt(3),0));
		break;
		case 1:
			p.getRegion().getBlock(x,y+1,z)->popResource(p.getRegion(),BlockPos(x,y+1,z),ItemInstance(IC::Items::ID::mRubber,1+ICPE::mRandom.nextInt(3),0));
		break;
		case 2:
			p.getRegion().getBlock(x,y,z-1)->popResource(p.getRegion(),BlockPos(x,y,z-1),ItemInstance(IC::Items::ID::mRubber,1+ICPE::mRandom.nextInt(3),0));
		break;
		case 3:
			p.getRegion().getBlock(x,y,z+1)->popResource(p.getRegion(),BlockPos(x,y,z+1),ItemInstance(IC::Items::ID::mRubber,1+ICPE::mRandom.nextInt(3),0));
		break;
		case 4:
			p.getRegion().getBlock(x-1,y,z)->popResource(p.getRegion(),BlockPos(x-1,y,z),ItemInstance(IC::Items::ID::mRubber,1+ICPE::mRandom.nextInt(3),0));
		break;
		case 5:
			p.getRegion().getBlock(x+1,y,z)->popResource(p.getRegion(),BlockPos(x+1,y,z),ItemInstance(IC::Items::ID::mRubber,1+ICPE::mRandom.nextInt(3),0));
		break;
		}
	}
}
