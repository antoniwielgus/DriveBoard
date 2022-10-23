#include <Arduino.h>
#include <HardwareSerial.h>
#include <SoftwareSerial.h>

// SoftwareSerial mySerial(5, 4);






const int length = 12;
char buffer[length];

void setup() 
{
  Serial.begin(9600);

  Serial2.setTX(4);
  Serial2.setRX(5);
  Serial2.begin(9600);

  for (int i = 0; i < length; i++)
    buffer[i] = 7;
  
  // mySerial.begin(9600);

  // Serial2.setTimeout(100);
}

void loop() 
{
  // mySerial.readBytes(buffer, length);

  // Serial2.readBytes(buffer, length);
  // Serial.println(Serial2.read());
  Serial.println(Serial2.readBytes(buffer, length));

  for (int i = 0; i < length; i++)
  {
    Serial.print((uint8_t)buffer[i]);
    Serial.print(" ");
  }

  Serial.println();


  // delay(1000);
}