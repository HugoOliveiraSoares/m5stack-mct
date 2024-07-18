#include "PN532Reader.h"
#include <cstdint>
#include <cstring>
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
    uint8_t *buffer = new uint8_t[1024];
    uint8_t *sectorData;

    for (int i = 0; i < 16; i++)
    {
        if (!this->authenticate(i * 4, key, uid))
        {
            delete[] buffer;
            return nullptr;
        }
        sectorData = this->readSector(i);
        if (sectorData == nullptr)
        {
            delete[] buffer;
            return nullptr;
        }

        memcpy(buffer + i * 64, sectorData, 64);
        delete[] sectorData;
    }

    return buffer;
}

uint8_t *PN532Reader::readSector(uint8_t sec)
{
    uint8_t reg = sec * 4;
    uint8_t *buffer = new uint8_t[64];
    uint8_t *regData;

    for (int i = 0; i < 4; i++)
    {
        regData = this->readRegister(reg + i);
        if (regData == nullptr)
        {
            delete[] buffer;
            return nullptr;
        }
        else
        {
            memcpy(buffer + i * 16, regData, 16);
            delete[] regData;
        }
    }

    return buffer;
}

uint8_t *PN532Reader::readRegister(uint8_t reg)
{
    uint8_t *buffer = new uint8_t[16];
    this->_nfc->mifareclassic_ReadDataBlock(reg, buffer);
    return buffer;
}

bool PN532Reader::writeRegister(uint8_t reg, uint8_t *value, uint8_t valueSize)
{
    return this->_nfc->mifareclassic_WriteDataBlock(reg, value);
}

// TODO: Not implemented yet
bool PN532Reader::setUid(uint8_t *newUid)
{
    return false;
}

uint8_t *PN532Reader::getUid()
{
    return this->_uid;
}
