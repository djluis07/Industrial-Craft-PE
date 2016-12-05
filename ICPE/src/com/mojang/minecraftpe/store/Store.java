/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  java.lang.Object
 *  java.lang.String
 */
package com.mojang.minecraftpe.store;

public interface Store {
    public void acknowledgePurchase(String var1, String var2);

    public void destructor();

    public String getStoreId();

    public void purchase(String var1, boolean var2, String var3);

    public void queryProducts(String[] var1);

    public void queryPurchases();
}

