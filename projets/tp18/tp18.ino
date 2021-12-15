// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"
#include <Wire.h>
#include <LCD_I2C.h>
#define DHTTYPE DHT11   // DHT 11
#define DHTPIN 2 
LCD_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

Adafruit_MPU6050 mpu;

void setup(void) {
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  
  Serial.print("Set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.print("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.print("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.print("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.print("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }

  Serial.println("");
  delay(100);
}

void loop() {
  temperature();
  gyro();
}
void gyro(){
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  lcd.setCursor(0,0);
  lcd.print("Accel X: ");
  lcd.print(a.acceleration.x);
  lcd.setCursor(0,1);
  lcd.print("Y:");
  lcd.print(a.acceleration.y);
  lcd.setCursor(9,1);
  lcd.print("Z:");
  lcd.print(a.acceleration.z);
  delay(1000);
  Serial.println(" m/s^2");
  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");
}

void temperature(){
  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");
  delay(500);
   float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) 
    Serial.println(F("Failed to read from DHT sensor!"));
    return;


  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
 
  lcd.setCursor(0,0);
  lcd.print(F("Humid: "));
  lcd.print(h);
  lcd.print(F("%"));
  lcd.setCursor(0,1);
  lcd.print(F("Temp: "));
  lcd.print(t);
  lcd.print(F("deg C"));
  delay(1000);
}
