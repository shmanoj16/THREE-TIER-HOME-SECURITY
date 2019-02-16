package com.example.useralert;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.telephony.SmsMessage;
import android.widget.Toast;

public class SmsBroadcastReceiver extends BroadcastReceiver {

    public static final String SMS_BUNDLE = "pdus";
    String smsBody="";
    public void onReceive(Context context, Intent intent) {
        Bundle intentExtras = intent.getExtras();
        if (intentExtras != null) {
            Object[] sms = (Object[]) intentExtras.get(SMS_BUNDLE);
            String smsMessageStr = "";
            for (int i = 0; i < sms.length; ++i) {
                SmsMessage smsMessage = SmsMessage.createFromPdu((byte[]) sms[i]);

                smsBody = smsMessage.getMessageBody().toString();
                String address = smsMessage.getOriginatingAddress();
                smsMessageStr += "SMS From: " + address + "\n";
                smsMessageStr += smsBody + "\n";
            }
            if(smsBody.contains("tts_home_alert"))
            {
            	Toast.makeText(context,"Received an alert...", Toast.LENGTH_SHORT).show();
            	Intent i=new Intent();
                i.setClassName("com.example.useralert","com.example.useralert.MainActivity");
                i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                context.startActivity(i);
            }
            else if(smsBody.contains("tts_fire_alert"))
            {
            	Toast.makeText(context,"Fire Alarm....", Toast.LENGTH_SHORT).show();
                Intent i=new Intent();
                i.setClassName("com.example.useralert","com.example.useralert.MainActivity2");
                i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                context.startActivity(i);
            }
            else if(smsBody.contains("tts_guest_user"))
            {
                Toast.makeText(context,"Guest Login", Toast.LENGTH_SHORT).show();
                Intent i=new Intent();
                i.setClassName("com.example.useralert","com.example.useralert.Notification_MainActivity");
                i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                context.startActivity(i);
            }
        }
    }
}