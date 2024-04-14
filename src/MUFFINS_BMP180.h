#pragma once
#include <Arduino.h>
#include <MUFFINS_Component_Base.h>
#include <SPI.h> // Adafruit base library requires SPI
#include <Adafruit_BMP085.h>

class BMP180 : public Component_Base
{
public:
  struct Config
  {
    TwoWire *wire;
  };

  struct Data
  {
    float temperature;
    int pressure;
  };

private:
  Adafruit_BMP085 _bmp;

  // Local config object
  Config _config;

public:
  /**
   * @brief Construct a new BMP180 object
   */
  BMP180(String component_name = "BMP180", void (*info_function)(String) = nullptr, void (*error_function)(String) = nullptr);

  /**
   * @brief Destroy the BMP180 object
   */
  ~BMP180();

  Data data;

  /**
   * @brief
   *
   * @param config BMP config to be used
   * @return true If configured successfully
   */
  bool begin(const Config &config);

  /**
   * @brief Read temperature and pressure data from BMP180
   *
   * @return true If read successfully
   */
  bool read();
};