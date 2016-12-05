#include "RubberWoodBlock.h"

#include "blocks/Blocks.h"
#include "util/ICRandom.h"
#include "client/ICClient.h"

#include "mcpe/level/BlockSource.h"
#include "mcpe/item/ItemInstance.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/block/blocks/FireBlock.h"

RubberWoodBlock::RubberWoodBlock():IC::Blocks("ic.rubber.wood",IC::Blocks::ID::mRubberWood,Material::getMaterial(MaterialType::WOOD))
{
	init();
	//setSoundType(BlockSoundType::SOUND_DEFAULT);
	setCategory(CreativeItemCategory::DECORATIONS);
	setExplodeable(10);
	setDestroyTime(2);
	setTicking(true);
	
	((FireBlock*)mFire)->setFlammable(BlockID(IC::Blocks::ID::mRubberWood),50,10);
}
void RubberWoodBlock::tick(BlockSource&s, BlockPos const&pos, Random&)
{
	if(ICClient::mInstance.getRandom().nextInt(7)==5&&s.getData(pos)==1)
		s.setBlockAndData(pos,FullBlock(IC::Blocks::ID::mRubberWood,2),3);
}
int RubberWoodBlock::getSpawnResourcesAuxValue(unsigned char)
{
	return 0;
}
int RubberWoodBlock::getPlacementDataValue(Mob&, BlockPos const&, signed char, Vec3 const&, int aux)
{
	return aux;
}
