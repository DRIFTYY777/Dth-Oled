#include "init.h"

UI ui;
DHT dht(DHT11_PIN);
Battery battery(1000, 12);

int currentWindow = 1;

Init::Init()
{
    return;
}

void Init::readDHTValues(float &temp, float &humi)
{
    humi = dht.readHumidity();
    temp = dht.readTemperature();
}

void Init::button_init()
{
    pinMode(BUTTON_PIN, INPUT);
}

void Init::start()
{
    button_init();
    battery.begin();
    ui.begin();
    dht.begin();
    return;
}

void Init::looper()
{
    if (digitalRead(BUTTON_PIN) == LOW)
    {
        currentWindow = (currentWindow % 2) + 1; // Toggle window
        delay(200);                              // Debounce delay
    }

    if (currentWindow == 1)
    {
        ui.displayBatteryVoltage(battery.battery_voltage(), battery.battery_percentage());
    }
    else
    {
        ui.displayHumiTemp(dht.readHumidity(), dht.readTemperature());
    }
}
