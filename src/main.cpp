#include "DeviceSelect.h"
#include "entities/DeviceInterfaceBase.h"
#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>

using namespace Entities;

DeviceBase *dev;

void setup()
{
    dev = DeviceBase::getInstance();
    dev->begin();
}

void loop()
{
    dev->loop();
    delay(1000);
}
