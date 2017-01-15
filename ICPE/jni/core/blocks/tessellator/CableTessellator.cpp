#include "CableTessellator.h"

#include "blocks/blockentity/CableBlockEntity.h"
#include "blocks/Blocks.h"
#include "util/CableUtil.h"
#include "icpe.h"
#include "mcpe/util/random.h"

bool CableTessellator::tessellate(Block const&b,BlockPos const&pos,unsigned char aux,bool wtf)
{
	float defaultDistance=0.3125;
	if(CableUtil::isGlassCable(aux))
		defaultDistance=0.375;
	else if(CableUtil::isHeavyCable(aux))
		defaultDistance=0.25;
	
	unsigned char maux=((CableBlockEntity*)blockSource->getICBlockEntity(pos))->getTextureAux();
	
	if(isElectricBlockAt(pos,{pos.x,pos.y+1,pos.z}))
		_setShapeAndTessellate({defaultDistance,1-defaultDistance,defaultDistance},{1-defaultDistance,1,1-defaultDistance},b,pos,maux);
	if(isElectricBlockAt(pos,{pos.x,pos.y-1,pos.z}))
		_setShapeAndTessellate({defaultDistance,0,defaultDistance},{1-defaultDistance,defaultDistance,1-defaultDistance},b,pos,maux);
	if(isElectricBlockAt(pos,{pos.x,pos.y,pos.z+1}))
		_setShapeAndTessellate({defaultDistance,defaultDistance,1-defaultDistance},{1-defaultDistance,1-defaultDistance,1},b,pos,maux);
	if(isElectricBlockAt(pos,{pos.x,pos.y,pos.z-1}))
		_setShapeAndTessellate({defaultDistance,defaultDistance,0},{1-defaultDistance,1-defaultDistance,defaultDistance},b,pos,maux);
	if(isElectricBlockAt(pos,{pos.x+1,pos.y,pos.z}))
		_setShapeAndTessellate({1-defaultDistance,defaultDistance,defaultDistance},{1,1-defaultDistance,1-defaultDistance},b,pos,maux);
	if(isElectricBlockAt(pos,{pos.x-1,pos.y,pos.z}))
		_setShapeAndTessellate({0,defaultDistance,defaultDistance},{defaultDistance,1-defaultDistance,1-defaultDistance},b,pos,maux);
	_setShapeAndTessellate({defaultDistance,defaultDistance,defaultDistance},{1-defaultDistance,1-defaultDistance,1-defaultDistance},b,pos,maux);
	return true;
}
bool CableTessellator::isElectricBlockAt(BlockPos const&p1,BlockPos const&p2)
{
	return CableUtil::canConnectTo(*blockSource,p1,p2);
}
