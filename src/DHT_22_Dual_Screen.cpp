#include <Arduino.h>
#include "U8g2lib.h"
#include <Wire.h> //Library for I2C interface
#include <dht.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C OLED_Right(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
U8G2_SH1106_128X64_NONAME_F_HW_I2C OLED_Left(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

dht DHT;
#define DHT22_PIN 8

float current_humditiy, new_humidity, current_temp, new_temp = 0;
char temp_buffer[20], humidity_buffer[20];

void get_Current_Readings()
{
    int chk = DHT.read22(DHT22_PIN);
    current_temp = DHT.temperature;
    current_humditiy = DHT.humidity;
}

void setup()
{
    Serial.begin(115200);

    OLED_Right.setI2CAddress(0x3C * 2);
    OLED_Left.setI2CAddress(0x3D * 2);

    OLED_Right.begin();
    OLED_Left.begin();

    OLED_Right.setFont(u8g_font_7x13);
    OLED_Left.setFont(u8g_font_7x13);
}

void loop()
{
    get_Current_Readings();
    if ((new_temp != current_temp) && (new_humidity != current_humditiy))
    {
        new_temp = current_temp;
        new_humidity = current_humditiy;
        OLED_Right.drawStr(15, 10, "===== Temp =====");
        dtostrf((new_temp * 1.8) + 32, 5, 2, temp_buffer); //print value 10
        OLED_Right.drawStr(40, 40, temp_buffer);
        OLED_Right.sendBuffer();  // transfer internal memory to the display
        OLED_Right.clearBuffer(); // clear the internal memory

        OLED_Left.drawStr(10, 10, "=== Humidity ===");
        dtostrf(new_humidity, 5, 2, humidity_buffer); //print value 20
        OLED_Left.drawStr(40, 40, humidity_buffer);
        OLED_Left.sendBuffer();  // transfer internal memory to the display
        OLED_Left.clearBuffer(); // clear the internal memory
    }
    else
    {
        delay(100);
    }

}

