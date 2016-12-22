#include "GuideBookItem.h"

#include "mcpe/client/resources/I18n.h"

#include "ui/UIScreenChooser.h"

#include "ICPE.h"

GuideBookItem::GuideBookItem():IC::Items("guide_book",IC::Items::ID::mGuideBook-256)
{
	setCategory(CreativeItemCategory::ITEMS);
	setIcon("book_written",0);
	setMaxStackSize(1);
	setIsGlint(true);
}
std::string GuideBookItem::buildEffectDescriptionName(ItemInstance const&) const
{
	return "§7"+I18n::get("ic.guidebook.effect");
}
void GuideBookItem::useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float)
{
	ICPE::mUIScreenChooser.pushGuideBookScreen();
}
bool GuideBookItem::isEmissive(int) const
{
	return true;
}
