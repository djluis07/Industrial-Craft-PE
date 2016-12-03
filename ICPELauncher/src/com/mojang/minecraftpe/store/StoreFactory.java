/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  android.content.Context
 *  java.lang.Object
 *  java.lang.String
 */
package com.mojang.minecraftpe.store;

import android.content.Context;
import com.mojang.minecraftpe.MainActivity;
import com.mojang.minecraftpe.store.Store;
import com.mojang.minecraftpe.store.StoreListener;
import com.mojang.minecraftpe.store.amazonappstore.AmazonAppStore;
import com.mojang.minecraftpe.store.googleplay.GooglePlayStore;

public class StoreFactory {
    static Store createAmazonAppStore(StoreListener storeListener) {
        return new AmazonAppStore((Context)MainActivity.mInstance, storeListener);
    }

    static Store createGooglePlayStore(String string2, StoreListener storeListener) {
        return new GooglePlayStore(MainActivity.mInstance, string2, storeListener);
    }
}

