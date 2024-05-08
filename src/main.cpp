#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>

#define DHT11PIN 1
#define BUTTON 34
#define LED 2

Adafruit_SSD1306 display(128, 64, &Wire, -1);
DHT dht(DHT11PIN, DHT11);

TaskHandle_t Core0Task;
TaskHandle_t Core1Task;

void readDHTValues(float &temp, float &humi)
{
  humi = dht.readHumidity();
  temp = dht.readTemperature();
}

void printDHT11(void *pvParameters)
{
  for (;;)
  {
    float humi, temp;

    readDHTValues(temp, humi);

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print("ºC ");
    Serial.print("Humidity: ");
    Serial.println(humi);

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("HUMI: ");

    display.setTextSize(2);
    display.setCursor(0, 10);
    display.print(humi);

    display.setTextSize(1);
    display.setCursor(0, 35);
    display.print("TEMP: ");
    display.setTextSize(2);
    display.setCursor(0, 45);
    display.print(temp);

    display.display();

    vTaskDelay(pdMS_TO_TICKS(2000));
  }
}

void Task2code(void *pvParameters)
{
  for (;;)
  {
  }
}

void setup()
{
  Serial.begin(115200);

  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);

  dht.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
  }
  else
  {
    Serial.println(F("SSD1306 allocation success"));
    delay(2000);
    display.clearDisplay();
    display.setTextColor(WHITE);
  }

  xTaskCreatePinnedToCore(
      printDHT11, /* Task function. */
      "Task1",    /* Name of the task. */
      4096,       /* Stack size of the task. Adjust based on actual usage. */
      NULL,       /* Parameter of the task. */
      2,          /* Priority of the task. Higher value means higher priority. */
      &Core0Task, /* Task handle to keep track of the created task. */
      0);         /* Pin task to core 0. */

  xTaskCreatePinnedToCore(
      Task2code,  /* Task function. */
      "Task2",    /* Name of the task. */
      4096,       /* Stack size of the task. Adjust based on actual usage. */
      NULL,       /* Parameter of the task. */
      1,          /* Priority of the task. Lower value means lower priority. */
      &Core1Task, /* Task handle to keep track of the created task. */
      1);         /* Pin task to core 1. */
  delay(1000);
}

void loop()
{
}
