#include "DeviceInterfaceBase.h"
#include "ButtonInterfaceBase.h"

using namespace Entities;

DeviceBase *DeviceBase::_instance = nullptr;

DeviceBase::DeviceBase()
{
    DeviceBase::_instance = this;
}

DeviceBase::DeviceBase(ButtonInterfaceBase *buttonInterface)
{
    DeviceBase::_instance = this;
    this->_buttonInterface = buttonInterface;
}

void DeviceBase::begin()
{
    Serial.begin(115200);
    this->_buttonInterface->begin();
}

void DeviceBase::loop()
{
    // Serial.println(this->getName());
    this->_buttonInterface->loop();

    if (this->_buttonInterface->isChange())
    {
        if (this->_buttonInterface->isClickNext())
        {
            Serial.println("next");
        }

        if (this->_buttonInterface->isClickPrevious())
        {
            Serial.println("previous");
        }

        if (this->_buttonInterface->isClickSelect())
        {
            Serial.println("select");
        }
    }
}

DeviceBase *DeviceBase::getInstance()
{
    return DeviceBase::_instance;
}
