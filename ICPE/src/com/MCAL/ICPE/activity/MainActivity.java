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
//		Intent intent=new Intent(this,LauncherActivity.class);
//		startActivity(intent);
//		finish();
		
		com.gc.materialdesign.widgets.Dialog dialog=new com.gc.materialdesign.widgets.Dialog(this,"test","test_message\njj\njj\nagi\nai\nkkkkkkk\n你\nal/\n*?&*/[*?\naopapoqjj\nakoaokgk\nap?\n....");
		dialog.addButtonAccept("gone");
		dialog.addButtonCancel("hh");
		dialog.show();
	}
}
