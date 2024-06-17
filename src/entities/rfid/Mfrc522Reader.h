#pragma once

#include "MFRC522_I2C.h"
#include "RfidInterface.h"
#include <WString.h>
#include <cstdint>

namespace Entities::RFID
{
class Mfrc522Reader : public RfidModuleInterface
{
  public:
    Mfrc522Reader();
    bool isCardPresent();
    bool authenticate(uint8_t reg, uint8_t *key, uint8_t *uid);
    uint8_t *dumpMemory(uint8_t *uid, uint8_t *key);
    uint8_t *readSector(uint8_t sec);
    uint8_t *readRegister(uint8_t reg);
    bool writeRegister(uint8_t reg, uint8_t *value, uint8_t valueSize);
    bool setUid(uint8_t *newUid);
    uint8_t *getUid();
    void stop();

  private:
    MFRC522_I2C *_mfrc522;
};

} // namespace Entities::RFID
