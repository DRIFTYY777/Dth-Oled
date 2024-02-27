#include <Arduino.h>
#include <core/core.h>


Core core(1000, 1000);



void setup()
{
  Serial.begin(115200);
  core.begin();
}

void loop()
{
  core.startbothCore();
}
