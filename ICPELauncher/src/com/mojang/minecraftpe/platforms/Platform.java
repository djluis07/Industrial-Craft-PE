/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  android.os.Build
 *  android.os.Build$VERSION
 *  android.view.View
 *  java.lang.Object
 *  java.lang.String
 */
package com.mojang.minecraftpe.platforms;

import android.os.Build;
import android.view.View;
import com.mojang.minecraftpe.platforms.Platform19;
import com.mojang.minecraftpe.platforms.Platform21;
import com.mojang.minecraftpe.platforms.Platform9;

public abstract class Platform {
    public static Platform createPlatform(boolean bl) {
        if (Build.VERSION.SDK_INT >= 19) {
            return new Platform19(bl);
        }
        if (Build.VERSION.SDK_INT >= 21) {
            return new Platform21(bl);
        }
        return new Platform9();
    }

    public abstract String getABIS();

    public abstract void onAppStart(View var1);

    public abstract void onViewFocusChanged(boolean var1);

    public abstract void onVolumePressed();
}

