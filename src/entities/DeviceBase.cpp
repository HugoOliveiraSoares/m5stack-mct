#include "DeviceBase.h"
#include "ButtonInterfaceBase.h"
#include <memory>

using namespace Entities;

DeviceBase *DeviceBase::_instance = nullptr;

DeviceBase::DeviceBase()
{
    DeviceBase::_instance = this;
}

DeviceBase::DeviceBase(ButtonInterfaceBase *button)
{
    DeviceBase::_instance = this;
    this->_button = button;
}

void DeviceBase::begin()
{
    Serial.begin(115200);

    this->_display = std::make_shared<TFT_eSPI>();

    this->_display->begin();
    this->_display->setFreeFont(nullptr);
    this->_display->setRotation(1);
    this->_display->fillScreen(TFT_BLACK);
    this->_display->setTextDatum(MC_DATUM);
    this->_display->setTextColor(TFT_SKYBLUE);
    this->_display->setTextSize(2);

    this->_button->begin();
}

void DeviceBase::loop()
{
    this->_button->loop();
}

DeviceBase *DeviceBase::getInstance()
{
    return DeviceBase::_instance;
}

std::shared_ptr<TFT_eSPI> DeviceBase::getDisplay()
{
    return this->_display;
}

ButtonInterfaceBase *DeviceBase::getButton()
{
    return this->_button;
}
