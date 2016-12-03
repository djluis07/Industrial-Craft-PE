/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  android.content.Context
 *  android.text.Editable
 *  android.text.InputFilter
 *  android.text.InputFilter$LengthFilter
 *  android.text.Spanned
 *  android.util.AttributeSet
 *  android.view.KeyEvent
 *  android.view.inputmethod.EditorInfo
 *  android.view.inputmethod.InputConnection
 *  android.view.inputmethod.InputConnectionWrapper
 *  android.widget.EditText
 *  java.lang.CharSequence
 *  java.lang.Object
 */
package com.mojang.minecraftpe;

import android.content.Context;
import android.text.Editable;
import android.text.InputFilter;
import android.text.Spanned;
import android.util.AttributeSet;
import android.view.KeyEvent;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputConnection;
import android.view.inputmethod.InputConnectionWrapper;
import android.widget.EditText;

public class TextInputProxyEditTextbox
extends EditText {
    private MCPEKeyWatcher _mcpeKeyWatcher = null;
    public final int allowedLength;
    public final boolean limitInput;

    /*
     * Enabled aggressive block sorting
     */
    public TextInputProxyEditTextbox(Context context, int n, boolean bl) {
        super(context);
        this.allowedLength = n;
        this.limitInput = bl;
        InputFilter[] arrinputFilter = bl ? new InputFilter[]{new InputFilter.LengthFilter(this.allowedLength), new InputFilter(){

            public CharSequence filter(CharSequence charSequence, int n, int n2, Spanned spanned, int n3, int n4) {
                if (charSequence.equals((Object)"")) {
                    // empty if block
                }
                return charSequence;
            }
        }} : new InputFilter[]{new InputFilter.LengthFilter(this.allowedLength)};
        this.setFilters(arrinputFilter);
    }

    public TextInputProxyEditTextbox(Context context, AttributeSet attributeSet) {
        super(context, attributeSet);
        this.allowedLength = 160;
        this.limitInput = false;
    }

    public TextInputProxyEditTextbox(Context context, AttributeSet attributeSet, int n) {
        super(context, attributeSet, n);
        this.allowedLength = 160;
        this.limitInput = false;
    }

    public InputConnection onCreateInputConnection(EditorInfo editorInfo) {
        return new MCPEInputConnection(super.onCreateInputConnection(editorInfo), true, this);
    }

    public boolean onKeyPreIme(int n, KeyEvent keyEvent) {
        if (n == 4 && keyEvent.getAction() == 1) {
            if (this._mcpeKeyWatcher != null) {
                this._mcpeKeyWatcher.onBackKeyPressed();
            }
            return false;
        }
        return super.onKeyPreIme(n, keyEvent);
    }

    public void setOnMCPEKeyWatcher(MCPEKeyWatcher mCPEKeyWatcher) {
        this._mcpeKeyWatcher = mCPEKeyWatcher;
    }

    private class MCPEInputConnection
    extends InputConnectionWrapper {
        TextInputProxyEditTextbox textbox;

        public MCPEInputConnection(InputConnection inputConnection, boolean bl, TextInputProxyEditTextbox textInputProxyEditTextbox2) {
            super(inputConnection, bl);
            this.textbox = textInputProxyEditTextbox2;
        }

        public boolean sendKeyEvent(KeyEvent keyEvent) {
            if (this.textbox.getText().length() == 0 && keyEvent.getAction() == 0 && keyEvent.getKeyCode() == 67) {
                if (TextInputProxyEditTextbox.this._mcpeKeyWatcher != null) {
                    TextInputProxyEditTextbox.this._mcpeKeyWatcher.onDeleteKeyPressed();
                }
                return false;
            }
            return super.sendKeyEvent(keyEvent);
        }
    }

    public static interface MCPEKeyWatcher {
        public void onBackKeyPressed();

        public void onDeleteKeyPressed();
    }

}

