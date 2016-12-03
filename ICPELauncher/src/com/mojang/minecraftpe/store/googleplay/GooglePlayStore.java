package com.mojang.minecraftpe.store.googleplay;

import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.util.Log;
import com.googleplay.util.IabHelper;
import com.googleplay.util.IabResult;
import com.googleplay.util.Inventory;
import com.googleplay.util.SkuDetails;
import com.mojang.minecraftpe.ActivityListener;
import com.mojang.minecraftpe.MainActivity;
import com.mojang.minecraftpe.store.Product;
import com.mojang.minecraftpe.store.Purchase;
import com.mojang.minecraftpe.store.Store;
import com.mojang.minecraftpe.store.StoreListener;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import org.json.JSONException;
import org.json.JSONObject;

public class GooglePlayStore
extends BroadcastReceiver
implements ActivityListener,
Store {
    static final String IAB_BROADCAST_ACTION = "com.android.vending.billing.PURCHASES_UPDATED";
    MainActivity mActivity;
    IabHelper mIabHelper;
    StoreListener mListener;
    int mPurchaseRequestCode;

    public GooglePlayStore(MainActivity mainActivity, String string2, StoreListener storeListener) {
        this.mListener = storeListener;
        this.mActivity = mainActivity;
        this.mActivity.addListener(this);
        this.mPurchaseRequestCode = MainActivity.RESULT_GOOGLEPLAY_PURCHASE;
        this.mIabHelper = new IabHelper((Context)this.mActivity, string2);
        this.mIabHelper.startSetup(new IabHelper.OnIabSetupFinishedListener(){

            public void onIabSetupFinished(IabResult iabResult) {
                Log.i((String)"GooglePlayStore", (String)("onIabSetupFinished: " + iabResult.getResponse() + ", " + iabResult.getMessage()));
                IntentFilter intentFilter = new IntentFilter("com.android.vending.billing.PURCHASES_UPDATED");
                //GooglePlayStore.this.mActivity.registerReceiver(this, intentFilter);
                GooglePlayStore.this.mListener.onStoreInitialized(iabResult.isSuccess());
            }
        });
    }

    private String createReceipt(com.googleplay.util.Purchase purchase) {
        JSONObject jSONObject = new JSONObject();
        try {
            jSONObject.put("itemtype", (Object)purchase.getItemType());
            jSONObject.put("originaljson", (Object)purchase.getOriginalJson());
            jSONObject.put("signature", (Object)purchase.getSignature());
        }
        catch (JSONException var3_3) {
            throw new RuntimeException((Throwable)var3_3);
        }
        return jSONObject.toString();
    }

    private com.googleplay.util.Purchase parseReceipt(String string2) {
        try {
            JSONObject jSONObject = new JSONObject(string2);
            com.googleplay.util.Purchase purchase = new com.googleplay.util.Purchase(jSONObject.getString("itemtype"), jSONObject.getString("originaljson"), jSONObject.getString("signature"));
            return purchase;
        }
        catch (JSONException var4_4) {
            return null;
        }
    }

    @Override
    public void acknowledgePurchase(final String string2, String string3) {
        if (string3.equals((Object)"Consumable")) {
            this.mActivity.runOnUiThread(new Runnable(){

                public void run() {
                    com.googleplay.util.Purchase purchase = GooglePlayStore.this.parseReceipt(string2);
                    if (purchase != null) {
                        GooglePlayStore.this.mIabHelper.consumeAsync(purchase, null);
                    }
                }
            });
        }
    }

    @Override
    public void destructor() {
        this.onDestroy();
    }

    @Override
    public String getStoreId() {
        return "android.googleplay";
    }

    @Override
    public void onActivityResult(int n, int n2, Intent intent) {
        if (this.mIabHelper != null) {
            this.mIabHelper.handleActivityResult(n, n2, intent);
        }
    }

    @Override
    public void onDestroy() {
        this.mActivity.removeListener(this);
        if (this.mIabHelper != null) {
            this.mIabHelper.dispose();
        }
        this.mIabHelper = null;
    }

    public void onReceive(Context context, Intent intent) {
        Log.i((String)"GooglePlayStore", (String)"IabBroadcastReceiver received message PURCHASES_UPDATED");
        this.queryPurchases();
    }

    @Override
    public void purchase(final String string2, final boolean bl, final String string3) {
        this.mActivity.runOnUiThread(new Runnable(){

            /*
             * Enabled aggressive block sorting
             */
            public void run() {
                String string22 = bl ? "subs" : "inapp";
                GooglePlayStore.this.mIabHelper.launchPurchaseFlow((Activity)GooglePlayStore.this.mActivity, string2, string22, GooglePlayStore.this.mPurchaseRequestCode, new IabHelper.OnIabPurchaseFinishedListener(){

                    public void onIabPurchaseFinished(IabResult iabResult, com.googleplay.util.Purchase purchase) {
                        if (iabResult.isSuccess()) {
                            GooglePlayStore.this.mListener.onPurchaseSuccessful(string2, GooglePlayStore.this.createReceipt(purchase));
                            return;
                        }
                        if (iabResult.getResponse() == -1005) {
                            GooglePlayStore.this.mListener.onPurchaseCanceled(string2);
                            return;
                        }
                        GooglePlayStore.this.mListener.onPurchaseFailed(string2);
                    }
                }, string3);
            }

        });
    }

    @Override
    public void queryProducts(final String[] arrstring) {
        this.mActivity.runOnUiThread(new Runnable(){

            public void run() {
                GooglePlayStore.this.mIabHelper.queryInventoryAsync(true, Arrays.asList((Object[])arrstring), new IabHelper.QueryInventoryFinishedListener(){

                    public void onQueryInventoryFinished(IabResult iabResult, Inventory inventory) {
                        if (iabResult.isSuccess()) {
                            ArrayList arrayList = new ArrayList();
                            if (iabResult.isSuccess()) {
                                for (String string2 : arrstring) {
                                    SkuDetails skuDetails = inventory.getSkuDetails(string2);
                                    if (skuDetails == null) continue;
                                    arrayList.add((Object)new Product(string2, skuDetails.getPrice()));
                                }
                            }
                            GooglePlayStore.this.mListener.onQueryProductsSuccess((Product[])arrayList.toArray((Object[])new Product[0]));
                            return;
                        }
                        GooglePlayStore.this.mListener.onQueryProductsFail();
                    }
                });
            }

        });
    }

    @Override
    public void queryPurchases() {
        this.mActivity.runOnUiThread(new Runnable(){

            public void run() {
                GooglePlayStore.this.mIabHelper.queryInventoryAsync(false, new IabHelper.QueryInventoryFinishedListener(){

                    /*
                     * Enabled aggressive block sorting
                     */
                    public void onQueryInventoryFinished(IabResult iabResult, Inventory inventory) {
                        if (!iabResult.isSuccess()) {
                            GooglePlayStore.this.mListener.onQueryPurchasesFail();
                            return;
                        }
                        ArrayList arrayList = new ArrayList();
                        if (iabResult.isSuccess()) {
                            for (com.googleplay.util.Purchase purchase : inventory.getAllPurchases()) {
                                String string2 = purchase.getSku();
                                String string3 = GooglePlayStore.this.createReceipt(purchase);
                                boolean bl = purchase.getPurchaseState() == 0;
                                arrayList.add((Object)new Purchase(string2, string3, bl));
                            }
                        }
                        GooglePlayStore.this.mListener.onQueryPurchasesSuccess((Purchase[])arrayList.toArray((Object[])new Purchase[0]));
                    }
                });
            }

        });
    }

}

