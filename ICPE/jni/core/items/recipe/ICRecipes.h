#pragma once

#include <vector>

#include "RecipeUtil.h"

class FurnaceRecipes;
class Recipes;
class ItemInstance;

class ICRecipes
{
public:
	struct ShapelessItemInstance
	{
		short id;
		short aux;
	};
	struct ShapedItemInstance
	{
		char letter;
		short id;
		short aux;
	};
private:
	RecipeUtil ru;
public:
	ICRecipes(Recipes&,FurnaceRecipes&);
	~ICRecipes()=default;
	void addRecipes();
private:
	void addItemRecipes();
	void addFurnaceRecipes();
public:
	void addShapelessRecipe(ItemInstance const&,std::vector<ShapelessItemInstance> const&);
	void addShapedRecipe(ItemInstance const&,std::vector<std::string>const&,std::vector<ShapedItemInstance> const&);
	void addFurnaceRecipe(short,short,short,short);
};
