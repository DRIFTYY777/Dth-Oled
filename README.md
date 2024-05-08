# ESP32 DHT11 Temperature and Humidity Monitor with OLED Display

This project demonstrates how to use an ESP32 microcontroller to collect temperature and humidity readings from a DHT11 sensor and display them on an I2C OLED display.

## Features

Reads temperature and humidity data from a DHT11 sensor
Displays the readings on an I2C OLED display
Includes a clear pin configuration diagram for easy setup
## Getting Started

1. Prerequisites

ESP32 development board (any model compatible with Arduino IDE)
DHT11 sensor
I2C OLED display (model and library compatibility required)
Breadboard and jumper wires
Arduino IDE (https://www.arduino.cc/) installed on your computer
2. Hardware Setup

Connect the DHT11 sensor's data pin to DHT11_PIN (pin 1) on the ESP32 board.
Connect the VCC pin of the DHT11 sensor to 3.3V on the ESP32.
Connect the GND pin of the DHT11 sensor to GND on the ESP32.
Connect the SDA (data) and SCL (clock) pins of the OLED display to the corresponding SDA and SCL pins on the ESP32. Refer to your OLED display's datasheet for specific pin details.
Connect the VCC pin of the OLED display to 3.3V on the ESP32.
Connect the GND pin of the OLED display to GND on the ESP32.
## Pin Configuration Diagram

          ESP32 Board
         (Top View)

     3.3V  - |
          |  5V
          |  GND
       DHT11_PIN (1)  - DHT11 Sensor (Data)
          |
       SDA (OLED)    - SDA (I2C Data)
       SCL (OLED)    - SCL (I2C Clock)
          |
       VCC (OLED)   - 3.3V
       GND (OLED)   - GND
3. Software Setup

3.1. Install Libraries

Open the Arduino IDE and go to Sketch > Include Library > Manage Libraries.
Search and install the following libraries (if not already installed):
WiFi library (if needed for future additions)
DHT library (version compatible with your DHT11 sensor)
OLED library (specific to your OLED display model)
Replace placeholder values in the code with appropriate settings for your OLED display (e.g., display size, initialization commands). You might need to adjust these based on your specific display.
3.2. Upload the Code

In the Arduino IDE, open the provided code (ESP32_DHT11_OLED.ino).
Select your ESP32 board and serial port from the Tools menu.
Click the Upload button to upload the code to your ESP32 board.
## Expected Behavior

The code will initialize the OLED display and DHT11 sensor.
It will read temperature and humidity values from the sensor at regular intervals.
The readings will be displayed on the OLED display.
## Additional Notes

Consider error handling and debugging mechanisms in the code for robustness.
Explore advanced features in the OLED library for customization (e.g., fonts, clearing the display).
Experiment with displaying other sensor data (e.g., light level) on the OLED display by connecting additional sensors to your ESP32.
I hope this comprehensive README file empowers you to successfully set up and utilize your ESP32 temperature and humidity monitoring project!
