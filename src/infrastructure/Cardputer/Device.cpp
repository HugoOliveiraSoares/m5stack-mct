#ifdef CARDPUTER
#include "Device.h"

using namespace Infrastructure::cardputer;

Device::Device() : DeviceBase(new Infrastruture::cardputer::ButtonInterface())
{
}

String Device::getName()
{
    return "M5 Cardputer";
}

void Device::begin()
{
    Entities::DeviceBase::begin();
}

void Device::loop()
{
    Entities::DeviceBase::loop();
}
#endif
