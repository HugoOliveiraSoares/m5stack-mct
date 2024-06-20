#include "PN532Reader.h"
#include <cstdint>
#include <stdexcept>

using namespace Entities::RFID;

PN532Reader::PN532Reader()
{
    this->_pn532i2c = new PN532_I2C(Wire);
    this->_nfc = new PN532(*this->_pn532i2c);

    this->_nfc->begin();
    uint32_t version = this->_nfc->getFirmwareVersion();
    if (!version)
    {
        throw std::runtime_error("Didn't find PN532 board");
    }

    this->_nfc->SAMConfig();
}

bool PN532Reader::isCardPresent()
{
    return this->_nfc->readPassiveTargetID(PN532_MIFARE_ISO14443A, this->_uid, &this->_uidLength);
}

bool PN532Reader::authenticate(uint8_t reg, uint8_t *key, uint8_t *uid)
{
    return this->_nfc->mifareclassic_AuthenticateBlock(uid, this->_uidLength, reg, 0, key);
}

uint8_t *PN532Reader::dumpMemory(uint8_t *uid, uint8_t *key)
{
    return nullptr;
}

uint8_t *PN532Reader::readSector(uint8_t sec)
{
    return nullptr;
}

uint8_t *PN532Reader::readRegister(uint8_t reg)
{
    return nullptr;
}

bool PN532Reader::writeRegister(uint8_t reg, uint8_t *value, uint8_t valueSize)
{
    return false;
}

bool PN532Reader::setUid(uint8_t *newUid)
{
    return false;
}

uint8_t *PN532Reader::getUid()
{
    return this->_uid;
}
