int outPin = 1;

void setup()
{
     pinMode(outPin, OUTPUT);
}

void loop()
{
     digitalWrite(outPin, HIGH);
     delay(10000);
     digitalWrite(outPin, LOW);
     delay(10000);
}
