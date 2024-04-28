#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile


RH_ASK driver;

void setup()
{
  pinMode(A1, OUTPUT);
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    const char *msg = "hiiiiiii";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    digitalWrite(A1, HIGH);
    delay(1000);
    digitalWrite(A1, LOW);
    delay(1000);
}
