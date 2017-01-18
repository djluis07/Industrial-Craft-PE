#pragma once

#include "ContainerBlockEntity.h"

class IronFurnaceBlockEntity : public ContainerBlockEntity
{
private:
	bool isLit_;
	float burnProgress;
	float fireProgress;
	float maxFireProgress;
public:
	IronFurnaceBlockEntity(BlockSource&,BlockPos const&,Block const*);
	~IronFurnaceBlockEntity()=default;
public:
	virtual void load(mca::ComposedTag &);
	virtual void save(mca::ComposedTag &);
	virtual void tick(Level&);
public:
	bool canPushInItem(int,ItemInstance const&);
	bool isLit()const;
	void setLit(bool);
	float getBurnProgress()const;
	float getFireProgress()const;
	bool canBurn();
	bool canStartNextFire();
public:
	static const float mSpeed;
};
