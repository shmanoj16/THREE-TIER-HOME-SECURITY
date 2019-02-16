package com.example.useralert;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Vibrator;
import android.app.Activity;
import android.content.Context;
import android.telephony.gsm.SmsManager;
import android.view.Menu;
import android.view.View;
import android.widget.Toast;

public class MainActivity2 extends Activity {
	MediaPlayer mp;
	SmsManager sms;
	Vibrator v;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        long pattern[]={0,100,200,300,400};
        setContentView(R.layout.activity_main_activity2);
        mp=MediaPlayer.create(this,R.raw.tts_main_fire);
        v=(Vibrator)getSystemService(Context.VIBRATOR_SERVICE);
        mp.start();
        v.vibrate(pattern,0);
    }
    public void cancel(View vi)
    {
    	sms=SmsManager.getDefault();
    	sms.sendTextMessage("+919551881733",null,"Suspected Fire Alert @: #1/654,MCN Nagar,Anna 3rd St, Thuraipakkam,Chennai -97",null,null);
    	mp.release();
    	v.cancel();
    	System.exit(0);
    }
    public void exit(View v2)
    {
        finish();
        System.exit(0);
    }
    public void onBackPressed()
    {
    	Toast.makeText(this, "press cancel to exit!", Toast.LENGTH_LONG).show();
    }
}
