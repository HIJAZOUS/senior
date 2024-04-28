//
//    FILE: ML8511_DUV_index.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo UV sensor
//    DATE: 2020-06-21
//     URL: https://github.com/RobTillaart/ML8511
//
//          BREAKOUT
//        +-------+--+
//    VIN |o      +-+| mounting hole
//    3V3 |o      +-+|
//    GND |o         |
// a0 OUT |o         |
//PIN7 EN |o       S |  Sensor
//        +----------+
//
//   EN = ENABLE


#include <Arduino.h>
#include <ML8511.h>

#define ANALOGPIN     A1
//#define ENABLEPIN     7

ML8511 light(ANALOGPIN);


void setup()
{
  Serial.begin(9600);

  // manually enable / disable the sensor.
  //light.enable();
  light.setDUVfactor(1.8);    // calibrate your sensor
  Serial.print("DUV index");
  Serial.println();
}


void loop()
{
  float UV = light.getUV();
  float DUV = light.estimateDUVindex(UV);
  Serial.print(DUV, 1);
  Serial.println();
  delay(1000);
}


// -- END OF FILE --

