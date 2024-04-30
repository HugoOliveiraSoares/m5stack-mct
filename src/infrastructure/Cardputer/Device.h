#ifdef CARDPUTER
#pragma once

#include "../DeviceBase.h"

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
