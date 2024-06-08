#ifdef CARDPUTER
#include "Device.h"

using namespace Infrastructure::cardputer;

Device::Device() : DeviceBase()
{
}

String Device::getName()
{
    return "M5 Cardputer";
}

void Device::begin()
{
    DeviceBase::begin();
}

void Device::loop()
{
    DeviceBase::loop();
}
#endif
