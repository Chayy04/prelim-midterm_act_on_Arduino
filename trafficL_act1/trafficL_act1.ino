#include <DHT.h>
#define DHTPIN 2   // Pin for DHT11 sensor
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);
 
int potPin = A2;    // Potentiometer pin
int waterPin = A0;  // Water sensor pin
int micPin = A1;    // Microphone sensor pin
int greenLED = 9;
int yellowLED = 10;
int redLED = 11;
 
void setup() {
  Serial.begin(9600);
  dht.begin();
 
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}
 
void loop() {
  int potValue = analogRead(potPin);   // Read potentiometer
  if (potValue >= 0 && potValue <= 300) {
    readDHT11();  // DHT11 mode
  } else if (potValue > 300 && potValue <= 700) {
    readWaterSensor();  // Water sensor mode
  } else if (potValue > 700 && potValue <= 1023) {
    readMicSensor();  // Microphone sensor mode
  }
  delay(1000);  // Delay between readings
}
 
void readDHT11() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
 
  if (temperature < 20) {
    setLEDs(HIGH, LOW, LOW);  // Green LED
  } else if (temperature >= 20 && temperature <= 30) {
    setLEDs(LOW, HIGH, LOW);  // Yellow LED
  } else {
    setLEDs(LOW, LOW, HIGH);  // Red LED
  }
 
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
 
void readWaterSensor() {
  int waterValue = analogRead(waterPin);
 
  if (waterValue < 300) {
    setLEDs(HIGH, LOW, LOW);  // Green LED
  } else if (waterValue >= 300 && waterValue <= 700) {
    setLEDs(LOW, HIGH, LOW);  // Yellow LED
  } else {
    setLEDs(LOW, LOW, HIGH);  // Red LED
  }
 
  Serial.print("Water sensor value: ");
  Serial.println(waterValue);
}
 
void readMicSensor() {
  int soundValue = analogRead(micPin);
 
  if (soundValue < 300) {
    setLEDs(HIGH, LOW, LOW);  // Green LED
  } else if (soundValue >= 300 && soundValue <= 700) {
    setLEDs(LOW, HIGH, LOW);  // Yellow LED
  } else {
    setLEDs(LOW, LOW, HIGH);  // Red LED
  }
 
  Serial.print("Sound level: ");
  Serial.println(soundValue);
}
 
void setLEDs(int greenState, int yellowState, int redState) {
  digitalWrite(greenLED, greenState);
  digitalWrite(yellowLED, yellowState);
  digitalWrite(redLED, redState);
}