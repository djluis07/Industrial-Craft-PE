#include "ICRecipes.h"

#include "RecipeUtil.h"

#include "ic/blocks/Blocks.h"
#include "ic/items/Items.h"

void ICRecipes::addRecipes(Recipes&r,FurnaceRecipes&fr)
{
	//addItemRecipes(r);
	//addFurnaceRecipes(fr);
}
void ICRecipes::addItemRecipes(Recipes&r)
{
	RecipeUtil ru(&r,0);
	
	ru.addRecipeType(IC::Blocks::ID::mRubberWood,'w');
	ru.addShapedRecipe(ItemInstance(5,4,0),{"w"});
	ru.clearAllRecipeTypes();
	
	ru.addRecipeType(5,'w');
	ru.addShapedRecipe(ItemInstance(IC::Items::ID::mTreeTap,1,0),{" w ","www","w  "});
	ru.clearAllRecipeTypes();
}
void ICRecipes::addFurnaceRecipes(FurnaceRecipes&fr)
{
	RecipeUtil ru(0,&fr);
	
	ru.addFurnaceRecipe(265,0,IC::Items::ID::mIngot,1);
	ru.addFurnaceRecipe(IC::Blocks::ID::mOre,0,IC::Items::ID::mIngot,0);
	ru.addFurnaceRecipe(IC::Blocks::ID::mOre,1,IC::Items::ID::mIngot,2);
	ru.addFurnaceRecipe(IC::Blocks::ID::mOre,2,IC::Items::ID::mIngot,3);
	ru.addFurnaceRecipe(IC::Blocks::ID::mOre,3,IC::Items::ID::mUranium,0);
	ru.addFurnaceRecipe(IC::Items::ID::mRubber,0,IC::Items::ID::mRubber,1);
}