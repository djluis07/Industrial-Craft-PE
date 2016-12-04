package com.MCAL.ICPE.activity;

import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;
import android.view.*;
import android.content.*;
import com.MCAL.ICPE.*;
import android.graphics.*;
import com.gc.materialdesign.views.*;
import android.os.*;
import android.preference.*;

public class StartActivity extends Activity
{
	@Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
		setContentView(R.layout.start_activity);

		new Thread(new LoopRnuable()).start();
    }

	public class LoopRnuable implements Runnable
	{
		@Override
        public void run()
		{
            try
			{
				Thread.sleep(5000);
				Intent intent=new Intent(StartActivity.this,com.MCAL.ICPE.activity.MainActivity.class);
				startActivity(intent);
				finish();
            }
			catch(Exception e)
			{
				
			}
        }
    }
}
