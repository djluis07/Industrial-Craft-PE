#pragma once

class FurnaceRecipes;
class Recipes;

class ICRecipes
{
public:
	static void addRecipes(Recipes&,FurnaceRecipes&);
private:
	static void addItemRecipes(Recipes&);
	static void addFurnaceRecipes(FurnaceRecipes&);
};
