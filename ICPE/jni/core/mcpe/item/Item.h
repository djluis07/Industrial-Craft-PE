#pragma once

#include <string>
#include <memory>
#include <vector>

#include "CreativeItemCategory.h"
#include "UseAnimation.h"
#include "ItemInstance.h"
#include "mcpe/util/BlockID.h"
#include "mcpe/block/BlockShape.h"
#include "../client/renderer/texture/TextureUVCoordinateSet.h"

class TextureUVCoordinateSet;
class SeedItemComponent;
class FoodItemComponent;
class CameraItemComponent;
class Block;
class ItemInstance;
class Entity;
class Mob;
class Level;
class Player;
class Container;
class BlockSource;
class Vec3;
class IDataInput;
class IDataOutput;
namespace Json
{ 
	class Value; 
};

class Item 
{
public:
	/* constructor */
	Item(const std::string&, short);

	/* fields */
	char filler[200];//56

	/* list */
	static Item* mItems[4096];
	static std::vector<ItemInstance> mCreativeList;

	/* vtable */
	virtual ~Item();
    virtual Item* setIcon(std::string const&, int);
    virtual Item* setIcon(TextureUVCoordinateSet const&);
    virtual Item* setMaxStackSize(unsigned char);
    virtual Item* setCategory(CreativeItemCategory);
    virtual Item* setStackedByData(bool);
    virtual Item* setMaxDamage(int);
    virtual Item* setHandEquipped();
    virtual Item* setUseAnimation(UseAnimation);
    virtual Item* setMaxUseDuration(int);
    virtual Item* setRequiresWorldBuilder(bool);
    virtual Item* setExplodable(bool);
    virtual Item* setIsGlint(bool);
    virtual Item* setShouldDespawn(bool);
    virtual BlockShape getBlockShape() const;
    virtual bool canBeDepleted();
    virtual bool canDestroySpecial(Block const*) const;
    virtual int getLevelDataForAuxValue(int) const;
    virtual bool isStackedByData() const;
    virtual int getMaxDamage();
    virtual int getAttackDamage();
    virtual bool isHandEquipped() const;
    virtual bool isArmor() const;
    virtual bool isDye() const;
    virtual bool isGlint(ItemInstance const*) const;
    virtual bool isThrowable() const;
    virtual bool canDestroyInCreative() const;
    virtual bool isLiquidClipItem(int) const;
    virtual bool requiresInteract() const;
    virtual std::string appendFormattedHovertext(ItemInstance const&, Level&, std::string&, bool) const;
    virtual bool isValidRepairItem(ItemInstance const&, ItemInstance const&);
    virtual int getEnchantSlot() const;
    virtual int getEnchantValue() const;
    virtual bool isComplex() const;
    virtual bool isValidAuxValue(int) const;
    virtual int getDamageChance(int) const;
    virtual bool uniqueAuxValues() const;
    virtual int getColor(ItemInstance const&) const;
    virtual void use(ItemInstance&, Player&);
    virtual void useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
    virtual void dispense(BlockSource&, Container&, int, Vec3 const&, signed char);
    virtual void useTimeDepleted(ItemInstance*, Level*, Player*);
    virtual void releaseUsing(ItemInstance*, Player*, int);
    virtual float getDestroySpeed(ItemInstance*, Block const*);
    virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
    virtual void interactEnemy(ItemInstance*, Mob*, Player*);
    virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
    virtual std::string buildDescriptionName(ItemInstance const&) const;
    virtual std::string buildEffectDescriptionName(ItemInstance const&) const;
    virtual void readUserData(ItemInstance*, IDataInput&) const;
    virtual void writeUserData(ItemInstance const*, IDataOutput&) const;
    virtual void getMaxStackSize(ItemInstance const*);
    virtual void inventoryTick(ItemInstance&, Level&, Entity&, int, bool);
    virtual void onCraftedBy(ItemInstance&, Level&, Player&);
    virtual int getCooldownType() const;
    virtual int getCooldownTime() const;
    virtual std::string getInteractText(Player const&) const;
    virtual int getAnimationFrameFor(Mob&) const;
    virtual bool isEmissive(int) const;
    virtual TextureUVCoordinateSet const& getIcon(int, int, bool) const;
    virtual int getIconYOffset() const;
    virtual bool isMirroredArt() const;
	
	static void initClientData();
	static void initCreativeItems();
	static void addCreativeItem(short,short);
	static TextureUVCoordinateSet getTextureUVCoordinateSet(std::string const&,int);
	
	static Item* mSword_diamond;
	static Item* mShears;
	static Item* mHatchet_diamond;
	static Item* mHoe_iron;
	
};
