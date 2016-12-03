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
import com.mojang.minecraftpe.store.StoreListener;

public class NativeStoreListener
implements StoreListener {
    long mStoreListener;

    public NativeStoreListener(long l) {
        this.mStoreListener = l;
    }

    public native void onPurchaseCanceled(long var1, String var3);

    @Override
    public void onPurchaseCanceled(String string2) {
        this.onPurchaseCanceled(this.mStoreListener, string2);
    }

    public native void onPurchaseFailed(long var1, String var3);

    @Override
    public void onPurchaseFailed(String string2) {
        this.onPurchaseFailed(this.mStoreListener, string2);
    }

    public native void onPurchaseSuccessful(long var1, String var3, String var4);

    @Override
    public void onPurchaseSuccessful(String string2, String string3) {
        this.onPurchaseSuccessful(this.mStoreListener, string2, string3);
    }

    @Override
    public void onQueryProductsFail() {
        this.onQueryProductsFail(this.mStoreListener);
    }

    public native void onQueryProductsFail(long var1);

    public native void onQueryProductsSuccess(long var1, Product[] var3);

    @Override
    public void onQueryProductsSuccess(Product[] arrproduct) {
        this.onQueryProductsSuccess(this.mStoreListener, arrproduct);
    }

    @Override
    public void onQueryPurchasesFail() {
        this.onQueryPurchasesFail(this.mStoreListener);
    }

    public native void onQueryPurchasesFail(long var1);

    public native void onQueryPurchasesSuccess(long var1, Purchase[] var3);

    @Override
    public void onQueryPurchasesSuccess(Purchase[] arrpurchase) {
        this.onQueryPurchasesSuccess(this.mStoreListener, arrpurchase);
    }

    public native void onStoreInitialized(long var1, boolean var3);

    @Override
    public void onStoreInitialized(boolean bl) {
        this.onStoreInitialized(this.mStoreListener, bl);
    }
}

