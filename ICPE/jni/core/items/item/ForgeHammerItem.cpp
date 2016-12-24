#include "ForgeHammerItem.h"

ForgeHammerItem::ForgeHammerItem():IC::Items("ic.forgehammer",IC::Items::ID::mForgeHammer-0x100)
{
	setIcon("icpe_forge_hammer",0);
	setMaxStackSize(70);
	setCategory(CreativeItemCategory::TOOLS);
}
