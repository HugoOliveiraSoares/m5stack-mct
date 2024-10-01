#ifdef CPLUS2
#include "Device.h"
#include "Button.h"

using namespace Infrastructure::cplus2;

Device::Device()
    : DeviceBase(new Infrastructure::cplus2::Button())

{}

String Device::getName() { return "M5 StickCPlus2"; }

void Device::begin() { DeviceBase::begin(); }

void Device::loop() { DeviceBase::loop(); }
#endif
