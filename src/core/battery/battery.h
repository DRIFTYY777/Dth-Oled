#ifndef _BATTERY_H
#define _BATTERY_H

#include <core/pins/pins.h>
#include <Arduino.h>

#define mAH 3000  // Battery capacity in mAh
#define NV 3.85   // Nominal voltage
#define CV 4.4    // Charge voltage
#define R1 220000 // Voltage divider resistor 220ohm
#define R2 220000 // Voltage divider resistor 220ohm




class Battery
{
public:
    Battery(int l_delay, int l_adc_resolution);
    void begin(void);
    float read_voltage();
    float battery_voltage();
    float battery_percentage();
    void battery_info(float &volatile_voltage, float &percentage, float &voltage);
private:
    int u_delay;
    int adc_resolution = 12;

};

#endif