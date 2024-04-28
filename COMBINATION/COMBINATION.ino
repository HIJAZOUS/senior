
#include <RH_ASK.h>// Include RadioHead Amplitude Shift Keying Library
#include <SPI.h> // Include dependant SPI Library 
#include "DHT.h";// Include DHT Libraries from Adafruit, Dependant upon Adafruit_Sensors Library
#include <Arduino.h>
#include <ML8511.h>


// Define Constants
#define AOUT_PIN A0 // Arduino pin that connects to AOUT pin of moisture sensor
#define DHTPIN 13      // DHT-22 Output Pin connection
#define DHTTYPE DHT22   // DHT Type is DHT 22 (AM2302)
#define Uvpin     A1



// Define Variables

float hum;    // Stores humidity value in percent
float temp;   // Stores temperature value in Celcius

// Define output strings

String str_humid;
String str_temp;
String str_soil;
String str_out;
String str_uv;

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

ML8511 light(Uvpin);
DHT dht(DHTPIN, DHTTYPE);// Initialize DHT sensor for normal 16mhz Arduino

void setup() {
 Serial.begin(9600);
  rf_driver.init();// Initialize ASK Object
  dht.begin();// Start DHT Sensor
light.setDUVfactor(1.8);    // calibrate your sensor

}

void loop()
{

  delay(2000);  // Delay so DHT-22 sensor can stabalize
  
   int soil = analogRead(AOUT_PIN); // read the analog value from sensor
  int moisturepercent = map(soil,0,1023,100,0);
  
    hum = dht.readHumidity();  // Get Humidity value
    temp= dht.readTemperature();  // Get Temperature value
  float UV = light.getUV();
  float DUV = light.estimateDUVindex(UV);
  
  
    str_soil = String(moisturepercent);// Convert Temperature to string
    str_humid = String(hum);  // Convert Humidity to string
    str_temp = String(temp);// Convert Temperature to string
    str_uv = String(DUV);
    
    //DATA check on serial monitor
    //Serial.print("Message: ");
    
      
    Serial.println("h="+str_humid);//humidity check
    Serial.println("t="+str_temp);//temperature check
    Serial.println("Moisture= "+str_soil+"%");//soil check
    Serial.println("uv="+str_uv);//uv check
    Serial.println("*********************************");
    
    str_out = str_humid + "," + str_temp + "," + str_soil + "," + str_uv;// Combine Humidity and Temperature
    
    
    static char *msg = str_out.c_str();// Compose output character
    
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(5000);
}