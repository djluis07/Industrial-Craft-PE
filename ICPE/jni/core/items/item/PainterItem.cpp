#include "PainterItem.h"

#include "mcpe/client/resources/I18n.h"
#include "mcpe/util/Util.h"
#include "mcpe/entity/Mob.h"
#include "mcpe/entity/EntityType.h"
#include "mcpe/entity/EntityClassTree.h"
#include "mcpe/entity/player/Player.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/block/Block.h"
#include "blocks/blockentity/CableBlockEntity.h"
#include "blocks/blocks.h"
#include "util/CableUtil.h"

PainterItem::PainterItem(std::string const&name,int id,std::string const&tex):IC::Items(name,id)
{
	setCategory(CreativeItemCategory::TOOLS);
	setMaxDamage(32);
	setIcon(tex,0);
	setMaxStackSize(1);
}
void PainterItem::useOn(ItemInstance&item, Entity&ent, int x, int y, int z, signed char, float, float, float)
{
	PaletteColor colorType;
	switch(item.getId())
	{
	case ID::mPainterWhite:
		colorType=PaletteColor::WHITE;
	break;
	case ID::mPainterOrange:
		colorType=PaletteColor::ORANGE;
	break;
	case ID::mPainterMagenta:
		colorType=PaletteColor::MAGENTA;
	break;
	case ID::mPainterLightBlue:
		colorType=PaletteColor::LIGHTBLUE;
	break;
	case ID::mPainterYellow:
		colorType=PaletteColor::YELLOW;
	break;
	case ID::mPainterLime:
		colorType=PaletteColor::LIME;
	break;
	case ID::mPainterPink:
		colorType=PaletteColor::PINK;
	break;
	case ID::mPainterBrown:
		colorType=PaletteColor::BROWN;
	break;
	case ID::mPainterCyan:
		colorType=PaletteColor::CYAN;
	break;
	case ID::mPainterGray:
		colorType=PaletteColor::GRAY;
	break;
	case ID::mPainterRed:
		colorType=PaletteColor::RED;
	break;
	case ID::mPainterGreen:
		colorType=PaletteColor::GREEN;
	break;
	case ID::mPainterBlue:
		colorType=PaletteColor::BLUE;
	break;
	case ID::mPainterPurple:
		colorType=PaletteColor::PURPLE;
	break;
	case ID::mPainterLightGray:
		colorType=PaletteColor::LIGHTGRAY;
	break;
	case ID::mPainterBlack:
		colorType=PaletteColor::BLACK;
	break;
	}

	if(ent.getRegion().getBlock(x,y,z)==Block::mBlocks[35])
		ent.getRegion().setBlockAndData(x,y,z,35,(unsigned char)colorType,3);
	else if(ent.getRegion().getBlock(x,y,z)==Block::mBlocks[171])
		ent.getRegion().setBlockAndData(x,y,z,171,(unsigned char)colorType,3);
	else if(ent.getRegion().getBlock(x,y,z)==Block::mBlocks[172])
		ent.getRegion().setBlockAndData(x,y,z,159,(unsigned char)colorType,3);
	else if(ent.getRegion().getBlock(x,y,z)==Block::mBlocks[159])
		ent.getRegion().setBlockAndData(x,y,z,159,(unsigned char)colorType,3);
	else if(ent.getRegion().getBlock(x,y,z)==Block::mBlocks[IC::Blocks::ID::mCable]&&CableUtil::canDye(ent.getRegion().getData(x,y,z)))
		((CableBlockEntity*)ent.getRegion().getICBlockEntity(x,y,z))->setColor((unsigned char)colorType);
	else
		return;
	if(item.aux<(getMaxDamage()-1))
		item.hurtAndBreak(1,0);
	else
		item=ItemInstance(ID::mPainter,1,0);
}
std::string PainterItem::buildEffectDescriptionName(ItemInstance const&i) const
{
	return "§7"+I18n::get("ic.effectname.lastuses")+":"+Util::toString(32-i.aux)+"/32";
}
void PainterItem::interactEnemy(ItemInstance*item, Mob*mob, Player*player)
{
	if(!mob||!player||!item||!EntityClassTree::isInstanceOf(*mob,EntityType::SHEEP))
		return;
	PaletteColor colorType;
	switch(item->getId())
	{
	case ID::mPainterWhite:
		colorType=PaletteColor::WHITE;
	break;
	case ID::mPainterOrange:
		colorType=PaletteColor::ORANGE;
	break;
	case ID::mPainterMagenta:
		colorType=PaletteColor::MAGENTA;
	break;
	case ID::mPainterLightBlue:
		colorType=PaletteColor::LIGHTBLUE;
	break;
	case ID::mPainterYellow:
		colorType=PaletteColor::YELLOW;
	break;
	case ID::mPainterLime:
		colorType=PaletteColor::LIME;
	break;
	case ID::mPainterPink:
		colorType=PaletteColor::PINK;
	break;
	case ID::mPainterBrown:
		colorType=PaletteColor::BROWN;
	break;
	case ID::mPainterCyan:
		colorType=PaletteColor::CYAN;
	break;
	case ID::mPainterGray:
		colorType=PaletteColor::GRAY;
	break;
	case ID::mPainterRed:
		colorType=PaletteColor::RED;
	break;
	case ID::mPainterGreen:
		colorType=PaletteColor::GREEN;
	break;
	case ID::mPainterBlue:
		colorType=PaletteColor::BLUE;
	break;
	case ID::mPainterPurple:
		colorType=PaletteColor::PURPLE;
	break;
	case ID::mPainterLightGray:
		colorType=PaletteColor::LIGHTGRAY;
	break;
	case ID::mPainterBlack:
		colorType=PaletteColor::BLACK;
	break;
	}
	mob->setColor(colorType);
	ItemInstance item_(351,1,(int)colorType);
	mDye_powder->interactEnemy(&item_,mob,player);
	
	if(player->isCreative())
		return;
	if(item->aux<(getMaxDamage()-1))
		item->hurtAndBreak(1,0);
	else
		(*item)=ItemInstance(ID::mPainter,1,0);
}
