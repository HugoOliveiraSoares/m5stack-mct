#ifdef CARDPUTER
#include "Device.h"

using namespace Infrastructure::cardputer;

Device::Device() : DeviceBase(new Infrastructure::cardputer::Button())
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
