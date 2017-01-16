#include "ICRecipes.h"

#include "blocks/Blocks.h"
#include "items/Items.h"

ICRecipes::ICRecipes(Recipes&r,FurnaceRecipes&fr):ru(RecipeUtil(&r,&fr))
{
	
}
void ICRecipes::addRecipes()
{
	addItemRecipes();
	addFurnaceRecipes();
}
void ICRecipes::addItemRecipes()
{
	using namespace IC;
	
	//Painter empty
	addShapedRecipe(ItemInstance(Items::ID::mPainter,2,0),{
	"aab",
	" b ",
	" b "},{{'a',35,0},{'b',280,0}});
	//Painter red
	addShapelessRecipe(ItemInstance(Items::ID::mPainterRed,1,0),
	{{Items::ID::mPainter,0},{351,1}});
	//Painter brown
	addShapelessRecipe(ItemInstance(Items::ID::mPainterBrown,1,0),
	{{Items::ID::mPainter,0},{351,3}});
	//Painter Green
	addShapelessRecipe(ItemInstance(Items::ID::mPainterGreen,1,0),
	{{Items::ID::mPainter,0},{351,2}});
	//Painter blue
	addShapelessRecipe(ItemInstance(Items::ID::mPainterBlue,1,0),
	{{Items::ID::mPainter,0},{351,4}});
	//Painter magenta
	addShapelessRecipe(ItemInstance(Items::ID::mPainterMagenta,1,0),
	{{Items::ID::mPainter,0},{351,13}});
	//Painter Purple
	addShapelessRecipe(ItemInstance(Items::ID::mPainterPurple,1,0),
	{{Items::ID::mPainter,0},{351,5}});
	//Painter light blue
	addShapelessRecipe(ItemInstance(Items::ID::mPainterLightBlue,1,0),
	{{Items::ID::mPainter,0},{351,12}});
	//Painter white
	addShapelessRecipe(ItemInstance(Items::ID::mPainterWhite,1,0),
	{{Items::ID::mPainter,0},{351,15}});
	//Painter black
	addShapelessRecipe(ItemInstance(Items::ID::mPainterBlack,1,0),
	{{Items::ID::mPainter,0},{351,0}});
	//Painter pink
	addShapelessRecipe(ItemInstance(Items::ID::mPainterPink,1,0),
	{{Items::ID::mPainter,0},{351,9}});
	//Painter light green
	addShapelessRecipe(ItemInstance(Items::ID::mPainterGreen,1,0),
	{{Items::ID::mPainter,0},{351,10}});
	//Painter yellow
	addShapelessRecipe(ItemInstance(Items::ID::mPainterYellow,1,0),
	{{Items::ID::mPainter,0},{351,11}});
	//Painter orange
	addShapelessRecipe(ItemInstance(Items::ID::mPainterOrange,1,0),
	{{Items::ID::mPainter,0},{351,14}});
	//Painter gray
	addShapelessRecipe(ItemInstance(Items::ID::mPainterGray,1,0),
	{{Items::ID::mPainter,0},{351,0}});
	//Painter light gray
	addShapelessRecipe(ItemInstance(Items::ID::mPainterGray,1,0),
	{{Items::ID::mPainter,8},{351,7}});
	//Painter cyan
	addShapelessRecipe(ItemInstance(Items::ID::mPainterCyan,1,0),
	{{Items::ID::mPainter,0},{351,6}});
	//Forge hammer
	addShapedRecipe(ItemInstance(Items::ID::mForgeHammer,1,0),{
	"aa ",
	"abb",
	"aa "},{{'a',265,0},{'b',280,0}});
	//Bronze sword
	addShapedRecipe(ItemInstance(Items::ID::mBronzeSword,1,0),{
	"a",
	"a",
	"b",},{{'a',Items::ID::mBronzeIngot,0},{'b',280,0}});
	//Bronze pickaxe
	addShapedRecipe(ItemInstance(Items::ID::mBronzePickAxe,1,0),{
	"aaa",
	" b ",
	" b "},{{'a',Items::ID::mBronzeIngot,0},{'b',280,0}});
	//Bronze hoe
	addShapedRecipe(ItemInstance(Items::ID::mBronzeHoe,1,0),{
	"aa",
	" b",
	" b"},{{'a',Items::ID::mBronzeIngot,0},{'b',280,0}});
	//Bronze shovel
	addShapedRecipe(ItemInstance(Items::ID::mBronzeShovel,1,0),{
	"a",
	"b",
	"b"},{{'a',Items::ID::mBronzeIngot,0},{'b',280,0}});
	//Bronze axe
	addShapedRecipe(ItemInstance(Items::ID::mBronzeAxe,1,0),{
	"aa",
	"ab",
	" b"},{{'a',Items::ID::mBronzeIngot,0},{'b',280,0}});
	//Circuit
	addShapedRecipe(ItemInstance(Items::ID::mCircuit,1,0),{
	"aaa",
	"bcb",
	"aaa"},{{'a',Items::ID::mCopperCable0,0},{'b',331,0},{'c',Items::ID::mIronPlate,0}});
	//Advanced circuit
	addShapedRecipe(ItemInstance(Items::ID::mAdvancedCircuit,1,0),{
	"aba",
	"cdc",
	"aba"},{{'a',351,0},{'b',342},{'c',331,0},{'d',Items::ID::mIronPlate}});
	//Coil
	addShapedRecipe(ItemInstance(Items::ID::mCoil,2,0),{
	"aaa",
	"aba",
	"aaa"},{{'a',Items::ID::mCopperCable0,0},{'b',265,0}});
	//Iron furnace
	addShapedRecipe(ItemInstance(Blocks::ID::mFurnace,1,0),{
	" a ",
	"a a",
	"aba"},{{'a',Items::ID::mIronPlate,0},{'b',61,0}});
	//ITNT
	addShapedRecipe(ItemInstance(Blocks::ID::mITNT,4,0),{
	"aaa",
	"bbb",
	"aaa"},{{'a',318,0},{'b',46,0}});
	//Planks
	addShapelessRecipe(ItemInstance(5,4,0),
	{{Blocks::ID::mRubberWood,-1}});
	//Tree tap
	addShapedRecipe(ItemInstance(Items::ID::mTreeTap,1,0),{
	" w ",
	"www",
	"w  "},{{'w',5,-1}});
	//Metal blocks
	addShapedRecipe(ItemInstance(Blocks::ID::mMetal,1,0),{
	"aaa",
	"aaa",
	"aaa"},{{'a',Items::ID::mTinIngot,0}});
	addShapedRecipe(ItemInstance(Blocks::ID::mMetal,1,1),{
	"aaa",
	"aaa",
	"aaa"},{{'a',Items::ID::mSteelIngot,0}});
	addShapedRecipe(ItemInstance(Blocks::ID::mMetal,1,2),{
	"aaa",
	"aaa",
	"aaa"},{{'a',Items::ID::mCopperIngot,0}});
	addShapedRecipe(ItemInstance(Blocks::ID::mMetal,1,3),{
	"aaa",
	"aaa",
	"aaa"},{{'a',Items::ID::mLeadIngot,0}});
	//Ingots
	addShapelessRecipe(ItemInstance(Items::ID::mTinIngot,9,0),
	{{Blocks::ID::mMetal,0}});
	addShapelessRecipe(ItemInstance(Items::ID::mSteelIngot,9,0),
	{{Blocks::ID::mMetal,1}});
	addShapelessRecipe(ItemInstance(Items::ID::mCopperIngot,9,0),
	{{Blocks::ID::mMetal,2}});
	addShapelessRecipe(ItemInstance(Items::ID::mLeadIngot,9,0),
	{{Blocks::ID::mMetal,3}});
	//Bronze plate
	addShapelessRecipe(ItemInstance(Items::ID::mBronzePlate,1,0),
	{{Items::ID::mBronzeIngot,-1},{Items::ID::mForgeHammer,-1}});
	//Steel plate
	addShapelessRecipe(ItemInstance(Items::ID::mSteelPlate,1,0),
	{{Items::ID::mSteelIngot,-1},{Items::ID::mForgeHammer,-1}});
	//Iron plate
	addShapelessRecipe(ItemInstance(Items::ID::mIronPlate,1,0),
	{{265,-1},{Items::ID::mForgeHammer,-1}});
	//Tin plate
	addShapelessRecipe(ItemInstance(Items::ID::mTinPlate,1,0),
	{{Items::ID::mTinIngot,-1},{Items::ID::mForgeHammer,-1}});
	//Lead plate
	addShapelessRecipe(ItemInstance(Items::ID::mLeadPlate,1,0),
	{{Items::ID::mLeadIngot,-1},{Items::ID::mForgeHammer,-1}});
	//Gold plate
	addShapelessRecipe(ItemInstance(Items::ID::mGoldPlate,1,0),
	{{266,-1},{Items::ID::mForgeHammer,-1}});
	//Copper plate
	addShapelessRecipe(ItemInstance(Items::ID::mCopperPlate,1,0),
	{{Items::ID::mCopperIngot,-1},{Items::ID::mForgeHammer,-1}});
	//Lapis plate
	addShapelessRecipe(ItemInstance(Items::ID::mLapisPlate,1,0),
	{{351,4},{Items::ID::mForgeHammer,-1}});
	//Obsidian plate
	addShapelessRecipe(ItemInstance(Items::ID::mObsidianPlate,1,0),
	{{49,-1},{Items::ID::mForgeHammer,-1}});
	
}
void ICRecipes::addFurnaceRecipes()
{
	using namespace IC;
	
	addFurnaceRecipe(Items::ID::mResin,-1,Items::ID::mRubber,0);
	addFurnaceRecipe(Blocks::ID::mRubberWood,-1,263,1);
	addFurnaceRecipe(Blocks::ID::mOre,0,Items::ID::mTinIngot,0);
	addFurnaceRecipe(Blocks::ID::mOre,1,Items::ID::mCopperIngot,0);
	addFurnaceRecipe(Blocks::ID::mOre,2,Items::ID::mLeadIngot,0);
}
void ICRecipes::addShapelessRecipe(ItemInstance const&item,std::vector<ShapelessItemInstance> const&items)
{
	char letter=0;
	ru.clearAllRecipeTypes();
	for(ShapelessItemInstance itemShapeless:items)
		if(itemShapeless.aux==-1)
			ru.addRecipeType(itemShapeless.id,++letter);
		else
			ru.addRecipeTypeAuxValue(itemShapeless.id,itemShapeless.aux,++letter);
	ru.addShapelessRecipe(item);
}
void ICRecipes::addShapedRecipe(ItemInstance const&item,std::vector<std::string>const&map,std::vector<ShapedItemInstance> const&res)
{
	ru.clearAllRecipeTypes();
	for(ShapedItemInstance itemShaped:res)
		if(itemShaped.aux==-1)
			ru.addRecipeType(itemShaped.id,itemShaped.letter);
		else
			ru.addRecipeTypeAuxValue(itemShaped.id,itemShaped.aux,itemShaped.letter);
	ru.addShapedRecipe(item,map);
}
void ICRecipes::addFurnaceRecipe(short id,short aux,short toid,short toaux)
{
	if(aux==-1)
		ru.addFurnaceRecipe(id,toid,toaux);
	else
		ru.addFurnaceRecipe(id,aux,toid,toaux);
}
