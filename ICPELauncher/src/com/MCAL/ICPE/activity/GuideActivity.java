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

public class GuideActivity extends Activity
{
	@Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
		setContentView(R.layout.guide_activity);
		
		SharedPreferences.Editor editor = PreferenceManager.getDefaultSharedPreferences(this).edit();
		if(PreferenceManager.getDefaultSharedPreferences(this).getBoolean("first_loaded",false))
		{
			Intent intent=new Intent(this,com.MCAL.ICPE.activity.StartActivity.class);
			startActivity(intent);
			finish();
		}
		
		((com.gc.materialdesign.views.ButtonFlat)findViewById(R.id.guideactivity_ButtonFlat_UserLegal)).getTextView().getPaint().setFlags(Paint.UNDERLINE_TEXT_FLAG);
		((com.gc.materialdesign.views.ButtonRectangle)findViewById(R.id.guideactivityButtonRectangle)).setEnabled(false);
		
		new Thread(new LoopRnuable()).start();
    }
	
	/*listeners*/
	public void onAgreeLicense(View view)
	{
		if(((com.gc.materialdesign.views.CheckBox)findViewById(R.id.guideactivityCheckBox)).isCheck())
		{
			SharedPreferences.Editor editor = PreferenceManager.getDefaultSharedPreferences(this).edit();
			editor.putBoolean("first_loaded",true);
			editor.commit();
			Intent intent=new Intent(this,com.MCAL.ICPE.activity.MainActivity.class);
			startActivity(intent);
			finish();
		}
	}
	
	public void onReadLicense(View view)
	{
		Intent intent=new Intent(this,com.MCAL.ICPE.activity.LicenseActivity.class);
		startActivity(intent);
	}
	
	
	
	private Handler handler = new Handler()
	{
        @Override
        public void handleMessage(Message msg)
		{
            super.handleMessage(msg);
            if(((com.gc.materialdesign.views.CheckBox)findViewById(R.id.guideactivityCheckBox)).isCheck())
				((com.gc.materialdesign.views.ButtonRectangle)findViewById(R.id.guideactivityButtonRectangle)).setEnabled(true);
			else
				((com.gc.materialdesign.views.ButtonRectangle)findViewById(R.id.guideactivityButtonRectangle)).setEnabled(false);
			
        }
    };
	public class LoopRnuable implements Runnable
	{
		@Override
        public void run()
		{
            while (true)
			{
                try
				{
                    Thread.sleep(250);
                    Message msg = new Message();
                    msg.what = 1;
                    handler.sendMessage(msg);
                }
				catch (InterruptedException e)
				{
                    e.printStackTrace();
                }
            }
        }
    }
}
