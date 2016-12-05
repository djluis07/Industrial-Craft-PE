/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  java.lang.Object
 *  java.lang.String
 *  org.apache.http.Header
 */
package com.mojang.android.net;

import org.apache.http.Header;

public class HTTPResponse {
    public static final int ABORTED = 2;
    public static final int DONE = 1;
    public static final int IN_PROGRESS = 0;
    public static final int TIME_OUT = 3;
    String body = "";
    Header[] headers;
    int responseCode = -100;
    int status = 0;

    public String getBody() {
        return this.body;
    }

    public Header[] getHeaders() {
        return this.headers;
    }

    public int getResponseCode() {
        return this.responseCode;
    }

    public int getStatus() {
        return this.status;
    }

    public void setBody(String string2) {
        this.body = string2;
    }

    public void setHeaders(Header[] arrheader) {
        this.headers = arrheader;
    }

    public void setResponseCode(int n) {
        this.responseCode = n;
    }

    public void setStatus(int n) {
        this.status = n;
    }
}

