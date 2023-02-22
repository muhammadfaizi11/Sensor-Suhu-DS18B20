//Library Sensor Suhu
#include <OneWire.h>
#include <DallasTemperature.h>

//GPIO pin ESP32
int pinSuhu = 4;

//Setup onewire to commpiunicate with any other onewire
OneWire oneWire(pinSuhu);

//Onewire to dallas temperature
DallasTemperature sensors(&oneWire);

void setup(){
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin(); //Start Sensor DS18B20 
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
//  float temperatureF = sensors.getTempFByIndex(0);
  Serial.print(temperatureC);
  Serial.println("ºC");
//  Serial.print(temperatureF);
//  Serial.println("ºF");
  delay(2500);
}
