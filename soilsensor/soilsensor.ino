#define AOUT_PIN A0 // Arduino pin that connects to AOUT pin of moisture sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(AOUT_PIN); // read the analog value from sensor
  int moisturepercent = map(value,0,1023,100,0);
  Serial.print("Moisture: ");
  Serial.print(moisturepercent);
  Serial.println("%");

  delay(1000);
}
