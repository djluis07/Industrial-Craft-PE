#pragma once

#include "ContainerBlockEntity.h"

class IronFurnaceBlockEntity : public ContainerBlockEntity
{
private:
	bool isLit_;
	float burnProgress;
	float fireProgress;
public:
	IronFurnaceBlockEntity(BlockSource&,BlockPos const&,Block const*);
	~IronFurnaceBlockEntity()=default;
public:
	virtual void load(mca::ComposedTag &);
	virtual void save(mca::ComposedTag &);
	virtual void tick(Level&);
public:
	void pushInItem(int,ItemInstance&);
	bool canPushInItem(int,ItemInstance const&);
	ItemInstance pullOutItem(int,short);
	ItemInstance* getItem(int);
	void setItem(int,ItemInstance const*);
	bool isLit()const;
	void setLit(bool);
};
