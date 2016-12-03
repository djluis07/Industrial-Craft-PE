/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  android.annotation.TargetApi
 *  android.os.Build
 *  java.lang.String
 */
package com.mojang.minecraftpe.platforms;

import android.annotation.TargetApi;
import android.os.Build;
import com.mojang.minecraftpe.platforms.Platform19;

@TargetApi(value=21)
public class Platform21
extends Platform19 {
    public Platform21(boolean bl) {
        super(bl);
    }

    @Override
    public String getABIS() {
        return Build.SUPPORTED_ABIS.toString();
    }
}

