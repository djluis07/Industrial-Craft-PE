package com.MCAL.ICPE.activity;

import android.app.*;
import android.content.*;
import android.net.*;
import android.os.*;
import com.MCAL.ICPE.*;

public class NOMCPEActivity extends Activity
{
	@Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
		setContentView(R.layout.nomcpe_activity);
    }
	
	protected void uninstallApp()
	{
		Intent intent = new Intent();
		intent.setAction(Intent.ACTION_DELETE);
		intent.setData(Uri.parse("package:"+this.getPackageName()));
		startActivity(intent);
	}
}
