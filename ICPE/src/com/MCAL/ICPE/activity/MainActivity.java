package com.MCAL.ICPE.activity;

import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;
import android.view.*;
import android.content.*;
import com.MCAL.ICPE.*;
import android.app.*;
import com.gc.materialdesign.views.*;
import android.widget.*;
import android.database.*;
import java.util.*;
import android.util.*;
import android.view.View.*;

public class MainActivity extends Activity
{
	@Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
		setContentView(R.layout.main_activity);
    }
	
	public void launchGame(View view)
	{
		com.gc.materialdesign.widgets.Dialog dialog=new com.gc.materialdesign.widgets.Dialog(this,getString(R.string.launch_title),getString(R.string.launch_message));
		dialog.addButtonCancel(getString(R.string.launch_by_mcpelauncher),new View.OnClickListener()
		{
			@Override
			public void onClick(View p1)
			{
				Intent intent = MainActivity.this.getPackageManager().getLaunchIntentForPackage("net.zhuoweizhang.mcpelauncher.pro");
				if (intent==null)
				{
					Intent intent2 = MainActivity.this.getPackageManager().getLaunchIntentForPackage("net.zhuoweizhang.mcpelauncher");
					if(intent2!=null)
						startActivity(intent2);
					else
					{
//						Intent intent3=new Intent(MainActivity.this,ErrorActivity.class);
//						startActivity(intent3);
					}
				}
				else
					startActivity(intent);
			}
		});
		dialog.addButtonAccept(getString(R.string.launch_by_self),new View.OnClickListener()
		{

			@Override
			public void onClick(View p1)
			{
				Intent intent=new Intent(MainActivity.this,LauncherActivity.class);
				startActivity(intent);
				finish();
			}
		});
		dialog.show();
	}
	
	
	public void gotoOptions(View view)
	{
		Intent intent=new Intent(this,OptionsActivity.class);
		startActivity(intent);
	}
}
