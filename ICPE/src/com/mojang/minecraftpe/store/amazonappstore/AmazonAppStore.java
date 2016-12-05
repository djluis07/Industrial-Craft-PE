/*
 * Decompiled with CFR 0_110.
 * 
 * Could not load the following classes:
 *  android.content.Context
 *  com.amazon.device.iap.PurchasingListener
 *  com.amazon.device.iap.PurchasingService
 *  com.amazon.device.iap.model.FulfillmentResult
 *  com.amazon.device.iap.model.Product
 *  com.amazon.device.iap.model.ProductDataResponse
 *  com.amazon.device.iap.model.ProductDataResponse$RequestStatus
 *  com.amazon.device.iap.model.PurchaseResponse
 *  com.amazon.device.iap.model.PurchaseResponse$RequestStatus
 *  com.amazon.device.iap.model.PurchaseUpdatesResponse
 *  com.amazon.device.iap.model.PurchaseUpdatesResponse$RequestStatus
 *  com.amazon.device.iap.model.Receipt
 *  com.amazon.device.iap.model.RequestId
 *  com.amazon.device.iap.model.UserData
 *  com.amazon.device.iap.model.UserDataResponse
 *  java.lang.CharSequence
 *  java.lang.Object
 *  java.lang.RuntimeException
 *  java.lang.String
 *  java.lang.Throwable
 *  java.util.ArrayList
 *  java.util.Arrays
 *  java.util.Collection
 *  java.util.HashMap
 *  java.util.HashSet
 *  java.util.Iterator
 *  java.util.List
 *  java.util.Map
 *  java.util.Set
 *  org.json.JSONException
 *  org.json.JSONObject
 */
package com.mojang.minecraftpe.store.amazonappstore;

import android.content.Context;
import com.amazon.device.iap.PurchasingListener;
import com.amazon.device.iap.PurchasingService;
import com.amazon.device.iap.model.FulfillmentResult;
import com.amazon.device.iap.model.ProductDataResponse;
import com.amazon.device.iap.model.PurchaseResponse;
import com.amazon.device.iap.model.PurchaseUpdatesResponse;
import com.amazon.device.iap.model.Receipt;
import com.amazon.device.iap.model.RequestId;
import com.amazon.device.iap.model.UserData;
import com.amazon.device.iap.model.UserDataResponse;
import com.mojang.minecraftpe.store.Product;
import com.mojang.minecraftpe.store.Purchase;
import com.mojang.minecraftpe.store.Store;
import com.mojang.minecraftpe.store.StoreListener;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import org.json.JSONException;
import org.json.JSONObject;

public class AmazonAppStore
implements Store {
    private StoreListener mListener;
    private Map<RequestId, String> mProductIdRequestMapping = new HashMap();
    private PurchasingListener mPurchasingListener;
    private final String subscriptionKey = ".subscription";

    public AmazonAppStore(Context context, StoreListener storeListener) {
        this.mPurchasingListener = new PurchasingListener(){

            /*
             * Enabled aggressive block sorting
             */
            public void onProductDataResponse(ProductDataResponse productDataResponse) {
                if (productDataResponse.getRequestStatus() != ProductDataResponse.RequestStatus.SUCCESSFUL) {
                    AmazonAppStore.this.mListener.onQueryProductsFail();
                    return;
                }
                ArrayList arrayList = new ArrayList();
                Set set = productDataResponse.getUnavailableSkus();
                Map map = productDataResponse.getProductData();
                Iterator iterator = map.keySet().iterator();
                do {
                    if (!iterator.hasNext()) {
                        AmazonAppStore.this.mListener.onQueryProductsSuccess((Product[])arrayList.toArray((Object[])new Product[0]));
                        return;
                    }
                    String string2 = (String)iterator.next();
                    if (set.contains((Object)string2)) continue;
                    com.amazon.device.iap.model.Product product = (com.amazon.device.iap.model.Product)map.get((Object)string2);
                    String string3 = product.getSku() != null ? product.getSku().replace((CharSequence)".child", (CharSequence)"") : "";
                    String string4 = product.getPrice() != null ? product.getPrice() : "";
                    arrayList.add((Object)new Product(string3, string4));
                } while (true);
            }

            public void onPurchaseResponse(PurchaseResponse purchaseResponse) {
                String string2 = (String)AmazonAppStore.this.mProductIdRequestMapping.remove((Object)purchaseResponse.getRequestId());
                if (purchaseResponse.getRequestStatus() == PurchaseResponse.RequestStatus.SUCCESSFUL) {
                    AmazonAppStore.this.mListener.onPurchaseSuccessful(string2, AmazonAppStore.this.createReceipt(purchaseResponse));
                    return;
                }
                AmazonAppStore.this.mListener.onPurchaseFailed(string2);
            }

            /*
             * Enabled aggressive block sorting
             */
            public void onPurchaseUpdatesResponse(PurchaseUpdatesResponse purchaseUpdatesResponse) {
                if (purchaseUpdatesResponse.getRequestStatus() != PurchaseUpdatesResponse.RequestStatus.SUCCESSFUL) {
                    AmazonAppStore.this.mListener.onQueryPurchasesFail();
                    return;
                }
                ArrayList arrayList = new ArrayList();
                String string2 = purchaseUpdatesResponse.getUserData().getUserId();
                Iterator iterator = purchaseUpdatesResponse.getReceipts().iterator();
                do {
                    if (!iterator.hasNext()) {
                        AmazonAppStore.this.mListener.onQueryPurchasesSuccess((Purchase[])arrayList.toArray((Object[])new Purchase[0]));
                        return;
                    }
                    Receipt receipt = (Receipt)iterator.next();
                    String string3 = receipt.getSku();
                    String string4 = AmazonAppStore.this.createReceipt(string2, receipt.getReceiptId());
                    boolean bl = !receipt.isCanceled();
                    arrayList.add((Object)new Purchase(string3, string4, bl));
                } while (true);
            }

            public void onUserDataResponse(UserDataResponse userDataResponse) {
            }
        };
        this.mListener = storeListener;
        PurchasingService.registerListener((Context)context, (PurchasingListener)this.mPurchasingListener);
        storeListener.onStoreInitialized(true);
    }

    private String createReceipt(PurchaseResponse purchaseResponse) {
        return this.createReceipt(purchaseResponse.getUserData().getUserId(), purchaseResponse.getReceipt().getReceiptId());
    }

    private String createReceipt(String string2, String string3) {
        JSONObject jSONObject = new JSONObject();
        try {
            jSONObject.put("userId", (Object)string2);
            jSONObject.put("receiptId", (Object)string3);
        }
        catch (JSONException var4_4) {
            throw new RuntimeException((Throwable)var4_4);
        }
        return jSONObject.toString();
    }

    @Override
    public void acknowledgePurchase(String string2, String string3) {
        try {
            PurchasingService.notifyFulfillment((String)new JSONObject(string2).getString("receiptId"), (FulfillmentResult)FulfillmentResult.FULFILLED);
            return;
        }
        catch (JSONException var3_3) {
            return;
        }
    }

    @Override
    public void destructor() {
    }

    @Override
    public String getStoreId() {
        return "android.amazonappstore";
    }

    @Override
    public void purchase(String string2, boolean bl, String string3) {
        RequestId requestId = PurchasingService.purchase((String)string2);
        this.mProductIdRequestMapping.put(requestId, string2);
    }

    /*
     * Enabled aggressive block sorting
     */
    @Override
    public void queryProducts(String[] arrstring) {
        Object[] arrobject = new String[arrstring.length];
        int n = 0;
        do {
            if (n >= arrstring.length) {
                PurchasingService.getProductData((Set)new HashSet((Collection)Arrays.asList((Object[])arrobject)));
                return;
            }
            arrobject[n] = arrstring[n].indexOf(".subscription") != -1 ? arrstring[n] + ".child" : arrstring[n];
            ++n;
        } while (true);
    }

    @Override
    public void queryPurchases() {
        PurchasingService.getPurchaseUpdates((boolean)true);
    }

}

