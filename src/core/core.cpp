#include "core.h"

void Core::Task1code(void *pvParameters)
{
    for (;;)
    {
        

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
void Core::Task2code(void *pvParameters)
{
    for (;;)
    {

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
void Core::core_main(void *pvParameters)
{
    xTaskCreatePinnedToCore(
        Task1code,  /* Task function. */
        "Task1",    /* Name of the task. */
        10000,      /* Stack size of the task. */
        NULL,       /* Parameter of the task. */
        1,          /* Priority of the task. */
        &Core0Task, /* Task handle to keep track of the created task. */
        0);         /* Pin task to core 0. */

    xTaskCreatePinnedToCore(
        Task2code,  /* Task function. */
        "Task2",    /* Name of the task. */
        10000,      /* Stack size of the task. */
        NULL,       /* Parameter of the task. */
        1,          /* Priority of the task. */
        &Core1Task, /* Task handle to keep track of the created task. */
        1);         /* Pin task to core 1. */
}