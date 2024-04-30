#ifdef CPLUS2
#include "Device.h"

using namespace Infrastructure::cplus2;

Device::Device() : DeviceBase()

{
}

String Device::getName()
{
    return "M5 StickCPlus2";
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
