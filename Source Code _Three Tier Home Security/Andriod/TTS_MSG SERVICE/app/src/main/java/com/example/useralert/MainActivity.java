package com.example.useralert;

import android.app.Activity;
import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Bundle;
import android.os.Vibrator;
import android.telephony.gsm.SmsManager;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

public class MainActivity extends Activity{
	MediaPlayer mp;
	SmsManager sms;
	Vibrator v;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        long pattern[]={0,100,200,300,400};
        mp=MediaPlayer.create(this,R.raw.tts_home_alert);
        v=(Vibrator)getSystemService(Context.VIBRATOR_SERVICE);
        mp.start();
        v.vibrate(pattern,0);
    }
    public void cancel(View vi)
    {
    	sms=SmsManager.getDefault();
    	sms.sendTextMessage("+918012084546",null,"Suspected Theif Activity @: #1/654,MCN Nagar,Anna 3rd St, Thuraipakkam,Chennai -97",null,null);
    	mp.release();
    	v.cancel();
    	System.exit(0);
    }
    public void exit(View v2)
    {
        finish();
        System.exit(0);
    }
    public void cam(View v3)
    {
        Intent i;
        PackageManager manager = getPackageManager();
        try {
            i = manager.getLaunchIntentForPackage("com.xapcamera");
            if (i == null)
                throw new PackageManager.NameNotFoundException();
            i.addCategory(Intent.CATEGORY_LAUNCHER);
            startActivity(i);
        } catch (PackageManager.NameNotFoundException e) {
            Toast bread = Toast.makeText(getApplicationContext(),"Please Sricam app from playstore", Toast.LENGTH_SHORT);
            bread.show();
        }

    }
    public void onBackPressed()
    {
    	Toast.makeText(this, "press exit button exit!", Toast.LENGTH_LONG).show();
    }
}