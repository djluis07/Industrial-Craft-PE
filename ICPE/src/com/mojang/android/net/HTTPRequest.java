/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  java.io.IOException
 *  java.io.UnsupportedEncodingException
 *  java.lang.Object
 *  java.lang.String
 *  java.security.InvalidParameterException
 *  org.apache.http.Header
 *  org.apache.http.HttpEntity
 *  org.apache.http.HttpResponse
 *  org.apache.http.StatusLine
 *  org.apache.http.client.ClientProtocolException
 *  org.apache.http.client.methods.HttpDelete
 *  org.apache.http.client.methods.HttpEntityEnclosingRequestBase
 *  org.apache.http.client.methods.HttpGet
 *  org.apache.http.client.methods.HttpPost
 *  org.apache.http.client.methods.HttpPut
 *  org.apache.http.client.methods.HttpRequestBase
 *  org.apache.http.client.methods.HttpUriRequest
 *  org.apache.http.conn.ConnectTimeoutException
 *  org.apache.http.entity.StringEntity
 *  org.apache.http.params.BasicHttpParams
 *  org.apache.http.params.HttpConnectionParams
 *  org.apache.http.params.HttpParams
 *  org.apache.http.util.EntityUtils
 */
package com.mojang.android.net;

import com.mojang.android.net.HTTPClientManager;
import com.mojang.android.net.HTTPResponse;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.security.InvalidParameterException;
import org.apache.http.Header;
import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.StatusLine;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.methods.HttpDelete;
import org.apache.http.client.methods.HttpEntityEnclosingRequestBase;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.methods.HttpPut;
import org.apache.http.client.methods.HttpRequestBase;
import org.apache.http.client.methods.HttpUriRequest;
import org.apache.http.conn.ConnectTimeoutException;
import org.apache.http.entity.StringEntity;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpConnectionParams;
import org.apache.http.params.HttpParams;
import org.apache.http.util.EntityUtils;

public class HTTPRequest {
    String mCookieData = "";
    HttpRequestBase mHTTPRequest = null;
    String mRequestBody = "";
    String mRequestContentType = "text/plain";
    HTTPResponse mResponse = new HTTPResponse();
    String mURL = "";

    /*
     * Enabled force condition propagation
     * Lifted jumps to return sites
     */
    private void addBodyToRequest(HttpEntityEnclosingRequestBase httpEntityEnclosingRequestBase) {
        if (this.mRequestBody == "") return;
        try {
            StringEntity stringEntity = new StringEntity(this.mRequestBody);
            stringEntity.setContentType(this.mRequestContentType);
            httpEntityEnclosingRequestBase.setEntity((HttpEntity)stringEntity);
            httpEntityEnclosingRequestBase.addHeader("Content-Type", this.mRequestContentType);
            return;
        }
        catch (UnsupportedEncodingException var3_3) {
            var3_3.printStackTrace();
            return;
        }
    }

    private void addHeaders() {
        this.mHTTPRequest.addHeader("User-Agent", "MCPE/Android");
        BasicHttpParams basicHttpParams = new BasicHttpParams();
        HttpConnectionParams.setConnectionTimeout((HttpParams)basicHttpParams, (int)3000);
        this.mHTTPRequest.setParams((HttpParams)basicHttpParams);
        if (this.mCookieData != null && this.mCookieData.length() > 0) {
            this.mHTTPRequest.addHeader("Cookie", this.mCookieData);
        }
        this.mHTTPRequest.addHeader("Charset", "utf-8");
    }

    /*
     * Enabled aggressive block sorting
     * Enabled unnecessary exception pruning
     * Enabled aggressive exception aggregation
     */
    private void createHTTPRequest(String string2) {
        HTTPRequest hTTPRequest = this;
        synchronized (hTTPRequest) {
            if (string2.equals((Object)"DELETE")) {
                this.mHTTPRequest = new HttpDelete(this.mURL);
            } else if (string2.equals((Object)"PUT")) {
                HttpPut httpPut = new HttpPut(this.mURL);
                this.addBodyToRequest((HttpEntityEnclosingRequestBase)httpPut);
                this.mHTTPRequest = httpPut;
            } else if (string2.equals((Object)"GET")) {
                this.mHTTPRequest = new HttpGet(this.mURL);
            } else {
                if (!string2.equals((Object)"POST")) {
                    throw new InvalidParameterException("Unknown request method " + string2);
                }
                HttpPost httpPost = new HttpPost(this.mURL);
                this.addBodyToRequest((HttpEntityEnclosingRequestBase)httpPost);
                this.mHTTPRequest = httpPost;
            }
            return;
        }
    }

    public void abort() {
        HTTPRequest hTTPRequest = this;
        synchronized (hTTPRequest) {
            this.mResponse.setStatus(2);
            if (this.mHTTPRequest != null) {
                this.mHTTPRequest.abort();
            }
            return;
        }
    }

    /*
     * Unable to fully structure code
     * Enabled aggressive exception aggregation
     */
    /*public HTTPResponse send(String var1_1) {
        this.createHTTPRequest(var1_1);
        this.addHeaders();
        if (this.mResponse.getStatus() == 2) {
            return this.mResponse;
        }
        try {
            var5_2 = HTTPClientManager.getHTTPClient().execute((HttpUriRequest)this.mHTTPRequest);
            this.mResponse.setResponseCode(var5_2.getStatusLine().getStatusCode());
            var6_3 = var5_2.getEntity();
            this.mResponse.setBody(EntityUtils.toString((HttpEntity)var6_3));
            this.mResponse.setStatus(1);
            this.mResponse.setHeaders(var5_2.getAllHeaders());
            var7_4 = this.mResponse;
            return var7_4;
        }
        catch (ConnectTimeoutException var4_5) {
            this.mResponse.setStatus(3);
lbl16: // 3 sources:
            do {
                this.mHTTPRequest = null;
                return this.mResponse;
                break;
            } while (true);
        }
        catch (ClientProtocolException var3_6) {
            var3_6.printStackTrace();
            ** GOTO lbl16
        }
        catch (IOException var2_7) {
            var2_7.printStackTrace();
            ** continue;
        }
    }*/

    public void setContentType(String string2) {
        this.mRequestContentType = string2;
    }

    public void setCookieData(String string2) {
        this.mCookieData = string2;
    }

    public void setRequestBody(String string2) {
        this.mRequestBody = string2;
    }

    public void setURL(String string2) {
        this.mURL = string2;
    }
}

