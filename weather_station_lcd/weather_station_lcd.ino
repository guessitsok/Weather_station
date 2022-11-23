#include "weather_station.h"

#define DHTPIN 7
#define DHTTYPE DHT11

// создаем объект-экран, передаём используемый адрес
// и разрешение экрана:
LiquidCrystal_I2C lcd(0x38, 16, 2);

// создаем объекты для работы с датчиками
DHT dht(7, DHT11);
Barometer barometer;

void setup() {
  lcd.init();
  // включаем подсветку
  lcd.backlight();
  dht.begin();
  barometer.begin();
}

void loop() {
  dht.read();
  lcd.clear();
  // считываем показания с датчиков
  // Температура, влажность, давление
  float temperature = dht.getTemperatureC();
  int humidity = dht.getHumidity();
  float pressure_mg = barometer.readPressureMillimetersHg();
  // Выводим температуру
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("\x99"
            "C");
  // выводим влажность на дисплей
  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(humidity);
  lcd.print("%");
  // выводим давление на дисплей
  lcd.setCursor(6, 1);
  lcd.print("P:");
  lcd.print(pressure_mg);
  lcd.print("mm");
  delay(3000);
}