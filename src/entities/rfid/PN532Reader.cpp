#include "PN532Reader.h"

using namespace Entities::RFID;

PN532Reader::PN532Reader()
{
    this->_pn532i2c = new PN532_I2C(Wire);
    this->_nfc = new PN532(*this->_pn532i2c);

    this->_nfc->begin();
    this->_nfc->SAMConfig();
}
