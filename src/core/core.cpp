#include "core.h"
#include "core/pins/pins.h"

#define STACK_SIZE 8192
#define TASK_PRIORITY 2

bool currentWindow = 0; // 0 for window 1, 1 for window 2
bool buttonPressed = false;

int _c1_delay, _c2_delay;

TaskHandle_t Core0Task;
TaskHandle_t Core1Task;

UI ui;
DHT dht(DHT11_PIN);
Battery battery(1000, 12);

void Core::readDHTValues(float &temp, float &humi)
{
    humi = dht.readHumidity();
    temp = dht.readTemperature();
}

void Core::button_init()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
}

Core::Core(int c1_delay, int c2_delay)
{
    _c1_delay = c1_delay;
    _c2_delay = c2_delay;
    // ESP_LOGI(LOG_TAG, "Begin: Core", "Core 0 delay: %d, Core 1 delay: %d", _c1_delay, _c2_delay);
}

void Task1code(void *pvParameters)
{
    for (;;)
    {
        digitalWrite(LED_PIN, HIGH);
        vTaskDelay(pdMS_TO_TICKS(100));
        digitalWrite(LED_PIN, LOW);
    }
    vTaskDelay(pdMS_TO_TICKS(_c1_delay));
}

void Task2code(void *pvParameters)
{
    for (;;)
    {
        bool currentButtonState = !digitalRead(BUTTON_PIN);
        // Check for button press and update state if needed
        if (currentButtonState && !buttonPressed)
        {
            buttonPressed = true;
            currentWindow = !currentWindow; // Toggle between windows
        }
        else if (!currentButtonState)
        {
            buttonPressed = false;
        }

        if (currentWindow)
        {
            ui.displayBatteryVoltage(battery.battery_voltage(), battery.battery_percentage());
        }
        else
        {
            ui.displayHumiTemp(dht.readHumidity(), dht.readTemperature());
        }
    }
    vTaskDelay(pdMS_TO_TICKS(_c2_delay));
}

void Core::startbothCore(void)
{
    xTaskCreatePinnedToCore(Task1code, "Task1", STACK_SIZE, NULL, 2, &Core0Task, 0);
    xTaskCreatePinnedToCore(Task2code, "Task2", STACK_SIZE, NULL, 1, &Core1Task, 1);
}

void Core::begin(void)
{

    button_init();
    battery.begin();
    ui.begin();
    dht.begin();
}