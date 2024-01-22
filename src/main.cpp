#include <Arduino.h>
#include <DHT.h>
#include "esp_sleep.h"

// Define the pins that we will use
#define DHTPIN 33
#define LED 26
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(DHTPIN, INPUT);
  dht.begin();

  // Attendre un court moment pour stabiliser le capteur
  delay(2000);

  // Lire l'humidité et la température
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Afficher l'humidité et la température
  if (!isnan(humidity) && !isnan(temperature)) {
    Serial.print("Humidité: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Température: ");
    Serial.print(temperature);
    Serial.println(" *C");
  } else {
    Serial.println("Échec de la lecture du capteur DHT");
  }

  Serial.flush();
  // Configuration du mode Deep Sleep
  esp_sleep_enable_timer_wakeup(5 * 1000000); // 5,000,000 microsecondes = 5 secondes
  esp_deep_sleep_start(); // L'ESP32 entre en mode Deep Sleep
}

void loop() {
  // La fonction loop reste vide car l'ESP32 redémarrera après chaque sommeil profond
}