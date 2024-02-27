#ifndef _CORE_H
#define _CORE_H

#include <Arduino.h>
#include "core/pins/pins.h"
#include "core/dht11/dht11.h"
#include "core/ui/ui.h"
#include "core/battery/battery.h"

#define const LOG_TAG "CORE"

class Core
{

public:
    Core(int c1_delay, int c2_delay);
    void begin(void);
    void startbothCore(void);
private:
    void readDHTValues(float &temp, float &humi);
    void button_init();
    
};

#endif