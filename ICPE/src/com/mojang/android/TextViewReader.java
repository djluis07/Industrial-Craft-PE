/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  android.widget.TextView
 *  java.lang.CharSequence
 *  java.lang.Object
 *  java.lang.String
 */
package com.mojang.android;

import android.widget.TextView;
import com.mojang.android.StringValue;

public class TextViewReader
implements StringValue {
    private TextView _view;

    public TextViewReader(TextView textView) {
        this._view = textView;
    }

    @Override
    public String getStringValue() {
        return this._view.getText().toString();
    }
}

