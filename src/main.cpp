#include <Arduino.h>
#include <core/init.h>


Init inittt;



void setup()
{
  Serial.begin(115200);
  inittt.start();
}

void loop()
{
  inittt.looper();
}
