#ifdef CPLUS2
#include "Device.h"

using namespace Infrastructure::cplus2;

Device::Device() : DeviceBase(new Infrastructure::cplus2::ButtonInterface())
{
}

String Device::getName()
{
    return "M5 StickCPlus2";
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
