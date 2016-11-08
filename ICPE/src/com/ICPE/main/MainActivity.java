/**********************************
 * Industrial Craft : PE Source Code
 * CopyRight © 2016-2017 MCAL Team(MinecraftPE Addons Laboratory Team)
 * Developded BY ModelPart
 **********************************/

package com.ICPE.main;

import android.app.*;
import android.os.*;
import android.view.*;
import android.content.*;
import android.net.*;

public class MainActivity extends Activity
{
	@Override
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main_activity);
	}
	
	//listeners
	public void onInstallClicked(View view)
	{

	}
	
	public void onUpDataClicked(View view)
	{
		
	}
	
	public void onGithubPageClicked(View view)
	{
		Intent intent = new Intent();        
        intent.setAction("android.intent.action.VIEW");    
        Uri content_url = Uri.parse("https://github.com/ModelPart/Industrial-Craft-PE.git");   
        intent.setData(content_url);  
        startActivity(intent);
	}
	
	public void onSettingsClicked(View view)
	{

	}
}
