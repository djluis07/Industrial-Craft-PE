#pragma once

#include "ICBlockEntity.h"

#include "mcpe/entity/PaletteColor.h"

class CableBlockEntity : public ICBlockEntity
{
private:
	bool foamed;
	unsigned short colorType;
	unsigned short foamColor;
	int foamHard;
public:
	CableBlockEntity(BlockSource&,BlockPos const&,Block const*);
	~CableBlockEntity()=default;
public:
	virtual void tick(Level&);
	virtual void load(mca::ComposedTag &);
	virtual void save(mca::ComposedTag &);
	virtual void remove();
public:
	unsigned char getColor()const;
	unsigned char getFoamColor()const;
	void setColor(unsigned char);
	void setFoamColor(unsigned char);
	unsigned char getTextureAux()const;
	void setFoamed(bool);
	void finishFoam();
	float getFoamHard()const;
	bool isFoamed()const;
};
