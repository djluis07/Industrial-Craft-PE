package com.MCAL.ICPE;

import android.app.*;

public class ICPEApplication extends Application
{
	@Override
	public void onCreate()
	{
		super.onCreate();
		
		onTerminate();
	}
}
