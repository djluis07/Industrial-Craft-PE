package com.MCAL.ICPE.activity;

import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;
import android.view.*;
import android.content.*;
import com.MCAL.ICPE.*;
import android.net.*;

public class JoinUSActivity extends Activity
{
	@Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
		setContentView(R.layout.join_us_activity);
    }
	
	public void join_ICPEDevTeam(View vuew)
	{
		try
		{
			joinQQGroup("6eSTSpyNGyXZZeNUeTZTaWjXD6HkKkB1");
		}
		catch(Exception e)
		{
			newDialogNoQQ();
		}
	}
	
	public void join_MCALTeam(View view)
	{
		try
		{
			joinQQGroup("_jbrPze9XRfZUJuc88WVSoxSlabSWpAY");
		}
		catch(Exception e)
		{
			newDialogNoQQ();
		}
	}
	
	protected void newDialogNoQQ()
	{
		com.gc.materialdesign.widgets.Dialog dialog=new com.gc.materialdesign.widgets.Dialog(this,getString(R.string.error),getString(R.string.no_qq));
		dialog.addButtonAccept(getString(R.string.cancel));
		dialog.show();
	}
	
	protected void joinQQGroup(String key) throws Exception
	{
		Intent intent = new Intent();
		intent.setData(Uri.parse("mqqopensdkapi://bizAgent/qm/qr?url=http%3A%2F%2Fqm.qq.com%2Fcgi-bin%2Fqm%2Fqr%3Ffrom%3Dapp%26p%3Dandroid%26k%3D" + key));
		intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
		try
		{
			startActivity(intent);
		}
		catch (Exception e)
		{
			throw new Exception("No QQ Found.");
		}
	}
	
}
