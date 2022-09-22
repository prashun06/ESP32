
//There are three on board sensors hall effect, touch and tempureture sensor 

#include "Arduino.h" 

#include <WiFi.h> 

//compile the c functions along the c++ libraries on module 
#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();

int touch=32;

const char* ssid       = "AESL";
const char* password   = "@esl_6th";

WiFiClient client;

void setup()
{
Serial.begin(115200);
Serial.println("Touch sensor ESP32");

delay(10);
 
Serial.println("Connecting to ");
Serial.println(ssid);
 
 
WiFi.begin(ssid, password);
 
while (WiFi.status() != WL_CONNECTED) 
{
    delay(500);
    Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
  
}

void loop()
{
    //hall effect sensor 
    int measurement = 0;
    measurement = hallRead();
 
    Serial.print("Hall sensor measurement: ");
    Serial.println(measurement); 
 
    delay(1000);
    
    //touch sensor 
    Serial.print("Touch: ");
    Serial.println(touchRead(touch));
    delay(1000);
 
    //Tempureture sensor
    Serial.print("Temperature: ");
  
    Serial.print((temprature_sens_read() - 32) / 1.8);
    Serial.println(" C");
    delay(1000);
}
