/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  android.content.Context
 *  android.os.Build
 *  android.os.Build$VERSION
 *  android.util.Log
 *  java.lang.Object
 *  java.lang.String
 */
package com.mojang.minecraftpe.input;

import android.content.Context;
import android.os.Build;
import android.util.Log;
import com.mojang.minecraftpe.input.JellyBeanDeviceManager;

public abstract class InputDeviceManager {
    public static InputDeviceManager create(Context context) {
        if (Build.VERSION.SDK_INT >= 16) {
            return new JellyBeanDeviceManager(context);
        }
        return new DefaultDeviceManager();
    }

    public abstract void register();

    public abstract void unregister();

    public static class DefaultDeviceManager
    extends InputDeviceManager {
        private DefaultDeviceManager() {
        }

        @Override
        public void register() {
            Log.w((String)"MCPE", (String)"INPUT Noop register device manager");
        }

        @Override
        public void unregister() {
            Log.w((String)"MCPE", (String)"INPUT Noop unregister device manager");
        }
    }

}

