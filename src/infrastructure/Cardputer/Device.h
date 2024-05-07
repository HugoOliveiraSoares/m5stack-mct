#ifdef CARDPUTER
#pragma once

#include "../../entities/DeviceBase.h"
#include "ButtonInterface.h"

namespace Infrastructure::cardputer
{
class Device : public DeviceBase
{
  public:
    Device();
    String getName();
    void begin();
    void loop();

  private:
};
} // namespace Infrastructure::cardputer
#endif
