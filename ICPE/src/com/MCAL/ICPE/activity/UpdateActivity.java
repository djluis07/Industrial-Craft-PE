package com.MCAL.ICPE.activity;

import android.app.*;
import android.content.*;
import android.net.*;
import android.os.*;
import android.view.*;
import android.widget.*;
import com.MCAL.ICPE.*;
import java.io.*;
import java.net.*;

public class UpdateActivity extends Activity
{
	protected String downloadURL="";
	protected com.gc.materialdesign.widgets.ProgressDialog progressDialog;
	protected int maxProgress=0;
	protected int progress=0;
	@Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
		setContentView(R.layout.update_activity);
		
		downloadURL=getIntent().getExtras().getString("downloadURL");
		
		String versionName=getIntent().getExtras().getString("versionName");
		String updateMsg=getIntent().getExtras().getString("updateMsg");
		
		((TextView)findViewById(R.id.updateactivityTextViewVersionName)).setText(versionName);
		((TextView)findViewById(R.id.updateactivityTextViewUpdateMsg)).setText(updateMsg);
    }
	
	public void download(View view)
	{
		new Thread()
		{
			public void run()
			{
				Looper.prepare();
				try
				{
					down_file(downloadURL, Environment.getExternalStorageDirectory() + "/ICPE/ICPE.apk");
				}
				catch (Exception e)
				{
					e.printStackTrace();
				} 
			}  
		}.start();
	}
	
	private Handler handler = new Handler(){  
		@Override
		public void handleMessage(Message msg)  
		{
			if (!Thread.currentThread().isInterrupted())
			{  
				switch (msg.what)
				{  
					case 0:
						progressDialog=new com.gc.materialdesign.widgets.ProgressDialog(UpdateActivity.this,getString(R.string.downloadProgress) + "0%");
						progressDialog.setCancelable(false);
						progressDialog.show();
					case 1:
						if(progressDialog==null)
							return;
						int result = progress * 100 / maxProgress;  
						progressDialog.setTitle(result + "%");
					break;  
					case 2:
						progressDialog.dismiss();
						progressDialog=null;
						com.gc.materialdesign.widgets.Dialog dialog=new com.gc.materialdesign.widgets.Dialog(UpdateActivity.this,getString(R.string.download_done),getString(R.string.install_now));
						dialog.addButtonAccept(getString(R.string.install),new View.OnClickListener()
						{
							@Override
							public void onClick(View p1)
							{
								Intent intent = new Intent(Intent.ACTION_VIEW);
								intent.setDataAndType(Uri.fromFile(new File(Environment.getExternalStorageDirectory() + "/ICPE/ICPE.apk")),
													  "application/vnd.android.package-archive");
								UpdateActivity.this.startActivity(intent);
							}
						});
						dialog.addButtonCancel(getString(R.string.cancel));
						dialog.show();
					break;  
					case -1:  
						String error = msg.getData().getString("error");
						Toast.makeText(UpdateActivity.this, error, Toast.LENGTH_SHORT).show();  
					break;  
				}  
			}  
			super.handleMessage(msg);  
		}  
	};

	public void down_file(String url,String fpath) throws IOException
	{
		String filename = fpath.substring(fpath.lastIndexOf("/") + 1);  
		String path = fpath.substring(0,fpath.lastIndexOf("/") + 1);
		URL myURL = new URL(url);
		URLConnection conn = myURL.openConnection();  
		conn.connect();
		InputStream is = conn.getInputStream();  
		this.maxProgress = conn.getContentLength();  
		if (this.maxProgress <= 0) 
			throw new RuntimeException("can not fount file size.");  
		if (is == null) 
			throw new RuntimeException("stream is null");
		File file1 = new File(path);
		File file2 = new File(path+filename);
		if(!file1.exists())
			file1.mkdirs();
		file2.createNewFile();
		FileOutputStream fos = new FileOutputStream(path+filename);
		byte buf[] = new byte[1024];
		progress = 0;
		sendMsg(0);
		do
		{
			int numread = is.read(buf);  
			if (numread == -1)
				break;
			fos.write(buf, 0, numread);  
			progress += numread;  
			sendMsg(1);
		}
		while (true); 

		sendMsg(2);  

		try
		{  
			is.close();  
		}
		catch (Exception ex)
		{  
			 
		}  

	}  
	
	private void sendMsg(int flag)  
	{  
		Message msg = new Message();  
		msg.what = flag;  
		handler.sendMessage(msg);  
	}    
}
