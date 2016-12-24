#include "CircuitItem.h"

#include "mcpe/client/resources/I18n.h"

CircuitItem::CircuitItem():IC::Items("ic.circuit",IC::Items::ID::mCircuit-0x100)
{
	setCategory(CreativeItemCategory::ITEMS);
	setStackedByData(true);
	
	circuitTextures[0]=getTextureUVCoordinateSet("icpe_circuit",0);
	circuitTextures[1]=getTextureUVCoordinateSet("icpe_advanced_circuit",0);
}
std::string CircuitItem::buildDescriptionName(const ItemInstance&i) const
{
	switch(i.aux)
	{
	case 0:
	default:
		return I18n::get("ic.circuit");
	case 1:
		return I18n::get("ic.circuit.advanced");
	}
}
const TextureUVCoordinateSet& CircuitItem::getIcon(int aux, int, bool) const
{
	return circuitTextures[aux>=(sizeof(circuitTextures)/sizeof(TextureUVCoordinateSet))?0:aux];
}
