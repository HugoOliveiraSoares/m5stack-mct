#pragma once

#include "RfidInterface.h"

#include "PN532.h"
#include "PN532_I2C.h"
#include <cstdint>

namespace Entities::RFID
{

class PN532Reader : public RfidModuleInterface
{
  public:
    PN532Reader();
    bool isCardPresent();
    bool authenticate(uint8_t reg, uint8_t *key, uint8_t *uid);
    uint8_t *dumpMemory(uint8_t *uid, uint8_t *key);
    uint8_t *readSector(uint8_t sec);
    uint8_t *readRegister(uint8_t reg);
    bool writeRegister(uint8_t reg, uint8_t *value, uint8_t valueSize);
    bool setUid(uint8_t *newUid);
    uint8_t *getUid();

  private:
    PN532_I2C *_pn532i2c;
    PN532 *_nfc;
    uint8_t _uid[7];
    uint8_t _uidLength;
};

} // namespace Entities::RFID
