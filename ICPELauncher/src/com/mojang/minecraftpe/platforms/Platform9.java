/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  android.os.Build
 *  android.view.View
 *  java.lang.String
 */
package com.mojang.minecraftpe.platforms;

import android.os.Build;
import android.view.View;
import com.mojang.minecraftpe.platforms.Platform;

public class Platform9
extends Platform {
    @Override
    public String getABIS() {
        return Build.CPU_ABI;
    }

    @Override
    public void onAppStart(View view) {
    }

    @Override
    public void onViewFocusChanged(boolean bl) {
    }

    @Override
    public void onVolumePressed() {
    }
}

