#include "DeviceSelect.h"
#include "infrastructure/DeviceBase.h"
#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>

void setup()
{
    Infrastructure::DeviceBase::getInstance()->begin();
}

void loop()
{
    Infrastructure::DeviceBase::getInstance()->loop();
    delay(1000);
}
