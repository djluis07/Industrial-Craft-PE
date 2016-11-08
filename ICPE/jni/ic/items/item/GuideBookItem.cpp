#include "GuideBookItem.h"

#include "ic/client/ICClient.h"

GuideBookItem::GuideBookItem():IC::Items("guide_book",IC::Items::ID::mGuideBook-256)
{
	setCategory(CreativeItemCategory::ITEMS);
	setIcon("book_written",0);
	setMaxStackSize(1);
}
std::string GuideBookItem::getInteractText(Player const&) const
{
	return "open";
}
bool GuideBookItem::requiresInteract() const
{
	return true;
}
void GuideBookItem::use(ItemInstance&, Player&)
{
	ICClient::mInstance.getScreenChooser()->pushGuideBookScreen();
}
