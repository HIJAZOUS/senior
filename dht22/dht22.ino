#include <DHT22.h>
//define pin data
#define pinDATA 2 // SDA, or almost any other I/O pin

DHT22 dht22(pinDATA); 
 
void setup() {
  Serial.begin(9600); //1bit=10µs
}

void loop() {
 

  float t = dht22.getTemperature();
  float h = dht22.getHumidity();

  Serial.print("h=");
  Serial.print(h);
  Serial.print("\t");
  Serial.print("t=");
  Serial.println(t);
  delay(5000); //Collecting period should be : >1.7 second
}
