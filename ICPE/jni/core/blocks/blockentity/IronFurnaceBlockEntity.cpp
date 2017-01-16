#include "IronFurnaceBlockEntity.h"

#include "mcpe/item/ItemInstance.h"
#include "mca/data/Database.h"

IronFurnaceBlockEntity::IronFurnaceBlockEntity(BlockSource&s,BlockPos const&pos,Block const*b)
:ContainerBlockEntity(s,pos,b,3)
{
	fireProgress=0.0F;
	burnProgress=0.0F;
	isLit_=false;
}
void IronFurnaceBlockEntity::load(mca::ComposedTag &tag)
{
	ContainerBlockEntity::load(tag);
	
	fireProgress=tag.getFloatTag("fireProgress").get();
	burnProgress=tag.getFloatTag("burnProgress").get();
	isLit_=tag.getBoolTag("isLit").get();
}
void IronFurnaceBlockEntity::save(mca::ComposedTag &tag)
{
	ContainerBlockEntity::save(tag);
	
	tag.getFloatTag("fireProgress").reset(fireProgress);
	tag.getFloatTag("burnProgress").reset(burnProgress);
	tag.getBoolTag("isLit").reset(isLit_);
}
void IronFurnaceBlockEntity::tick(Level&)
{
	
}
void IronFurnaceBlockEntity::pushInItem(int slot,ItemInstance&item)
{
	//if(canPushInItem(slot,item))
		
}
ItemInstance IronFurnaceBlockEntity::pullOutItem(int s,short count)
{
	if(getSlot(s)&&getSlot(s)->count>0)
	{
		ItemInstance copy=*getSlot(s);
		copy.remove(count);
		costItem(s,count);
		return copy;
	}
	return ItemInstance();
}
ItemInstance* IronFurnaceBlockEntity::getItem(int s)
{
	return getSlot(s);
}
bool IronFurnaceBlockEntity::isLit()const
{
	return isLit_;
}
void IronFurnaceBlockEntity::setLit(bool b)
{
	isLit_=b;
}
bool IronFurnaceBlockEntity::canPushInItem(int s,ItemInstance const&i)
{
	if(getSlot(s)&&!getSlot(s)->isNull()&&getSlot(s)->getId()!=i.getId())
		return false;
	return true;
}
void IronFurnaceBlockEntity::setItem(int s,ItemInstance const*i)
{
	setSlot(s,i);
}
