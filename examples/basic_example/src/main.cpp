#include <Arduino.h>
#include <MUFFINS_BMP180.h>

const int SENSOR_POWER_ENABLE_PIN = 17;
const int WIRE0_SCL = 1;
const int WIRE0_SDA = 0;

BMP180 bmp;

BMP180::Config bmp_config = {
  .wire = &Wire,
};

void setup()
{
  Serial.begin(115200);
  while(!Serial)
  {
    delay(1000);
  }
  
  pinMode(SENSOR_POWER_ENABLE_PIN, OUTPUT_12MA);
  digitalWrite(SENSOR_POWER_ENABLE_PIN, HIGH);

  if (Wire.setSCL(WIRE0_SCL) && Wire.setSDA(WIRE0_SDA))
  {
    Wire.begin();
  }

  if (!bmp.begin(bmp_config))
  {
    while (1)
      ;
  }
}

void loop()
{
  bmp.read();
  Serial.print("Temperature: ");
  Serial.print(bmp.data.temperature);
  Serial.print(" C | Pressure: ");
  Serial.print(bmp.data.pressure);
  Serial.println(" Pa");
  delay(100);
}