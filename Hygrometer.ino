#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
#define DHTPIN    A0
#define DHTTYPE   DHT11
DHT dht11(DHTPIN, DHTTYPE);
char temperature[] = "000.0 C";
char humidity[]    = "000.0 %";
void setup()
    {
    delay(1000);
    display.begin();
    dht11.begin();
    display.setContrast(50);
    display.clearDisplay();
    display.display();
    display.drawFastHLine(0, 23, display.width(), BLACK);
    display.setTextSize(1);
    display.setTextColor(BLACK, WHITE);
    display.setCursor(6, 0);
    display.print("TEMPERATURE:");
    display.setCursor(15, 28);
    display.print("HUMIDITY:");
    display.display();
    }
void loop()
    {
    int RH = dht11.readHumidity() * 10;
    int Temp = dht11.readTemperature() * 10;
    if(Temp < 0)
        {
        temperature[0] = '-';
        Temp = abs(Temp);
        }
    else
    temperature[0] = ' ';
    temperature[1] = (Temp / 100) % 10  + '0';
    temperature[2] = (Temp / 10)  % 10  + '0';
    temperature[4] =  Temp % 10 + '0';
    if(RH >= 1000)
    humidity[0] = '1';
    else
    humidity[0] = ' ';
    humidity[1]   = (RH / 100) % 10 + '0';
    humidity[2]   = (RH / 10)  % 10 + '0';
    humidity[4]   =  RH % 10 + '0';
    display.setCursor(18, 12);
    display.print(temperature);
    display.drawRect(50, 12, 3, 3, BLACK);
    display.setCursor(18, 40);
    display.print(humidity);
    display.display();
    delay(1000);
    }