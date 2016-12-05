#include "RubTreeFeature.h"

#if 0

/*     */ package ic2.core.block;
/*     */ 
/*     */ import ic2.core.IC2;
/*     */ import ic2.core.ref.BlockName;
/*     */ import ic2.core.util.Log;
/*     */ import ic2.core.util.LogCategory;
/*     */ import java.util.Random;
/*     */ import net.minecraft.block.Block;
/*     */ import net.minecraft.block.state.IBlockState;
/*     */ import net.minecraft.util.EnumFacing;
/*     */ import net.minecraft.util.math.BlockPos;
/*     */ import net.minecraft.util.math.BlockPos.MutableBlockPos;
/*     */ import net.minecraft.world.World;
/*     */ import net.minecraft.world.gen.feature.WorldGenerator;
/*     */ import net.minecraftforge.common.IPlantable;
/*     */ 
/*     */ public class WorldGenRubTree extends WorldGenerator
/*     */ {
/*     */   public static final int maxHeight = 8;
/*     */ 
/*     */   public WorldGenRubTree(boolean notify)
/*     */   {
/*  29 */     super(notify);
/*     */   }
/*     */ 
/*     */   public boolean func_180709_b(World world, Random random, BlockPos pos)
/*     */   {
/*  34 */     BlockPos.MutableBlockPos cPos = new BlockPos.MutableBlockPos();
/*  35 */     cPos.func_181079_c(pos.func_177958_n(), IC2.getWorldHeight(world) - 1, pos.func_177952_p());
/*     */ 
/*  37 */     while ((world.func_175623_d(cPos)) && (cPos.func_177956_o() > 0)) {
/*  38 */       cPos.func_181079_c(cPos.func_177958_n(), cPos.func_177956_o() - 1, cPos.func_177952_p());
/*     */     }
/*     */ 
/*  41 */     cPos.func_181079_c(cPos.func_177958_n(), cPos.func_177956_o() + 1, cPos.func_177952_p());
/*     */ 
/*  43 */     return grow(world, cPos, random);
/*     */   }
/*     */ 
/*     */   public boolean grow(World world, BlockPos pos, Random random)
/*     */   {
/*  52 */     if (world == null) {
/*  53 */       IC2.log.warn(LogCategory.General, "RubberTree did not spawn! w=%s.", new Object[] { world });
/*  54 */       return false;
/*     */     }
/*     */ 
/*  57 */     Block woodBlock = BlockName.rubber_wood.getInstance();
/*     */ 
/*  59 */     IBlockState leaves = BlockName.leaves.getInstance().func_176223_P()
/*  59 */       .func_177226_a(Ic2Leaves.typeProperty, Ic2Leaves.LeavesType.rubber);
/*     */ 
/*  60 */     int treeholechance = 25;
/*  61 */     int height = getGrowHeight(world, pos);
/*  62 */     if (height < 2) return false;
/*     */ 
/*  65 */     height -= random.nextInt(height / 2 + 1);
/*     */ 
/*  67 */     BlockPos.MutableBlockPos tmpPos = new BlockPos.MutableBlockPos();
/*     */ 
/*  69 */     for (int cHeight = 0; cHeight < height; cHeight++) {
/*  70 */       BlockPos cPos = pos.func_177981_b(cHeight);
/*     */ 
/*  72 */       if (random.nextInt(100) <= treeholechance) {
/*  73 */         treeholechance -= 10;
/*     */ 
/*  75 */         func_175903_a(world, cPos, woodBlock.func_176223_P()
/*  76 */           .func_177226_a(BlockRubWood.stateProperty, 
/*  76 */           BlockRubWood.RubberWoodState.getWet(EnumFacing.field_176754_o[random
/*  76 */           .nextInt(4)])));
/*     */       }
/*     */       else {
/*  78 */         func_175903_a(world, cPos, woodBlock.func_176223_P()
/*  79 */           .func_177226_a(BlockRubWood.stateProperty, BlockRubWood.RubberWoodState.plain_y));
/*     */       }
/*     */ 
/*  82 */       if ((height < 4) || ((height < 7) && (cHeight > 1)) || (cHeight > 2))
/*     */       {
/*  85 */         for (int cx = pos.func_177958_n() - 2; cx <= pos.func_177958_n() + 2; cx++) {
/*  86 */           for (int cz = pos.func_177952_p() - 2; cz <= pos.func_177952_p() + 2; cz++) {
/*  87 */             int chance = Math.max(1, cHeight + 4 - height);
/*  88 */             int dx = Math.abs(cx - pos.func_177958_n());
/*  89 */             int dz = Math.abs(cz - pos.func_177952_p());
/*     */ 
/*  92 */             if (((dx <= 1) && (dz <= 1)) || ((dx <= 1) && 
/*  93 */               (random
/*  93 */               .nextInt(chance) == 0)) || (
/*  93 */               (dz <= 1) && 
/*  94 */               (random
/*  94 */               .nextInt(chance) == 0)))
/*     */             {
/*  95 */               tmpPos.func_181079_c(cx, pos.func_177956_o() + cHeight, cz);
/*     */ 
/*  97 */               if (world.func_175623_d(tmpPos)) {
/*  98 */                 func_175903_a(world, new BlockPos(tmpPos), leaves);
/*     */               }
/*     */             }
/*     */           }
/*     */         }
/*     */       }
/*     */     }
/*     */ 
/* 106 */     for (int i = 0; i <= height / 4 + random.nextInt(2); i++) {
/* 107 */       tmpPos.func_181079_c(pos.func_177958_n(), pos.func_177956_o() + height + i, pos.func_177952_p());
/*     */ 
/* 110 */       if (world.func_175623_d(tmpPos)) {
/* 111 */         func_175903_a(world, new BlockPos(tmpPos), leaves);
/*     */       }
/*     */     }
/*     */ 
/* 115 */     return true;
/*     */   }
/*     */ 
/*     */   public int getGrowHeight(World world, BlockPos pos)
/*     */   {
/* 125 */     BlockPos below = pos.func_177977_b();
/* 126 */     IBlockState baseState = world.func_180495_p(below);
/* 127 */     Block baseBlock = baseState.func_177230_c();
/*     */ 
/* 129 */     if ((baseBlock.isAir(baseState, world, below)) || 
/* 130 */       (!baseBlock
/* 130 */       .canSustainPlant(baseState, world, below, EnumFacing.UP, 
/* 130 */       (IPlantable)BlockName.sapling
/* 130 */       .getInstance())) || (
/* 131 */       (!world
/* 131 */       .func_175623_d(pos
/* 131 */       .func_177984_a())) && (world.func_180495_p(pos.func_177984_a()).func_177230_c() != BlockName.sapling.getInstance())))
/*     */     {
/* 133 */       return 0;
/*     */     }
/*     */ 
/* 136 */     int height = 1;
/* 137 */     pos = pos.func_177984_a();
/*     */ 
/* 139 */     while ((world.func_175623_d(pos)) && (height < 8)) {
/* 140 */       pos = pos.func_177984_a();
/* 141 */       height++;
/*     */     }
/*     */ 
/* 144 */     return height;
/*     */   }
/*     */ }

/* Location:           D:\BaiduYunDownload\industrialcraft-2-2.6.85-ex110.jar
 * Qualified Name:     ic2.core.block.WorldGenRubTree
 * JD-Core Version:    0.6.2
 */

#endif
