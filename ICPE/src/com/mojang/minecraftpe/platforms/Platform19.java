/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  android.annotation.TargetApi
 *  android.os.Handler
 *  android.view.View
 *  android.view.View$OnSystemUiVisibilityChangeListener
 *  java.lang.Object
 *  java.lang.Runnable
 */
package com.mojang.minecraftpe.platforms;

import android.annotation.TargetApi;
import android.os.Handler;
import android.view.View;
import com.mojang.minecraftpe.platforms.Platform9;

@TargetApi(value=19)
public class Platform19
extends Platform9 {
    private Runnable decorViewSettings;
    private View decoreView;
    private Handler eventHandler;

    public Platform19(boolean bl) {
        if (bl) {
            this.eventHandler = new Handler();
        }
    }

    @Override
    public void onAppStart(View view) {
        if (this.eventHandler == null) {
            return;
        }
        this.decoreView = view;
        this.decoreView.setOnSystemUiVisibilityChangeListener(new View.OnSystemUiVisibilityChangeListener(){

            public void onSystemUiVisibilityChange(int n) {
                Platform19.this.eventHandler.postDelayed(Platform19.this.decorViewSettings, 500);
            }
        });
        this.decorViewSettings = new Runnable(){

            public void run() {
                Platform19.this.decoreView.setSystemUiVisibility(5894);
            }
        };
        this.eventHandler.post(this.decorViewSettings);
    }

    @Override
    public void onViewFocusChanged(boolean bl) {
        if (this.eventHandler != null && bl) {
            this.eventHandler.postDelayed(this.decorViewSettings, 500);
        }
    }

    @Override
    public void onVolumePressed() {
    }

}

