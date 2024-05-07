#include "DeviceSelect.h"
#include "entities/DeviceBase.h"
#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>

Entities::DeviceBase *dev;

std::shared_ptr<TFT_eSPI> display;

void setup()
{
    dev = Entities::DeviceBase::getInstance();

    dev->begin();
    display = dev->getDisplay();
}

void loop()
{
    dev->loop();

    if (dev->getButton()->isPressed())
    {
        display->drawString("Button isPressed", 240 / 2, 135 / 2);
    }
    if (dev->getButton()->isReleased())
    {
        display->fillScreen(TFT_BLACK);
    }
}
