#ifdef CARDPUTER
#pragma once

#include "../../entities/DeviceInterfaceBase.h"

using namespace Entities;

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
