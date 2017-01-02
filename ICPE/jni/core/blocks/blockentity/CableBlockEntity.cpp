#include "CableBlockEntity.h"

#include "mca/data/tag/ComposedTag.h"
#include "util/CableUtil.h"
#include "mcpe/level/BlockSource.h"

CableBlockEntity::CableBlockEntity(BlockSource&s,BlockPos const&pos,Block const*b):ICBlockEntity(s,pos,b)
{
	foamed=false;
	colorType=15;
	foamColor=15;
	foamHard=0;
}
void CableBlockEntity::tick(Level&)
{
	if(foamed&&foamHard<1000)
		++foamHard;
}
void CableBlockEntity::load(mca::ComposedTag&tag)
{
	foamed=tag.getBoolTag("foamed").get();
	colorType=(unsigned short)tag.getUshortTag("colorType").get();
	foamColor=(unsigned short)tag.getUshortTag("foamColor").get();
	foamHard=tag.getIntTag("foamHard").get();
}
void CableBlockEntity::save(mca::ComposedTag&tag)
{
	tag.getBoolTag("foamed").reset(foamed);
	tag.getUshortTag("foamColor").reset((unsigned short)foamColor);
	tag.getUshortTag("colorType").reset((unsigned short)colorType);
	tag.getIntTag("foamHard").reset(foamHard);
}
void CableBlockEntity::remove()
{
	
}
unsigned char CableBlockEntity::getColor()const
{
	return colorType;
}
unsigned char CableBlockEntity::getFoamColor()const
{
	return foamColor;
}
void CableBlockEntity::setColor(unsigned char c)
{
	colorType=c;
	update();
}
void CableBlockEntity::setFoamColor(unsigned char c)
{
	foamColor=c;
	update();
}
unsigned char CableBlockEntity::getTextureAux()const
{
	return CableUtil::dye(source.getData(pos),getColor());
}
void CableBlockEntity::setFoamed(bool b)
{
	foamHard=0;
	foamed=b;
	update();
}
void CableBlockEntity::finishFoam()
{
	foamHard=1000;
	update();
}
float CableBlockEntity::getFoamHard()const
{
	return ((float)foamHard)/((float)1000);
}
bool CableBlockEntity::isFoamed()const
{
	return foamed;
}
