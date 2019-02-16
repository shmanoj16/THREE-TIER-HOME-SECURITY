# THREE-TIER-HOME-SECURITY
An advanced home security system which also uses human odor value to validate the authenticated user.



1.1 GENERAL                 Home  security  has  changed  a  lot  from the  last  century  and  will  be  changing in  coming  years. Security  is  an  important  aspect  or  feature  in  the  smart  home  applications. The new  and  emerging  concept  of  smart  homes  offers  a  comfortable, convenient,  and  safe  environment  for  occupants. Conventional security  systems  keep  homeowners,  and  their property,  safe  from  intruders  by  giving  the  indication  in  terms  of  alarm. However, a smart home security system offers many more benefits. Several modules like GSM, magnetic door sensors, RFID module, odor sensor, IR sensor, Bluetooth etc. The goal of this project is to utilize the after-market parts and build an integrated home security system. Consequently, the proposed system provides reliable security within reasonable cost and also removes the circuit complexity. 
 
1.2 AUTHENTICATION METHODS                In this proposed model, we propose three-tier layer of security measures for any home or office situations. We consider three tiers, the tier 1 security concentrates in authenticating the genuine user to enter his/her house. The authentication is done using RFID tag where it is connected to an Servo motor for locking purpose and family members are given each a unique RFID card where there is an 16-bit key code each distinct from one other and still suffers from problems such as access RFID card losses. There is one master card for the main family person and remaining are all RFID tags, which are portable and used along with vehicle 
2 
 
keychain. In case, of a guest user or loss of RFID tag we implemented a new tier, which authenticates genuine users.               In Tier 2, we developed an Android App (Three Tier Security) where guests can register their data in our database and the owner receives this information and grants permissions to their guests in case the owner is out of town or our relatives need to stay in our house while owner is away. This is done by Bluetooth module and where guest pair with the Bluetooth module and access the door unlock button he/she gains access to the house. Same goes for owner losing his/her RFID tag or master card can access his/her home by Android App for Admin (TTS Admin) this is used only by Owner and it connects with Bluetooth module of Arduino and authenticates access.                In Tier 3, this is worst-case scenario detection of intruders via odor sensor, this is experimental and has been implemented as way to find gas leakage or fire accidents in the house. Also used to find owner using unique smell stored on the module. 
 
 
 
 
 
 
 
 
 
 
 
3 
 
CHAPTER 2 LITERATURE SURVEY 
 
[1]Abhishek S. Parab (2015), ‘Implementation of Home Security System using GSM module and Microcontroller’ 
This system invented to keep home safe from intruder. In this work, we present the design and implementation of a GSM based wireless home security system. which take a very less power. The system is a wireless home network which contains a GSM modem and magnet with relay which are door security nodes. The system can response rapidly as intruder detect and GSM module will do alert home owner. This security system for alerting a house owner wherever he will. In this system a relay and magnet installed at entry point to a precedence produce a signal through a public telecom network and sends a message or redirect a call that that tells about your home update or predefined message which is embedded in microcontroller. Suspected activities are conveyed to remote user through SMS or Call using GSM technology. This system tested on the latest technology available in smartphone which gives a proper result. This system is easy to use and very simple. The model can be installed with a economical cost. The GSM technology gives a good response after received a message of particular action from microcontroller. SMS received time to house owner is basically depend on the signal strength range that you have got through mobile tower. We have developed and tested the model using C language further the same model can be enhanced with the help of some high end language and which would be more portable. This system tested on the latest technology available in smartphone which gives a proper result. This system is easy to use and very simple. The model can be installed with a economical cost. The GSM technology gives a good response after received a message of particular action from 
4 
 
microcontroller. SMS received time to house owner is basically depend on the signal strength range that you have got through mobile tower. We have developed and tested the model using C language further the same model can be enhanced with the help of some high end language and which would be more portable. 
[2]Anandan R, Karthik B, Kiran Kumar Dr.T.V.U (2015), ‘Wireless Home And Industrial Automation Security System Using Gsm’ 
This wireless home and industrial automation and security system can be used to provide security system for residential, industrial, and for all domestic and commercial purposes using GSM  technique. Security systems are certain electronic devices, which are used to detect intrusions in home or industry. The basic components of a home automation security system are motion detectors, LPG detectors and smoke detector. When the internal mode is selected by the user when  they are inside the wireless security area, the entire sensor  except PIR sensor will be activated and the buzzer  connected with the microcontroller will give an alarm and the reason for the insecurity will be displayed in the LCD connected to the microcontroller. In this mode, the electrical appliances in the security area automatically change to the manual mode in which user will control it. When the external mode is selected by the user when  they are outside the wireless security area, all the sensor  will be active and the security area address which is pre- programmed, along with the problem will be sent as SMS  to the specified police station, fire station, security room  and also to the user at the time of insecurity, fire accident,  unwanted movement of persons etc, which is sensed  by the respective sensor. 
 
5 
 
[3]Chintaiah N, Rajasekhar K, Dhanraj V (2011), ‘Automated Advanced Industrial and Home Security Using GSM and FPGA’ 
Home and industrial security today needs to make use of the latest technological components. In this paper I going to present the design and implementation of a remote and sensing, control and home security system based on GSM (Global System for Mobile). This system offers a complete, low cost, powerful and user friendly way of 24 hours of real –time monitoring and remote control of a home and industrial security. The system works as a remote sensing for the electrical appliances at home to check whether it is on or off, at the same time the user can control the electrical appliances at home by sending SMS ( Short Messaging Service) message to the system, for example turning on t he AC before returning home. In case of fire/security the chip will receive signals from the different sensors in the monitoring place and acts according to the received signal by sending an SMS message to user’s Mobile Phone, it also works as automatic and immediate reporting to the user in case of emergency for home security, as well as immediate and automatic reporting to the fire brigade and police station according to activated sensor to decrease the time required for tacking action. In this paper we introduced a remote sensing and control system based on using Global System for Mobil (GSM) and FPGA. The system is suitable for a real time monitoring in home security as well as controlling and sensing in home automation with large number of controlled devices. The system has been design and implemented in hardware using VHDL language and Xilinx Spartan 3E FPGA. GSM has been used for testing the circuit either for the sensing part of the circuit or the control part. The design was simulated  and verified the correctness and working operation of the whole system 
 
 
6 
 
[4]Jayashri Bangali and Arvind Shaligram (2013), ‘Design and Implementation of Security Systems for Smart Home based on GSM technology’ 
Smart Home can be also known as Automated Home or intelligent home, which indicates the automation of daily tasks with electrical appliances used in homes. This could be the control of lights, fans, viewing of the house interiors for surveillance purposes or giving the alarm alteration or indication in case of gas leakage. Home security has changed a lot from the last century and will be changing in coming years. Security is an important aspect or feature in the smart home applications. The new and emerging concept of smart homes offers a comfortable, convenient, and safe environment for occupants. Conventional security systems keep homeowners, and their property, safe from intruders by giving the indication in terms of alarm. However, a smart home security system offers many more benefits. This paper mainly focuses on the security of a home when the user is away from the place. Two systems are proposed, one is based on GSM technology and other uses web camera to detect the intruder. The first security system uses a web camera, installed in house premises, which is operated by software installed on the PC and it uses Internet for communication. The camera detects motion of any intruder in front of the camera dimensions or camera range. The software communicates to the intended user via Internet network and at the same time, it gives sound alert. The second security system is SMS based and uses GSM technology to send the SMS to the owner. The proposed system is aimed at the security of Home against Intruders and Fire. In any of the above cases happens while the owners are out of their home then the device sends SMS to the emergency number which is provided to the system. The system is made up of three components: sensors, GSM-GPS Module (sim548c), Atmega644p microcontroller, relays to control the device and buzzers to give security alert signal in terms of sound. 
7 
 
[5]Raqibull Hasan, Mohammad Monirujjaman Khan, Asaduzzaman Ashek, Israt Jahan Rumpa (2015), ‘Microcontroller Based Home Security System with GSM Technology’ 
In this paper, design and implement of a microcontroller based home security system with GSM technology have been presented and analyzed. Two microcontrollers with other peripheral devices which include Light Emitting Diode (LED), Liquid Crystal Display (LCD), Buzzer and Global System for Mobile Communication (GSM) Module are responsible for reliable operation of the proposed security system. In addition, a mobile phone is interfaced with microcontroller through a Bluetooth device in order to control the system. Moreover, a manual keypad is another way to lock or unlock the system. At last, the results of practical circuit show the proper functions and also verify the reliable security within reasonable cost. This paper presents design and implementation of a smart home security system based on microcontroller along with GSM for user friendly application. The system is intelligent enough to monitor the secure environment. In addition, the user is informed about the security breach through GSM network that provides a special opportunity whenever the user stays at far away from home. However, Android application is the most stunning feature in order to control the system through a Bluetooth device. Moreover, the system provides the reliable operation within reasonable cost and removes the system complexity. In this work, traditional burglar alarm mode, LED lights and LCD are the promising features used to ensure reliability. The whole system is implemented on a practical home security system which requires considerable effort to install it. Consequently, the system is also applicable for commercial purposes due to versatile ways of security and controllability. 