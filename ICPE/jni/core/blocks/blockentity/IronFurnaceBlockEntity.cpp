#include "IronFurnaceBlockEntity.h"

#include <stdlib.h>
#include <cmath>

#include "mcpe/item/ItemInstance.h"
#include "mcpe/blockentity/FurnaceBlockEntity.h"
#include "mcpe/recipe/FurnaceRecipes.h"

#include "mca/data/Database.h"
#include "util/Log.h"

const float IronFurnaceBlockEntity::mSpeed=0.01F;

IronFurnaceBlockEntity::IronFurnaceBlockEntity(BlockSource&s,BlockPos const&pos,Block const*b):ContainerBlockEntity(s,pos,b,3)
{
	fireProgress=0.0F;
	maxFireProgress=0.0F;
	burnProgress=0.0F;
	isLit_=false;
}
void IronFurnaceBlockEntity::load(mca::ComposedTag &tag)
{
	ContainerBlockEntity::load(tag);
	
	fireProgress=tag.getFloatTag("fireProgress").get();
	maxFireProgress=tag.getFloatTag("maxFireProgress").get();
	burnProgress=tag.getFloatTag("burnProgress").get();
	isLit_=tag.getBoolTag("isLit").get();
}
void IronFurnaceBlockEntity::save(mca::ComposedTag &tag)
{
	ContainerBlockEntity::save(tag);
	
	tag.getFloatTag("maxFireProgress").reset(maxFireProgress);
	tag.getFloatTag("fireProgress").reset(fireProgress);
	tag.getFloatTag("burnProgress").reset(burnProgress);
	tag.getBoolTag("isLit").reset(isLit_);
}
void IronFurnaceBlockEntity::tick(Level&)
{
	if(burnProgress>=1.0F)
	{
		if(!getSlot(0)||getSlot(0)->isNull())
		{
			LOG_E("Slot [0] is empty.");
			goto burnEnd;
		}
		ItemInstance item=FurnaceRecipes::getInstance()->getResult(getSlot(0));
		if(item.isNull())
		{
			LOG_E("Burn result is empty.");
			goto burnEnd;
		}
		if(!getSlot(2)||getSlot(2)->isNull())
			setSlot(2,&item);
		else
			++getSlot(2)->count;
		getSlot(0)->remove(1);
		burnProgress=0.0F;
	}
	else if(burnProgress>0.0F&&burnProgress<1.0F)
	{
		if(canBurn())
			burnProgress+=mSpeed;
		else if(!getSlot(0)||getSlot(0)->isNull())
			burnProgress=0.0F;
		else
			burnProgress-=(mSpeed*2);
	}
	else if(burnProgress==0.0F)
	{
		if(canBurn())
			burnProgress=mSpeed;
	}
	else
		burnProgress=0.0F;
	
	burnEnd:;

	if(fireProgress>0)
		fireProgress-=2E-45;
	else
		fireProgress=0;
	if(canStartNextFire())
	{
		maxFireProgress=fireProgress=FurnaceBlockEntity::getBurnDuration(getSlot(1));
		if(getSlot(1)->getId()!=325&&getSlot(1)->getAuxValue()!=10)
			getSlot(1)->remove(1);
		else
			getSlot(1)->aux=0;
	}
	if(fireProgress>0&&!isLit())
		setLit(true);
	else if(fireProgress<=0&&isLit())
		setLit(false);
}
bool IronFurnaceBlockEntity::isLit()const
{
	return isLit_;
}
void IronFurnaceBlockEntity::setLit(bool b)
{
	isLit_=b;
	update();
}
bool IronFurnaceBlockEntity::canPushInItem(int s,ItemInstance const&i)
{
	if(getSlot(s)&&!getSlot(s)->isNull()&&getSlot(s)->getId()!=i.getId())
		return false;
	if(s==1&&FurnaceBlockEntity::getBurnDuration(&i)>0.0F)
		return true;
	if(s==0)
		return true;
	return false;
}
float IronFurnaceBlockEntity::getBurnProgress()const
{
	if(burnProgress>=0.0F)
		return burnProgress;
	return 0.0F;
}
float IronFurnaceBlockEntity::getFireProgress()const
{
	float _fireProgress=abs(fireProgress*1E45);
	float _maxFireProgress=abs(maxFireProgress*1E45);
	float ret=(((float)_fireProgress)/((float)_maxFireProgress));
	if(_maxFireProgress==0.0F)
		return 0;
	if(ret<0)
		return 0;
	return ret;
}
bool IronFurnaceBlockEntity::canBurn()
{
	if(fireProgress*1E45<=0)
		return false;
	if(!getSlot(0)||getSlot(0)->isNull())
		return false;
	if(FurnaceRecipes::mInstance->isFurnaceItem(getSlot(0)))
	{
		if(getSlot(2)&&!getSlot(2)->isNull())
		{
			if(FurnaceRecipes::getInstance()->getResult(getSlot(0)).sameItemAndAux(getSlot(2))&&!getSlot(2)->isFullStack())
				return true;
			return false;
		}
		else
			return true;
	}
	return false;
}
bool IronFurnaceBlockEntity::canStartNextFire()
{
	if(!(((fireProgress*1E45)<=0.0F)&&getSlot(0)&&getSlot(1)&&!getSlot(0)->isNull()&&!getSlot(1)->isNull()&&FurnaceRecipes::getInstance()->isFurnaceItem(getSlot(0))&&(FurnaceBlockEntity::getBurnDuration(getSlot(1))*1E15>0.0F)))
		return false;
	if(getSlot(2)&&!getSlot(2)->isNull())
	{
		if(FurnaceRecipes::getInstance()->getResult(getSlot(0)).sameItemAndAux(getSlot(2))&&!getSlot(2)->isFullStack())
			return true;
		return false;
	}
	else
		return true;
}
