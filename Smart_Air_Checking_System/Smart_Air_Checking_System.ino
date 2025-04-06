#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Sensor Pins
#define MQ2_PIN A0
#define MQ135_PIN A2
#define ONE_WIRE_BUS 2

// Thresholds 
#define LPG_THRESHOLD 1000
#define CO_THRESHOLD 70
#define SMOKE_THRESHOLD 200
#define AIRQ_THRESHOLD 200

// MQ2 Calibration Constants 
#define RO_LPG 9.8       // Ro for LPG in clean air
#define RO_CO 10.0       // Ro for CO in clean air
#define RO_SMOKE 8.5     // Ro for Smoke in clean air

SoftwareSerial bluetooth(3, 4); // RX, TX
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature tempSensor(&oneWire);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  tempSensor.begin();
}

void loop() {
  // Read sensor values
  float lpg = readGas(MQ2_PIN, RO_LPG, -0.4, 0.6);  // LPG parameters
  float co = readGas(MQ2_PIN, RO_CO, -0.5, 0.7);     // CO parameters
  float smoke = readGas(MQ2_PIN, RO_SMOKE, -0.4, 0.5); // Smoke parameters
  float airQuality = readAirQuality();
  float temp = readTemperature();

  // Check thresholds and send warnings
  checkThresholds(lpg, co, smoke, airQuality);

  // Print normal readings to Serial
  Serial.print("Air Quality: ");
  Serial.print(airQuality);
  Serial.print(" PPM, Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  // Handle Bluetooth commands
  handleBluetooth(lpg, co, smoke, airQuality, temp);
  
  delay(2000); // Reading interval
}

float readGas(int pin, float ro, float a, float b) {
  int value = analogRead(pin);
  float voltage = value * (5.0 / 1023.0);
  float rs = (5.0 - voltage) / voltage;
  float ratio = rs / ro;
  return pow(10, (log10(ratio) - b) / a);
}

float readAirQuality() {
  int value = analogRead(MQ135_PIN);
  return value * (1000.0 / 1023.0); // Example conversion
}

float readTemperature() {
  tempSensor.requestTemperatures();
  return tempSensor.getTempCByIndex(0);
}

void checkThresholds(float lpg, float co, float smoke, float airQ) {
  if(lpg > LPG_THRESHOLD) sendWarning("LPG", lpg);
  if(co > CO_THRESHOLD) sendWarning("CO", co);
  if(smoke > SMOKE_THRESHOLD) sendWarning("Smoke", smoke);
  if(airQ > AIRQ_THRESHOLD) sendWarning("Air Quality", airQ);
}

void sendWarning(String gas, float value) {
  String msg = "Warning: " + gas + " value exceeds threshold - " + String(value) + " ppm";
  Serial.println(msg);
  bluetooth.println(msg);
}

void handleBluetooth(float lpg, float co, float smoke, float airQ, float temp) {
  if(bluetooth.available()) {
    char cmd = bluetooth.read();
    
    switch(cmd) {
      case 'R':
        bluetooth.print("LPG:");
        bluetooth.print(lpg, 5);
        bluetooth.print("ppm CO:");
        bluetooth.print(co, 5);
        bluetooth.print("ppm SMOKE:");
        bluetooth.print(smoke, 5);
        bluetooth.println("ppm");
        break;
        
      case 'A':
        bluetooth.print("Air Quality: ");
        bluetooth.print(airQ);
        bluetooth.print("ppm Temperature:");
        bluetooth.print(temp, 2);
        bluetooth.println("°C");
        break;
    }
  }
}