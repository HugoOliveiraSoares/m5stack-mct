#pragma once

#include "Wire.h"
#include <stdint.h>

namespace Entities::RFID
{
class RfidModuleInterface
{
  public:
    RfidModuleInterface();
    virtual void dumpMemory(byte uid);
    virtual void readSector(byte reg) = 0;
    virtual void readRegister(byte reg) = 0;
    virtual void writeRegister(byte reg, byte value) = 0;
    virtual void setUid(byte *newUid);

  private:
};

} // namespace Entities::RFID
