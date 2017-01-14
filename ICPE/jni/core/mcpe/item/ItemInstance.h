#pragma once

#include <memory>

#include "UseAnimation.h"
#include "../Util/BlockID.h"

class CompoundTag;
class Item;
class Block;
class ItemEnchants;
class Mob;
class Entity;
class Player;
class Color;
class UseDuration;
class Level;

class ItemInstance
{
public:
    unsigned char count;
    unsigned short aux;
    CompoundTag* userData;
    bool valid;
    Item* item;
    Block* block;
public:
    ItemInstance(ItemInstance const&);
	ItemInstance(bool);
	ItemInstance(int, int, int);
	ItemInstance();
	ItemInstance(Item const*, int, int, CompoundTag const*);
	ItemInstance(Item const*, int);
	ItemInstance(Item const*);
	ItemInstance(Block const*);
	ItemInstance(int, int, int, CompoundTag const*);
	ItemInstance(Item const*, int, int);
	ItemInstance(Block const*, int);
	ItemInstance(Block const*, int, int);
public:
	int getAuxValue() const;
	int getId() const;
	void operator=(ItemInstance const&);
	void getStrippedNetworkItem() const;
	void onCraftedBy(Level&, Player&);
	void setNull();
	bool isNull() const;
	int getMaxStackSize() const;
	std::string getName() const;
	void cloneSafe(ItemInstance const*);
	bool isStackable(ItemInstance const*, ItemInstance const*);
	void save();
	void remove(int);
	void fromTag(CompoundTag const&);
	void getUserData() const;
	void hasUserData() const;
	bool isWearableItem(ItemInstance const*);
	void add(int);
	bool isEnchanted() const;
	int getEnchantValue() const;
	void setAuxValue(short);
	void setCustomName(std::string const&);
	void setRepairCost(int);
	void resetHoverName();
	int getMaxDamage() const;
	int getDamageValue() const;
	bool isDamageableItem() const;
	bool isEnchantingBook() const;
	int getBaseRepairCost() const;
	bool hasCustomHoverName() const;
	bool isPotionItem(ItemInstance const*);
	void setJustBrewed(bool);
	bool wasJustBrewed() const;
	bool sameItemAndAux(ItemInstance const*) const;
	int getIdAuxEnchanted() const;
	std::string getEffectName() const;
	void matches(ItemInstance const*, ItemInstance const*);
	void inventoryTick(Level&, Entity&, int, bool);
	void set(int);
	bool useOn(Entity&, int, int, int, signed char, float, float, float);
	bool isFullStack() const;
	void getRawNameId() const;
	void setUserData(std::unique_ptr<CompoundTag, std::default_delete<CompoundTag> >);
	void hurtAndBreak(int, Entity*);
	void getUseAnimation() const;
	void getIdAux() const;
	void load(CompoundTag const&);
	bool isArmorItem(ItemInstance const*);
	void getAttackDamage();
	void getIcon(int, bool) const;
	bool hasSameUserData(ItemInstance const&) const;
	void releaseUsing(Player*, int);
	void interactEnemy(Mob*, Player*);
	void startCoolDown(Player*);
	float getDestroySpeed(Block const*);
	void useTimeDepleted(Level*, Player*);
	bool canDestroySpecial(Block const*);
	void hurtEnemy(Mob*, Mob*);
	UseDuration getMaxUseDuration() const;
	void operator==(ItemInstance const&) const;
	void operator!=(ItemInstance const&) const;
	bool isLiquidClipItem();
	void use(Player&);
	void mineBlock(BlockID, int, int, int, Mob*);
	std::string getHoverName() const;
	bool isStackable() const;
	bool isStackedByData() const;
	bool isDamaged() const;
	std::string getCustomName() const;
	void saveEnchantsToUserData(ItemEnchants const&);
	void getEnchantsFromUserData() const;
	void matchesNulls(ItemInstance const*, ItemInstance const*);
	void isHorseArmorItem(ItemInstance const*);
	void setDescriptionId(std::string const&);
	void isEquivalentArmor(ItemInstance const&);
	void retrieveIDFromIDAux(int);
	void retrieveAuxValFromIDAux(int);
	void retrieveEnchantFromIDAux(int);
	void init(int, int, int);
	void snap(Player*);
	void _setItem(int);
	void useAsFuel();
	bool isThrowable() const;
	int getEnchantSlot() const;
	void getNetworkUserData() const;
	void getFormattedHovertext(Level&, bool) const;
	void _getHoverFormattingPrefix() const;
	bool isGlint() const;
	bool matches(ItemInstance const*) const;
	Color getColor() const;
	std::string toString() const;
public:
	static bool isItem(ItemInstance const*);
	static ItemInstance* clone(ItemInstance const*);
public:
	static std::string const TAG_ENCHANTS;
	static std::string const TAG_DISPLAY;
	static std::string const MAX_STACK_SIZE;
	static std::string const TAG_REPAIR_COST;
	static std::string const TAG_DISPLAY_NAME;
};
