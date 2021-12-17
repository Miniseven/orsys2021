#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>
// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 4
#define DHTPIN 5



#define DHTTYPE    DHT11     // DHT 11

DHT_Unified dht(DHTPIN, DHTTYPE);
Adafruit_MPU6050 mpu;
Adafruit_BMP085 bmp;

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
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
  sensors.begin();


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

  sensors.requestTemperatures(); // Send the command to get temperatures
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if(tempC != DEVICE_DISCONNECTED_C) 
  {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  } 
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
