#ifndef INIT_H
#define INIT_H

#include "core/pins/pins.h"
#include "core/dht11/dht11.h"
#include "core/ui/ui.h"
#include "core/battery/battery.h"


class Init
{
public:
    Init();

    void start();
    void looper();
    void readDHTValues(float &temp, float &humi);

private:
    void button_init();
};


#endif
