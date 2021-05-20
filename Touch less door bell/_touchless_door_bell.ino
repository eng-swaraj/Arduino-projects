//                TOUCHLESS MUSICAL DOOR BELL

//Since we need to maintain social distancing in this time of COVID-19, I think my project will help in maintaining social distancing as COVID-19 spreads through contact.
//By bringing our hands near the sensor there will bw no direct contact and the door bell rings.
//COMPONENTS USED : ARDUINO UNO, BREADBOARD, PIR SENSOR, BUZZER, JUMPER WIRES


//-------------------------CODE----------------------------------------------

#include<LiquidCrystal.h>
int signalpin=2;//declaring signalpin connection to arduino
int buzzerpin=3;//declaring positive pin of buzzerpin connected to arduino
int rs=12;
int en=11;
int d4=7;
int d5=6;
int d6=5;
int d7=4;
LiquidCrystal lcd1(rs,en,d4,d5,d6,d7);
void setup()
{
  pinMode(signalpin,INPUT);//since pir sensor receives the signal
  pinMode(buzzerpin,OUTPUT);//since buzzzer produces output as sound
  lcd1.begin(16,2);//initializing rows ad columns
  lcd1.setCursor(0,0);//settting cursor to the (0,0)th position
  lcd1.print("SHOW YOUR HAND ");//printing on first line
  lcd1.setCursor(0,1);//setting cursor on the (0,1)th position
  lcd1.print("TO RING THE BELL");//printing second line
  
}

void loop()
{
  if(digitalRead(signalpin)==HIGH)//if pir sensor is activated
    {tone(buzzerpin,200);//buzzerpin produces sound of frequency 200
     delay(50);//a delay time of 0.5 seconds
     tone(buzzerpin,500);//frequency 500
     delay(50);//delay 0.5 sec
     tone(buzzerpin,900);//frequency 900
     delay(50);//delay 0.5 sec
     tone(buzzerpin,1000);//frequency 1000
     delay(50);//delay 0.5 sec
     tone(buzzerpin,1300);//frequency 1300
     delay(50);//delay 0.5 sec
     tone(buzzerpin,1800);//frequecy 1800
     delay(50);//delay 0.5 sec
     
    }
  else
    {noTone(buzzerpin);//if pir sensor is not activated no sound produced
    } 
}