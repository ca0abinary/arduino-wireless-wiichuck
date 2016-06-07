#include <Wire.h>
#include "ArduinoNunchuck.h"

#define BAUDRATE 9600

ArduinoNunchuck nunchuck = ArduinoNunchuck();

void setup()
{
  Serial.begin(BAUDRATE);
  Serial.print("Init chuck... ");
  while (true) {
    byte result = nunchuck.init();
    if (result != 0) Serial.print(result);
    else break;
    delay(500);
  }
  Serial.println("ready.");
}

void loop()
{
  delay(50);
  
  byte result = nunchuck.update();
  if (result == 0) {

    if ((nunchuck.analogX > 150) || (nunchuck.analogX < 90) ||
        (nunchuck.analogY > 150) || (nunchuck.analogY < 90) ||
        (nunchuck.zButton == 1)) {

      if (nunchuck.analogX > 150) Serial.print('r'); else Serial.print(' ');
      if (nunchuck.analogX < 90) Serial.print('l'); else Serial.print(' ');
      if (nunchuck.analogY > 150) Serial.print('f'); else Serial.print(' ');
      if (nunchuck.analogY < 90) Serial.print('b'); else Serial.print(' ');
      if (nunchuck.zButton == 1) Serial.print('s'); else Serial.print(' ');

      Serial.println("");
    }
  }
}
