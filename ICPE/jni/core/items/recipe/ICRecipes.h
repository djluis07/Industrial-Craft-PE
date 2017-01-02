#pragma once

#include <vector>

class FurnaceRecipes;
class Recipes;
class ItemInstance;

class ICRecipes
{
public:
	struct ShapelessItemInstance
	{
		unsigned short id;
		unsigned char aux;
	};
	struct ShapedItemInstance
	{
		char letter;
		unsigned short id;
		unsigned char aux;
	}; 
public:
	static void addRecipes(Recipes&,FurnaceRecipes&);
private:
	static void addItemRecipes(Recipes&);
	static void addFurnaceRecipes(FurnaceRecipes&);
public:
	static void addShapelessRecipe(ItemInstance const&,std::vector<ShapelessItemInstance> const&);
	static void addShapedecipe(ItemInstance const&,std::vector<ShapedItemInstance> const&);
	static void addFurnaceRecipe(short,short,short,short);
};
