#pragma once

#include "Wire.h"
#include <cstdint>

namespace Entities::RFID
{
class RfidModuleInterface
{
  public:
    RfidModuleInterface()
    {
    }
    virtual bool isCardPresent() = 0;
    virtual bool authenticate(uint8_t reg, uint8_t *key, uint8_t *uid) = 0;
    virtual uint8_t dumpMemory(uint8_t *uid) = 0;
    virtual uint8_t *readSector(uint8_t reg) = 0;
    virtual uint8_t *readRegister(uint8_t reg) = 0;
    virtual bool writeRegister(uint8_t reg, uint8_t *value, uint8_t valueSize) = 0;
    virtual bool setUid(uint8_t *newUid) = 0;
    virtual uint8_t *getUid() = 0;

  private:
};

} // namespace Entities::RFID
