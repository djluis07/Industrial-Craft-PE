#pragma once

#include <vector>

#include "ICBlockEntity.h"

class ItemInstance;

class ContainerBlockEntity : public ICBlockEntity
{
private:
	int const slotsCount;
	std::vector<ItemInstance>slots;
public:
	ContainerBlockEntity(BlockSource&,BlockPos const&,Block const*,int);
	~ContainerBlockEntity()=default;
public:
	virtual void onSlotChanged(int);
	virtual void addItem(int,short);
	virtual bool isEmptySlot(int);
	virtual ItemInstance* getSlot(int);
	virtual void setSlot(int,ItemInstance const*);
	virtual void costItem(int,short);
	virtual void load(mca::ComposedTag&);
	virtual void save(mca::ComposedTag&);
};
