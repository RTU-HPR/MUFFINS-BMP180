#include <MUFFINS_BMP180.h>

BMP180::BMP180(String component_name, void (*info_function)(String), void (*error_function)(String)) : Component_Base(component_name, info_function, error_function)
{
  return;
}

BMP180::~BMP180()
{
  return;
}

bool BMP180::begin(const Config &config)
{
  _config = config;

  if (!_bmp.begin(0, _config.wire)) // 0 - Ultra low power mode (Must use it, otherwise takes 40ms, because of blocking delay. Setting to 0 still takes 18ms, but it is better) 
  {
    error("Failed to initialize");
    return false;
  }

  info("Initialized");
  set_initialized(true);

  return true;
}

bool BMP180::read()
{
  if (!initialized())
  {
    return false;
  }

  data.temperature = _bmp.readTemperature();
  data.pressure = _bmp.readPressure();
  return true;
}