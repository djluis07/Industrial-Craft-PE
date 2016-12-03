package com.MCAL.ICPE.activity;

import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;
import android.view.*;
import android.content.*;
import com.MCAL.ICPE.*;

public class MainActivity extends Activity
{
	@Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
		setContentView(R.layout.main_activity);
    }
	
	/*listeners*/
	
	public void launchGame(View view)
	{
		Intent intent=new Intent(this,LauncherActivity.class);
		startActivity(intent);
		
	}
}
