#include <DHT.h>
DHT dht(8,DHT22);
float humidity;
float temperature;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  if(isnan(temperature) || isnan(humidity)){ //return true if val is not-a-number
    Serial.println("Couldn't read from sensor");
    return;
  }
  Serial.print("Humidity : ");
  Serial.print(humidity);
  Serial.print("% ; Temperature : ");
  Serial.print(temperature);
  Serial.println("Celsius;");
  delay(2000);
}
