#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>

#define DHTPIN 4
#define DHTTYPE    DHT11     // DHT 11


Adafruit_MPU6050 mpu;
Adafruit_BMP085 bmp;
DHT_Unified dht(DHTPIN, DHTTYPE);
float initialPressure = 0;

void setup() {
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
  }
  else {
    initialPressure = bmp.readPressure();
  }
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  dht.begin();

}

void loop() {

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  sensors_event_t dhtevent;
  dht.temperature().getEvent(&dhtevent);
  dht.humidity().getEvent(&dhtevent);

  float bmpTemp = bmp.readTemperature();
  float bmpPaPress = bmp.readPressure();
  float alt = bmp.readAltitude(initialPressure);

  Serial.print(F("DHT Temperature: "));
  Serial.print(dhtevent.temperature);
  Serial.println(F("°C"));
  Serial.print(F("Humidity: "));
  Serial.print(dhtevent.relative_humidity);
  Serial.println(F("%"));

  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  Serial.print("MPUTemperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");

  Serial.print("Altitude from start = ");
  Serial.print(alt);
  Serial.println(" m");

  Serial.print("BMPTemperature = ");
  Serial.print(bmpTemp);
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(bmpPaPress/100000.0F);
  Serial.println(" Pa");

  

}
