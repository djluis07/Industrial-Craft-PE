package com.mojang.minecraftpe;

import android.content.Context;
import android.os.Bundle;
import com.google.android.gms.gcm.GcmListenerService;
import com.microsoft.xbox.services.NotificationHelper;
import com.microsoft.xbox.services.NotificationResult;

public class NotificationListenerService
extends GcmListenerService {
    native void nativePushNotificationReceived(int var1, String var2, String var3, String var4);

    public void onMessageReceived(String string2, Bundle bundle) {
        NotificationResult notificationResult = NotificationHelper.tryParseXboxLiveNotification((Bundle)bundle, (Context)this);
        this.nativePushNotificationReceived(notificationResult.notificationType.ordinal(), notificationResult.title, notificationResult.body, notificationResult.data);
    }
}

