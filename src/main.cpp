#include <Arduino.h>
#include <DHT.h>

// Define the pins that we will use
#define DHTPIN 33
#define LED 26
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(DHTPIN,INPUT);
  dht.begin();
}

void loop() {
  delay(5000); // Attendre 5 secondes

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Afficher l'humidité et la température
  Serial.print("Humidité: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Température: ");
  Serial.print(temperature);
  Serial.println(" *C");

}