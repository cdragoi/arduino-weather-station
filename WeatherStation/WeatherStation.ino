    /////////////////////////////////////////////////////////////////
   //            Arduino Weather Station                          //
  /////////////////////////////////////////////////////////////////


#include "DHT.h"
#include <LiquidCrystal.h>


#define DHTPIN A1     // what pin we're connected to

#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(8,9,4,5,6,7); 

void setup(void) {
  lcd.begin(16, 2);
  lcd.print("Reading sensor");
  dht.begin();
}

void loop() {
  
  float temperature, humidity;

  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  delay(2000); 

 lcd.clear();

 char tempF[6]; 
 char humF[6];
 dtostrf(temperature, 5, 1, tempF);
 dtostrf(humidity, 2, 0, humF);
 lcd.print("DC Residence");
 lcd.setCursor(0,        1);
 lcd.print("T:"); 
 lcd.print(tempF);
 lcd.print((char)223);
 lcd.print("C ");
 lcd.print("H: ");
 lcd.print(humF);
 lcd.print("%");
 
}
