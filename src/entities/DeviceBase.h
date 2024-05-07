#pragma once

#include "ButtonInterfaceBase.h"
#include <Arduino.h>
#include <TFT_eSPI.h>
#include <WString.h>
#include <memory>

namespace Entities
{
class DeviceBase
{
  public:
    DeviceBase();
    DeviceBase(ButtonInterfaceBase *button);

    static DeviceBase *getInstance();

    void begin();
    void loop();
    virtual String getName() = 0;
    std::shared_ptr<TFT_eSPI> getDisplay();
    ButtonInterfaceBase *getButton();

  private:
    static DeviceBase *_instance;
    ButtonInterfaceBase *_button;
    std::shared_ptr<TFT_eSPI> _display;
};
} // namespace Entities
