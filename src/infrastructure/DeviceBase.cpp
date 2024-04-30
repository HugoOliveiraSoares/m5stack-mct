#include "DeviceBase.h"

using namespace Infrastructure;

DeviceBase *DeviceBase::_instance = nullptr;

DeviceBase::DeviceBase()
{
    DeviceBase::_instance = this;
}

void DeviceBase::begin()
{
    Serial.begin(115200);
}

void DeviceBase::loop()
{
    Serial.println(this->getName());
}

DeviceBase *DeviceBase::getInstance()
{
    return DeviceBase::_instance;
}
