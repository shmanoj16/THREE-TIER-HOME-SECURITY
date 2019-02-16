#include <AddicoreRFID.h>
#include <SPI.h>
#include<Servo.h>
#include<SoftwareSerial.h>
#define  uchar unsigned char
#define uint  unsigned int
uchar fifobytes;
uchar fifoValue;
int bluetoothTx=2;
int bluetoothRx=3;
int gsmTx=4;
int gsmRx=5;
int mq3value1,mq3value2,mq3value3,mq3value4;
SoftwareSerial bluetooth(bluetoothTx,bluetoothRx);
SoftwareSerial gsm(gsmTx,gsmRx);
AddicoreRFID myRFID; 
const int chipSelectPin = 10;
const int NRSTPD = 9;
const int spin=8;
const int spin2=7;
const int mq2=6;
char msg1[]={"tts_guest_user"};
char msg2[]={"authenticated_access"};
char alert1[]={"tts_home_alert"};
char alert2[]={"tts_home_fire"};
int mq2value;
Servo s,s0;
#define MAX_LEN 16
void setup() {                  
  Serial.begin(9600);                         
  delay(100);
  s.attach(spin);
  s0.attach(spin2);
  SPI.begin();
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,INPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(mq2,INPUT);
  digitalWrite(A2,HIGH);
  pinMode(chipSelectPin,OUTPUT);               
  digitalWrite(chipSelectPin, LOW);        
  pinMode(NRSTPD,OUTPUT);                    
    digitalWrite(NRSTPD, HIGH);
  myRFID.AddicoreRFID_Init();  
}
void loop()
{
  bluetooth.begin(9600);
  mq2value=analogRead(A2);
  if(mq2value<100)
  {
    sendSMS(alert2);
    s.write(180);
    for(;mq2value>220;)
    {
      digitalWrite(A0, HIGH);
      digitalWrite(A1, HIGH);
      digitalWrite(A3, HIGH);
      delay(1000);
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A3, LOW);
      mq2value=analogRead(A2);
    }  
    s.write(0);
    bluetooth.end();
  }
  uchar i, tmp, checksum1;
  uchar status;
  bool b=false;
  s.write(0);
      if(bluetooth.available()> 0 )
      {
      int servopos = bluetooth.read();
      if(servopos==0)
      s.write(0);
      else if(servopos==180)
      {
                Serial.println(servopos);
                b=true;
                digitalWrite(A0, HIGH);
                delay(500);
                digitalWrite(A0, LOW);
                delay(500);
                digitalWrite(A0, HIGH);
                delay(500);
                digitalWrite(A0, LOW);
                delay(500);
                digitalWrite(A0, HIGH);
                delay(500);
                digitalWrite(A0, LOW);
                s.write(180);
                digitalWrite(A0, HIGH);
                s.write(180);
                sendSMS(msg1);
                delay(4000*2);
                if(digitalRead(mq2)==LOW)
                {
                  s.write(0);
                  digitalWrite(A0, LOW);
                }
      }
      Serial.println(servopos);      
    }

        uchar str[MAX_LEN];
        uchar RC_size;
        uchar blockAddr;  
        String mynum = "";
        str[1] = 0x4400;
  status = myRFID.AddicoreRFID_Request(PICC_REQIDL, str); 
  if (status == MI_OK)
  {
          Serial.println("RFID tag detected");
          Serial.print("Tag Type:\t\t");
          uint tagType = str[0] << 8;
          tagType = tagType + str[1];
          switch (tagType) {
            case 0x4400:
              Serial.println("Mifare UltraLight");
              break;
            case 0x400:
              Serial.println("Mifare One (S50)");
              break;
            case 0x200:
              Serial.println("Mifare One (S70)");
              break;
            case 0x800:
              Serial.println("Mifare Pro (X)");
              break;
            case 0x4403:
              Serial.println("Mifare DESFire");
              break;
            default:
              Serial.println("Unknown");
              break;
          }
  }
  status = myRFID.AddicoreRFID_Anticoll(str);
  if (status == MI_OK)
  {
          checksum1 = str[0] ^ str[1] ^ str[2] ^ str[3];
          Serial.print("The tag's number is:\t");
          Serial.print(str[0]);
            Serial.print(" , ");
          Serial.print(str[1]);
            Serial.print(" , ");
          Serial.print(str[2]);
            Serial.print(" , ");
          Serial.println(str[3]);

          Serial.print("Read Checksum:\t\t");
            Serial.println(str[4]);
          Serial.print("Calculated Checksum:\t");
            Serial.println(checksum1);
           if(str[0] == 38 && str[1]==159 && str[2]==45 && str[3]==43)
            {   
                digitalWrite(A0, HIGH);
                delay(500);
                digitalWrite(A0, LOW);
                delay(500);
                digitalWrite(A0, HIGH);
                delay(500);
                digitalWrite(A0, LOW);
                delay(500);
                digitalWrite(A0, HIGH);
                delay(500);
                digitalWrite(A0, LOW);
                s.write(180);
                digitalWrite(A0, HIGH);
                sendSMS(msg1);
                delay(3000*2);
                if(digitalRead(mq2)==LOW)
                {
                  s.write(0);
                  digitalWrite(A0, LOW);
                }
                b=true;
                Serial.println("\nHello Guest!\n");
            }
            else if(str[0] == 181&&str[1]==218&&str[2]==218&&str[3]==82) 
            {                                                          
               digitalWrite(A1, HIGH);
                delay(500);
                digitalWrite(A1, LOW);
                delay(500);
                digitalWrite(A1, HIGH);
                delay(500);
                digitalWrite(A1, LOW);
                delay(500);
                digitalWrite(A1, HIGH);
                delay(500);
                digitalWrite(A1, LOW);
                s.write(180);
                digitalWrite(A1, HIGH);
                delay(5000*2);
                if(digitalRead(mq2)==LOW)
                {
                  s.write(0);
                  digitalWrite(A1, LOW);
                }
                b=true;
                Serial.println("\nHello ADMIN!\n");
            }
            else
            {
              Serial.println("Unknown card");
              digitalWrite(A3, HIGH);
              delay(5000);
              digitalWrite(A3, LOW);
            }
            Serial.println();
            delay(1000);
  }
            myRFID.AddicoreRFID_Halt();      
            if(digitalRead(mq2)==HIGH&&b==false)
                {
                mq3value1=analogRead(A4);
                delay(500);
                mq3value2=analogRead(A4);
                delay(500);
                for(;digitalRead(A5)==LOW&&digitalRead(mq2)==HIGH;);
                mq3value3=analogRead(A4);
                delay(500);
                mq3value4=analogRead(A4);
                Serial.print("Odour Value 1:");Serial.println(mq3value1);
                Serial.print("Odour Value 2:");Serial.println(mq3value2);
                Serial.print("Odour Value 3:");Serial.println(mq3value3);
                Serial.print("Odour Value 4:");Serial.println(mq3value4);
                if(mq3value1<310&&mq3value2<310&&mq3value3<310&&mq3value4<310)
                {
                digitalWrite(A3, HIGH);
                s0.write(180);
                delay(1000);
                s0.write(0);
                sendSMS(alert1);
                digitalWrite(A3, LOW);
                }
                else
                {
                sendSMS(msg2);
                for(;digitalRead(A5)==HIGH;);
                }
              }
              if(digitalRead(mq2)==HIGH&&b==true)
              {
              for(;digitalRead(mq2)==HIGH;);
              digitalWrite(A0, HIGH);
              sendSMS(msg1);
              digitalWrite(A0, LOW);
              }              

}
void sendSMS(char message[30])
{
  gsm.begin(9600);
  delay(1000);
  gsm.println("AT+CMGF=1");
  delay(1000);  
  gsm.println("AT+CMGS=\"+917845639909\"\r"); 
  delay(1000);
  gsm.println(message);
  delay(100);
  gsm.println((char)26);
  delay(1000);
  gsm.end();
}



