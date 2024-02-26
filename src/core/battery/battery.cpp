#include "Battery.h"

Battery::Battery(int _l_delay, int _l_adc_resolution)
{
    _l_delay = u_delay;
    _l_adc_resolution = adc_resolution; 
}

void Battery::begin(void)
{
    analogReadResolution(adc_resolution);
}

float Battery::read_voltage(){
  int adcValue = analogRead(BATTERY_PIN);
  float calibrationFactor = 1.08; // Adjust this value based on your findings
  float voltage = adcValue * (3.3 / 4095.0) * calibrationFactor;
  return voltage;
}

float Battery::battery_voltage(){
    return(read_voltage() * ((R1 + R2) / R2)); 
}

float Battery::battery_percentage(){
    return((read_voltage() - NV) / (CV - NV) * 100);
}

void Battery::battery_info(float &volatile_voltage, float &percentage, float &voltage){
    volatile_voltage = read_voltage();
    percentage = battery_percentage();
    voltage = battery_voltage();
}