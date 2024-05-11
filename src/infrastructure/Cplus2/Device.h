#ifdef CPLUS2
#pragma once

#include "../../entities/DeviceBase.h"
#include "ButtonInterface.h"

namespace Infrastructure::cplus2
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
} // namespace Infrastructure::cplus2
#endif
