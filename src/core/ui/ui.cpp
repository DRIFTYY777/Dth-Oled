#include "ui.h"

Adafruit_SSD1306 display(128, 64, &Wire, -1);


UI::UI()
{
    return;
}

void UI::begin()
{
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
}

void UI::displayHumiTemp(float humi, float temp)
{
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
}

void UI::displayBatteryVoltage(float voltage, float percentage)
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("Voltage: ");
    display.setTextSize(2);
    display.setCursor(0, 10);
    display.print(voltage);

    display.setTextSize(1);
    display.setCursor(0, 35);
    display.print("Percentage: ");
    display.setTextSize(2);
    display.setCursor(0, 45);
    display.print(percentage);
    display.print("%");

    display.display();
}
