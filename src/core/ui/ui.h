#ifndef UI_H
#define UI_H

#include <core/pins/pins.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>

class UI
{

public:
    UI();
    
    void begin();

    void displayHumiTemp(float humi, float temp);
    void displayBatteryVoltage(float voltage, float percentage);
};

#endif