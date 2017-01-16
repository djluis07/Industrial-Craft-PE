#include "ContainerBlockEntity.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/item/enchant/ItemEnchants.h"
#include "mcpe/item/enchant/EnchantUtils.h"
#include "mcpe/util/Util.h"
#include "mca/data/Database.h"

#include "util/log.h"

ContainerBlockEntity::ContainerBlockEntity(BlockSource&s,BlockPos const&pos,Block const*pBlock,int count):ICBlockEntity(s,pos,pBlock),slotsCount(count)
{
	slots=std::vector<ItemInstance>(count);
	for(ItemInstance&item:slots)
		item.setNull();
}
void ContainerBlockEntity::onSlotChanged(int)
{
	
}
void ContainerBlockEntity::addItem(int pos_,short count)
{
	if(pos_>=slotsCount||slots[pos_].isNull())
		return;
	
	slots[pos_].count+=count;
}
bool ContainerBlockEntity::isEmptySlot(int pos_)
{
	if(pos_>=slotsCount)
		return false;
	return slots[pos_].isNull();
}
ItemInstance* ContainerBlockEntity::getSlot(int pos_)
{
	if(pos_>=slotsCount)
		return NULL;
	return &(slots[pos_]);
}
void ContainerBlockEntity::setSlot(int pos_,ItemInstance const*item)
{
	if(pos_>=slotsCount)
		return;
	
	if(item==NULL||item->isNull())
		slots[pos_].setNull();
	else
	{
		ItemInstance clone=(*ItemInstance::clone(item));
		slots[pos_]=clone;
	}
}
void ContainerBlockEntity::costItem(int pos_,short count)
{
	if(pos_>=slotsCount||slots[pos_].isNull())
		return;
	
	if(slots[pos_].count>count)
		slots[pos_].count-=count;
	else
		slots[pos_].setNull();
}
void ContainerBlockEntity::load(mca::ComposedTag&tag)
{
	for(int i=0;i<slotsCount;++i)
	{
		ItemInstance item;
		
		short count=tag.getShortTag("containerItem_count_"+Util::toString(i)).get();
		short id=tag.getShortTag("containerItem_id_"+Util::toString(i)).get();
		short aux=tag.getShortTag("containerItem_aux_"+Util::toString(i)).get();
		std::string customName=tag.getStringTag("containerItem_customName_"+Util::toString(i)).get();
		short repair=tag.getIntTag("containerItem_repair_"+Util::toString(i)).get();
		bool hasCustomName=tag.getBoolTag("containerItem_hasCustomName_"+Util::toString(i)).get();
		
		item.init(id,count,aux);
		if(hasCustomName)
			item.setCustomName(customName);
		item.setRepairCost(repair);
		
		if(id==0)
			item.setNull();
		
		if(!item.isNull())
		{
			for(int ii=0;ii<25;++ii)
			{
				short level=tag.getShortTag("containerItem_enchant_"+Util::toString(i)+"_"+Util::toString(ii)).get();
				if(level>0)
					EnchantUtils::applyEnchant(item,ii,level);
			}
		}
		slots[i]=item;
	}
}
void ContainerBlockEntity::save(mca::ComposedTag&tag)
{
	for(int i=0;i<slotsCount;++i)
	{
		if(slots[i].isNull())
		{
			tag.getShortTag("containerItem_count_"+Util::toString(i)).reset(0);
			tag.getShortTag("containerItem_id_"+Util::toString(i)).reset(0);
			tag.getShortTag("containerItem_aux_"+Util::toString(i)).reset(0);
			tag.getStringTag("containerItem_customName_"+Util::toString(i)).reset("");
			tag.getIntTag("containerItem_repair_"+Util::toString(i)).reset(0);
			tag.getBoolTag("containerItem_hasCustomName_"+Util::toString(i)).reset(false);
		}
		else
		{
			tag.getShortTag("containerItem_count_"+Util::toString(i)).reset(slots[i].count);
			tag.getShortTag("containerItem_id_"+Util::toString(i)).reset(slots[i].getId());
			tag.getShortTag("containerItem_aux_"+Util::toString(i)).reset(slots[i].getAuxValue());
			tag.getBoolTag("containerItem_hasCustomName_"+Util::toString(i)).reset(slots[i].hasCustomHoverName());
			if(slots[i].hasCustomHoverName())
				tag.getStringTag("containerItem_customName_"+Util::toString(i)).reset(slots[i].getCustomName());
			else
				tag.getStringTag("containerItem_customName_"+Util::toString(i)).reset("");
			tag.getIntTag("containerItem_repair_"+Util::toString(i)).reset(slots[i].getBaseRepairCost());
			for(int ii=0;ii<25;++ii)
			{
				if(EnchantUtils::hasEnchant(ii,slots[i]))
					tag.getShortTag("containerItem_enchant_"+Util::toString(i)+"_"+Util::toString(ii)).reset(EnchantUtils::getEnchantLevel(ii,slots[i]));
				else
					tag.getShortTag("containerItem_enchant_"+Util::toString(i)+"_"+Util::toString(ii)).reset(0);
			}
		}
	}
}
