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
    Infrastructure::DeviceBase::begin();
}

void Device::loop()
{
    Infrastructure::DeviceBase::loop();
}
#endif
