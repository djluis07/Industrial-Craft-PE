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
import android.widget.*;

public class StartActivity extends Activity
{
	@Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
		setContentView(R.layout.start_activity);
		
		WindowManager windowManager = getWindowManager();
        Display display = windowManager.getDefaultDisplay();
        int screenWidth = screenWidth = display.getWidth();
        int screenHeight = screenHeight = display.getHeight();
		ViewGroup.LayoutParams param = ((ImageView)findViewById(R.id.startactivityImageView)).getLayoutParams();
		param.height=param.width=screenHeight/3;
		
		new Thread(new LoopRunnable()).start();
    }

	public class LoopRunnable implements Runnable
	{
		@Override
        public void run()
		{
            try
			{
				Thread.sleep(7500);
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
