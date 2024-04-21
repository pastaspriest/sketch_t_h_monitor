#include "DHT.h"
#include <LiquidCrystal.h>
#define DHTPIN 2 
// Одна из следующих строк закоментирована. Снимите комментарий, если подключаете датчик DHT11 к arduino
// DHT dht(DHTPIN, DHT22); //Инициация датчика
DHT dht(DHTPIN, DHT11);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600);
  dht.begin();

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);

  lcd.write("temp': ");

  lcd.setCursor(0, 1);

  lcd.write("vlazhnost': ");
}
void loop() {
  delay(2000); // 2 секунды задержки
  float h = dht.readHumidity(); //Измеряем влажность
  float t = dht.readTemperature(); //Измеряем температуру
  if (isnan(h) || isnan(t)) {  // Проверка. Если не удается считать показания, выводится «Ошибка считывания», и программа завершает работу
    Serial.println("Ошибка считывания");
    return;
  }
  Serial.print("Влажность: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Температура: ");
  Serial.print(t);
  Serial.println(" *C "); //Вывод показателей на экран

  lcd.setCursor(11, 0);
  lcd.print(t);
  lcd.setCursor(11, 1);
  lcd.print(h);
}