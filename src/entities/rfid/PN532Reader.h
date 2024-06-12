#pragma once

#include "RfidInterface.h"

#include "PN532.h"
#include "PN532_I2C.h"

namespace Entities::RFID
{

class PN532Reader : public RfidModuleInterface
{
  public:
    PN532Reader();
    void dumpMemory();
    void readSector(byte reg);
    void readRegister(byte reg);
    void writeRegister(byte reg, byte value);
    void setUid(byte *newUid);

  private:
    PN532_I2C *_pn532i2c;
    PN532 *_nfc;
};

} // namespace Entities::RFID
