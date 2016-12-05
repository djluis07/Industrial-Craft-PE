/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  java.lang.Object
 *  java.lang.String
 */
package com.mojang.minecraftpe.store;

public class Purchase {
    public String mProductId;
    public boolean mPurchaseActive;
    public String mReceipt;

    public Purchase(String string2, String string3, boolean bl) {
        this.mProductId = string2;
        this.mReceipt = string3;
        this.mPurchaseActive = bl;
    }
}

