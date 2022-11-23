// Библиотека для работы с модулями IMU
#include <TroykaIMU.h>
#include <TroykaDHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11
// Создаём объект для работы с барометром
Barometer barometer;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Открываем последовательный порт
  Serial.begin(9600);
  // Выводим сообщение о начале инициализации
  Serial.println("IMU Begin");
  // Инициализируем барометр
  barometer.begin();
  // Инициализируем датчик температуры и влажности
  dht.begin();
  // Выводим сообщение об удачной инициализации
  Serial.println("Initialization completed");  
}

float dht_temperature_c = 0.0;
float dht_temperature_k = 0.0;
float dht_temperature_f = 0.0;
float dht_humidity = 0.0;
float barometer_temperature_c = 0.0;
float barometer_pressure = 0.0;
 
void loop() {
    // Начинаем считывать данные с датчика DHT11
    dht.read();
    dht_temperature_c = dht.getTemperatureC();
    dht_temperature_k = dht.getTemperatureK();
    dht_temperature_f = dht.getTemperatureF();
    dht_humidity = dht.getHumidity();
    barometer_temperature_c = barometer.readTemperatureC();
    barometer_pressure = barometer.readPressureMillimetersHg(); 
    Serial.print("dht_temp_c: ");
    Serial.print(dht_temperature_c);
    Serial.print(" ");
    Serial.print("dht_temp_k: ");
    Serial.print(dht_temperature_k);
    Serial.print(" ");
    Serial.print("dht_temp_f: ");
    Serial.print(dht_temperature_f);
    Serial.print(" ");
    Serial.print("dht_humidity: ");
    Serial.print(dht_humidity);
    Serial.print(" ");
    // Выводим значения атмосферного давления в мм рт.ст.
    Serial.print("Pressure: ");
    Serial.print(barometer_pressure);
    // Выводим значения температуры окружающей среды
    Serial.print(" ");
    Serial.print("barometer_temp_c: "); 
    Serial.print(barometer_temperature_c);
    Serial.println();
    delay(3000);
}