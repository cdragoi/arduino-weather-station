    /////////////////////////////////////////////////////////////////
   //            Arduino Weather Station                          //
  /////////////////////////////////////////////////////////////////
#include "DHT.h"
#include <LiquidCrystal.h>
#define DHTPIN A3     // what pin we're connected to
#define DHTTYPE DHT11
  
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(8,9,4,5,6,7); 
int thresholdDry = 600;
int thresholdWet = 230;
int pump =3;
void setup(void) {
  Serial.begin(9600);
  pinMode(pump, OUTPUT);
  //lcd.begin(16, 2);
  //lcd.print("Reading sensor");
  //dht.begin();
}

void loop() {
  
  //float temperature, humidity;

  //humidity = dht.readHumidity();
  //temperature = dht.readTemperature();
  int sensorValue = analogRead(A1);
  //int val = map(sensorValue, 0, 700, 0, 255);
  //int val = sensorValue/70;
  delay(2000); 

 //lcd.clear();

 //char tempF[6]; 
 //char humF[6];
 //dtostrf(temperature, 5, 1, tempF);
 //dtostrf(humidity, 2, 0, humF);
//  lcd.print("T:"); 
// lcd.print(tempF);
// lcd.print((char)223);
// lcd.print("C ");
// lcd.print("H: ");
// lcd.print(humF);
// lcd.print("%");
// lcd.setCursor(0,        1);
 //lcd.print("Joey: ");
  if (sensorValue >= thresholdDry){
    Serial.print("Joey is thirsty");
    digitalWrite(pump, LOW);
    delay(4000);
    digitalWrite(pump, HIGH);
    //delay(60000);
    }
  else if (sensorValue >= thresholdWet){ 
    Serial.print("Joey is fine!");
    Serial.print(sensorValue);
   digitalWrite(pump, HIGH);
  }
  
 
}
