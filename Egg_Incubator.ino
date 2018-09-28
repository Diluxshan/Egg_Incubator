
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);   



#include "DHT.h"
#define DHTPIN 2          // modify to the pin we connected
#define DHTTYPE DHT11    // AM2301 
 
DHT dht(DHTPIN, DHTTYPE);

 
 
void setup() 
{
  pinMode(5 , INPUT);
  
  lcd.init();                     
  lcd.init();
  
Serial.begin(9600);
 dht.begin();
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);

Serial.println("welcome to GREEEN EYE Incubator"); 

}

void loop() {  

  boolean buttonState = digitalRead(5);
       if (buttonState == 1)
       {   lcd.backlight();      
         //  Right(5000);
       }
       else{lcd.noBacklight();}  // No any action
 
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 
//lcd.backlight();


Serial.print("Temparature :  ");
Serial.print(t);

  lcd.setCursor(0,0);   // Column+1 - Row+1
  lcd.print("Temp : ");
  lcd.print(t);
  lcd.print(" C");

Serial.print("\t Humidity :  " );
Serial.print(h);
Serial.println("%" );

  lcd.setCursor(0,1);
  lcd.print("Humi : ");
  lcd.print(h);
  lcd.print(" %");

//..................................................................
  
if( t < 37.00)
{
   digitalWrite(13,HIGH);
   digitalWrite(12,LOW);
  }

else if ( t >=39.00)
{
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
}


//else if ( DHT.temperature == 39.00)
//{
//  digitalWrite(13,LOW);
//  digitalWrite(12,HIGH);
//}

else if( t == 37.00 )
{
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  }

delay(2000);

}


//......................
 
void Right (int interval){
   static long prevMill = 0;
   if (((long)millis() - prevMill) >= interval){ 
    prevMill = millis(); 
    digitalWrite(12, !digitalRead(12));
  }
 }
