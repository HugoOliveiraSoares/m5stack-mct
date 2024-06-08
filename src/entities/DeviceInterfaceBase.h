#pragma once

#include <Arduino.h>
#include <WString.h>

namespace Entities
{
class DeviceBase
{
  public:
    DeviceBase();

    static DeviceBase *getInstance();

    virtual String getName() = 0;
    void begin();
    void loop();

  private:
    static DeviceBase *_instance;
};
} // namespace Entities
