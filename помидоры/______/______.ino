#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>  
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // (RS, E, DB4, DB5, DB6, DB7)
DHT dht(6, DHT11);

void setup() {
pinMode(7, OUTPUT); //помпа
Serial.begin(9600);
dht.begin();
lcd.begin(16,2); 
lcd.clear();
lcd.print("begin");
delay(1000);
lcd.clear();
}

void loop() {
  
digitalWrite(7,LOW );
lcd.clear();
int earth=analogRead(A0);
int earthproz=map(earth,280,630,100,0);
int h=dht.readHumidity();
int t=dht.readTemperature(); 
Serial.println(earthproz);
lcd.setCursor(0,0);
lcd.print("s=");
lcd.print(earthproz) ;
delay(10);
lcd.setCursor(6,0);
lcd.print("t=");
lcd.setCursor(8,0);
lcd.print(t);
delay(10);
lcd.setCursor(11, 0);
lcd.print("h=");
lcd.setCursor(13, 0);
lcd.print(h);
delay(1000);

if(earthproz<10){ // процентное содержание почвы,подобрать 
lcd.clear();
digitalWrite(7, HIGH); 
lcd.setCursor(0, 0);
lcd.print("water");
delay(2000); //зависит от длины трубки 
}
else {
loop();
}

}
  


 
  
