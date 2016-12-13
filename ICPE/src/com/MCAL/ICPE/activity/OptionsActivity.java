package com.MCAL.ICPE.activity;

import com.MCAL.ICPE.R;
import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;
import android.view.*;
import android.content.*;
import android.app.*;
import com.gc.materialdesign.views.*;
import android.widget.*;
import android.database.*;
import java.util.*;
import android.util.*;
import android.view.View.*;
import com.pgyersdk.update.*;
import com.pgyersdk.javabean.*;

public class OptionsActivity extends Activity
{
	@Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
		setContentView(R.layout.options_activity);
    }
	
	public void openEula(View view)
	{
		Intent intent=new Intent(this,LicenseActivity.class);
		startActivity(intent);
	}
	public void openSettings(View view)
	{
		Intent intent=new Intent(this,SettingsActivity.class);
		startActivity(intent);
	}
	public void openJoin(View view)
	{
		Intent intent=new Intent(this,JoinUSActivity.class);
		startActivity(intent);
	}
	public void openUpdate(View view)
	{
		PgyUpdateManager.register(this,new UpdateManagerListener()
			{
				@Override
				public void onUpdateAvailable(final String result)
				{
					AppBean bean = getAppBeanFromString(result);

					Bundle bundle=new Bundle();
					bundle.putString("updateMsg",bean.getReleaseNote());
					bundle.putString("versionName",bean.getVersionName());
					bundle.putString("downloadURL",bean.getDownloadURL());
					
					Intent intent=new Intent(OptionsActivity.this,UpdateActivity.class);
					intent.putExtras(bundle);
					OptionsActivity.this.startActivity(intent);
				}
				@Override
				public void onNoUpdateAvailable()
				{
					com.gc.materialdesign.widgets.Dialog dialog=new com.gc.materialdesign.widgets.Dialog(OptionsActivity.this,getString(R.string.error),getString(R.string.noupdate));
					dialog.addButtonAccept(getString(R.string.cancel));
					dialog.show();
				}
			});
	}
	
	public void exit(View view)
	{
		finish();
	}
}
