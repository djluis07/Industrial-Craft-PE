/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  android.annotation.TargetApi
 *  android.content.Context
 *  android.hardware.input.InputManager
 *  android.hardware.input.InputManager$InputDeviceListener
 *  android.os.Handler
 *  java.lang.Object
 *  java.lang.String
 */
package com.mojang.minecraftpe.input;

import android.annotation.TargetApi;
import android.content.Context;
import android.hardware.input.InputManager;
import android.os.Handler;
import com.mojang.minecraftpe.input.InputCharacteristics;
import com.mojang.minecraftpe.input.InputDeviceManager;

@TargetApi(value=16)
public class JellyBeanDeviceManager
extends InputDeviceManager
implements InputManager.InputDeviceListener {
    private final InputManager inputManager;

    JellyBeanDeviceManager(Context context) {
        this.inputManager = (InputManager)context.getSystemService("input");
    }

    public void onInputDeviceAdded(int n) {
        this.onInputDeviceAddedNative(n);
        this.setDoubleTriggersSupportedNative(InputCharacteristics.allControllersHaveDoubleTriggers());
        this.setCreteControllerNative(n, InputCharacteristics.isCreteController(n));
    }

    native void onInputDeviceAddedNative(int var1);

    public void onInputDeviceChanged(int n) {
        this.onInputDeviceChangedNative(n);
        this.setDoubleTriggersSupportedNative(InputCharacteristics.allControllersHaveDoubleTriggers());
        this.setCreteControllerNative(n, InputCharacteristics.isCreteController(n));
    }

    native void onInputDeviceChangedNative(int var1);

    public void onInputDeviceRemoved(int n) {
        this.onInputDeviceRemovedNative(n);
        this.setDoubleTriggersSupportedNative(InputCharacteristics.allControllersHaveDoubleTriggers());
        this.setCreteControllerNative(n, InputCharacteristics.isCreteController(n));
    }

    native void onInputDeviceRemovedNative(int var1);

    @Override
    public void register() {
        int[] arrn = this.inputManager.getInputDeviceIds();
        this.inputManager.registerInputDeviceListener((InputManager.InputDeviceListener)this, null);
        this.setDoubleTriggersSupportedNative(InputCharacteristics.allControllersHaveDoubleTriggers());
        for (int i = 0; i < arrn.length; ++i) {
            this.setCreteControllerNative(arrn[i], InputCharacteristics.isCreteController(arrn[i]));
        }
    }

    native void setCreteControllerNative(int var1, boolean var2);

    native void setDoubleTriggersSupportedNative(boolean var1);

    @Override
    public void unregister() {
        this.inputManager.unregisterInputDeviceListener((InputManager.InputDeviceListener)this);
    }
}

