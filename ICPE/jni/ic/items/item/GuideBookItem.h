#pragma once

#include "ic/items/Items.h"

class GuideBookItem : public IC::Items
{
public:
	GuideBookItem();
public:
    virtual void use(ItemInstance&, Player&);
    virtual std::string getInteractText(Player const&) const;
    virtual bool requiresInteract() const;
};
