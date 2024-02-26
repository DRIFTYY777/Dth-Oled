

#ifndef _CORE_H
#define _CORE_H

#include <Arduino.h>

TaskHandle_t Core0Task;
TaskHandle_t Core1Task;

class Core
{
public:
    void core_main(void *pvParameters);

private:
    static void Task1code(void *pvParameters);
    static void Task2code(void *pvParameters);
};

#endif