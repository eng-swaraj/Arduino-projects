#include <IRremote.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);
const int RECV_PIN=14;
IRrecv irrecv(RECV_PIN);
decode_results results;
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
bool i=true;
bool j=true;
bool k=true;
bool l=true;
bool m=true;
void setup()
{
 lcd.begin(16, 2);

  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  irrecv.enableIRIn();
  irrecv.blink13(true);
 
}
void loop() 
{
  if (irrecv.decode(&results)) 
   {
     Serial.println(results.value,HEX);
     delay(100);
     /////////////////////////
     if(results.value==0xFD08F7)
     {
        i=!i;
        digitalWrite(IN1, i);
        lcd.clear();
        Serial.print("Fan is turned on");
        lcd.print("Fan is  on");
        
     }
     ////////////////////////
     if(results.value==0xFD8877)
     {
        j=!j;
        digitalWrite(IN2, j);
        lcd.clear();
        Serial.print("Bulb is  on");
        lcd.print("Bulb is  on");
       // delay(200);
     }
     if(results.value==0xFD48B7)
     {
        k=!k;
        digitalWrite(IN3, k);
        lcd.clear();
        Serial.print("AC is on");
        lcd.print("AC is on");
       // delay(200);
     }  
     //////////////////////////////
     if(results.value==0xFD28D7)
     {
        l=!l;
        digitalWrite(IN4, l);
        lcd.clear();
        Serial.print("TV is on");
        lcd.print("TV is on");
       // delay(200);
     }
     //////////////////////
     if(results.value==0xFD00FF)
     {
        m=!m;
        digitalWrite(IN1, m);
        digitalWrite(IN2, m);
        digitalWrite(IN3, m);
        digitalWrite(IN4, m);
        lcd.clear();
         lcd.print("ALL appliance off");
       // delay(200);
     }
     irrecv.resume(); // Receive the next value
     //delay(100);
   }
}
