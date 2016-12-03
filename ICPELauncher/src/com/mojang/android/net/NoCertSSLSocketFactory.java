/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  java.io.IOException
 *  java.io.InputStream
 *  java.lang.Object
 *  java.lang.String
 *  java.net.Socket
 *  java.net.UnknownHostException
 *  java.security.KeyManagementException
 *  java.security.KeyStore
 *  java.security.KeyStoreException
 *  java.security.NoSuchAlgorithmException
 *  java.security.SecureRandom
 *  java.security.UnrecoverableKeyException
 *  java.security.cert.CertificateException
 *  java.security.cert.X509Certificate
 *  javax.net.ssl.KeyManager
 *  javax.net.ssl.SSLContext
 *  javax.net.ssl.SSLSocketFactory
 *  javax.net.ssl.TrustManager
 *  javax.net.ssl.X509TrustManager
 *  org.apache.http.conn.ssl.SSLSocketFactory
 *  org.apache.http.conn.ssl.X509HostnameVerifier
 */
package com.mojang.android.net;

import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.security.KeyManagementException;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.security.UnrecoverableKeyException;
import java.security.cert.CertificateException;
import java.security.cert.X509Certificate;
import javax.net.ssl.KeyManager;
import javax.net.ssl.SSLContext;
import javax.net.ssl.SSLSocketFactory;
import javax.net.ssl.TrustManager;
import javax.net.ssl.X509TrustManager;
import org.apache.http.conn.ssl.X509HostnameVerifier;

public class NoCertSSLSocketFactory
extends org.apache.http.conn.ssl.SSLSocketFactory {
    private SSLContext sslContext = SSLContext.getInstance((String)"TLS");

    public NoCertSSLSocketFactory(KeyStore keyStore) throws NoSuchAlgorithmException, KeyManagementException, KeyStoreException, UnrecoverableKeyException {
        super(keyStore);
        X509TrustManager x509TrustManager = new X509TrustManager(){

            public void checkClientTrusted(X509Certificate[] arrx509Certificate, String string2) throws CertificateException {
            }

            public void checkServerTrusted(X509Certificate[] arrx509Certificate, String string2) throws CertificateException {
            }

            public X509Certificate[] getAcceptedIssuers() {
                return null;
            }
        };
        this.sslContext.init(null, new TrustManager[]{x509TrustManager}, null);
    }

    public static NoCertSSLSocketFactory createDefault() throws KeyStoreException, NoSuchAlgorithmException, CertificateException, IOException, KeyManagementException, UnrecoverableKeyException {
        KeyStore keyStore = KeyStore.getInstance((String)KeyStore.getDefaultType());
        keyStore.load(null, null);
        NoCertSSLSocketFactory noCertSSLSocketFactory = new NoCertSSLSocketFactory(keyStore);
        noCertSSLSocketFactory.setHostnameVerifier(org.apache.http.conn.ssl.SSLSocketFactory.ALLOW_ALL_HOSTNAME_VERIFIER);
        return noCertSSLSocketFactory;
    }

    public Socket createSocket() throws IOException {
        return this.sslContext.getSocketFactory().createSocket();
    }

    public Socket createSocket(Socket socket, String string2, int n, boolean bl) throws IOException, UnknownHostException {
        return this.sslContext.getSocketFactory().createSocket(socket, string2, n, bl);
    }

}

