#pragma once

#include "RfidInterface.h"
#include <WString.h>

namespace Entities::RFID
{
class Mfrc522Reader : public RfidModuleInterface
{
  public:
    Mfrc522Reader();
    bool isCardPresent();
    bool authenticate(uint8_t reg, uint8_t key, uint8_t uid);
    uint8_t dumpMemory(uint8_t uid);
    uint8_t readSector(uint8_t reg);
    uint8_t readRegister(uint8_t reg);
    bool writeRegister(uint8_t reg, uint8_t value);
    bool setUid(uint8_t *newUid);

  private:
};

} // namespace Entities::RFID
