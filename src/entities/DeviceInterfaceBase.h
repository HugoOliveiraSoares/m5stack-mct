#pragma once

#include "ButtonInterfaceBase.h"
#include <Arduino.h>
#include <WString.h>

namespace Entities
{
class DeviceBase
{
  public:
    DeviceBase();
    DeviceBase(ButtonInterfaceBase *buttonInterface);

    static DeviceBase *getInstance();

    virtual String getName() = 0;
    void begin();
    void loop();

  private:
    static DeviceBase *_instance;
    ButtonInterfaceBase *_buttonInterface;
};
} // namespace Entities
