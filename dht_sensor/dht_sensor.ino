// библиотека для работы с датчиками серии DHT
#include <TroykaDHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11
// создаём объект класса DHT
// передаём номер пина к которому подключён датчик и тип датчика
// типы сенсоров: DHT11, DHT21, DHT22
DHT dht(4, DHT11);
 
void setup()
{
  // открываем последовательный порт для мониторинга действий в программе
  Serial.begin(9600);
  dht.begin();
  
  
}

float temperature_c = 0.0;
float temperature_k = 0.0;
float temperature_f = 0.0;
float humidity = 0.0;
void loop()
{
  // считывание данных с датчика
  dht.read();
  // проверяем состояние данных
  switch(dht.getState()) {
    // всё OK
    case DHT_OK:
      temperature_c = dht.getTemperatureC();
      temperature_k = dht.getTemperatureK();
      temperature_f = dht.getTemperatureF();
      humidity = dht.getHumidity();
      // выводим показания влажности и температуры
      Serial.print("Temperature = ");
      Serial.print(temperature_c);
      Serial.println(" C \t");
      Serial.print("Temperature = ");
      Serial.print(temperature_k);
      Serial.println(" K \t");
      Serial.print("Temperature = ");
      Serial.print(temperature_f);
      Serial.println(" F \t");
      Serial.print("Humidity = ");
      Serial.print(humidity);
      Serial.println(" %");
      break;
    // ошибка контрольной суммы
    case DHT_ERROR_CHECKSUM:
      Serial.println("Checksum error");
      break;
    // превышение времени ожидания
    case DHT_ERROR_TIMEOUT:
      Serial.println("Time out error");
      break;
    // данных нет, датчик не реагирует или отсутствует
    case DHT_ERROR_NO_REPLY:
      Serial.println("Sensor not connected");
      break;
  }
 
  // ждём две секунды
  delay(2000);
}