/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  java.lang.Object
 *  java.lang.String
 */
package com.mojang.minecraftpe.store;

import com.mojang.minecraftpe.store.Product;
import com.mojang.minecraftpe.store.Purchase;

public interface StoreListener {
    public void onPurchaseCanceled(String var1);

    public void onPurchaseFailed(String var1);

    public void onPurchaseSuccessful(String var1, String var2);

    public void onQueryProductsFail();

    public void onQueryProductsSuccess(Product[] var1);

    public void onQueryPurchasesFail();

    public void onQueryPurchasesSuccess(Purchase[] var1);

    public void onStoreInitialized(boolean var1);
}

