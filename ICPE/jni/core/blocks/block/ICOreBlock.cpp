#include "ICOreBlock.h"

#include "mcpe/client/resources/I18n.h"
#include "mcpe/item/ItemInstance.h"

ICOreBlock::ICOreBlock():IC::Blocks("ic.ore.tin",IC::Blocks::ID::mOre,Material::getMaterial(MaterialType::METAL))
{
	init();
	//setSoundType(BlockSoundType::SOUND_DEFAULT);
	setSolid(true);
	setDestroyTime(3);
	setExplodeable(15);
	setCategory(CreativeItemCategory::BLOCKS);
}
std::string ICOreBlock::buildDescriptionName(unsigned char aux) const
{
	switch(aux)
	{
	case 0:
	default:
		return I18n::get("ic.ore.tin");
	case 1:
		return I18n::get("ic.ore.copper");
	case 2:
		return I18n::get("ic.ore.lead");
	case 3:
		return I18n::get("ic.ore.uranium");
	}
}
int ICOreBlock::getSpawnResourcesAuxValue(unsigned char aux)const
{
	return aux;
}
int ICOreBlock::getPlacementDataValue(Entity&, BlockPos const&, signed char, Vec3 const&, int aux)const
{
	return aux;
}
