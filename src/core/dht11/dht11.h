
#ifndef DHT_H
#define DHT_H

#include "Arduino.h"

class DHT
{
public:
    DHT(uint8_t pin, uint8_t count = 6);
    void begin(uint8_t usec = 55);
    float readTemperature(bool S = false, bool force = false);
    float convertCtoF(float);
    float convertFtoC(float);
    float computeHeatIndex(bool isFahrenheit = true);
    float computeHeatIndex(float temperature, float percentHumidity,
                           bool isFahrenheit = true);
    float readHumidity(bool force = false);
    bool read(bool force = false);

private:
    uint8_t data[5];
    uint8_t _pin, _type;
    uint32_t _lastreadtime, _maxcycles;
    bool _lastresult;
    uint8_t pullTime; 
    uint32_t expectPulse(bool level);
};

class InterruptLock
{
public:
    InterruptLock()
    {
#if !defined(ARDUINO_ARCH_NRF52)
        noInterrupts();
#endif
    }
    ~InterruptLock()
    {
#if !defined(ARDUINO_ARCH_NRF52)
        interrupts();
#endif
    }
};

#endif
