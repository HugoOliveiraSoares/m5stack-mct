#include "Mfrc522Reader.h"
#include <cstdint>

using namespace Entities::RFID;

Mfrc522Reader::Mfrc522Reader()
{
    this->_mfrc522 = new MFRC522_I2C(0x28, 0);
    this->_mfrc522->PCD_Init();
}

bool Mfrc522Reader::isCardPresent()
{
    return !this->_mfrc522->PICC_IsNewCardPresent() || !this->_mfrc522->PICC_ReadCardSerial();
}

bool Mfrc522Reader::authenticate(uint8_t reg, uint8_t *key, uint8_t *uid)
{
    MFRC522_I2C::MIFARE_Key _key;
    for (int i = 0; i < 6; i++)
    {
        _key.keyByte[i] = *(key + i);
    }

    uint8_t status =
        this->_mfrc522->PCD_Authenticate(MFRC522_I2C::PICC_CMD_MF_AUTH_KEY_A, reg, &_key, &(this->_mfrc522->uid));

    if (status != MFRC522_I2C::STATUS_OK)
    {
        Serial.print(F("Authentication failed: "));
        Serial.println(this->_mfrc522->GetStatusCodeName(status));
        return 0;
    }
    return 1;
}

uint8_t Mfrc522Reader::dumpMemory(uint8_t *uid)
{
}

uint8_t *Mfrc522Reader::readSector(uint8_t reg)
{
}

uint8_t *Mfrc522Reader::readRegister(uint8_t reg)
{
    uint8_t len = 18;
    static uint8_t buffer[18];
    uint8_t status = this->_mfrc522->MIFARE_Read(reg, buffer, &len);

    if (status != MFRC522_I2C::STATUS_OK)
    {
        Serial.print(F("Reading failed: "));
        Serial.println(this->_mfrc522->GetStatusCodeName(status));
        return nullptr;
    }
    return buffer;
}

bool Mfrc522Reader::writeRegister(uint8_t reg, uint8_t *value, uint8_t valueSize)
{
}

bool Mfrc522Reader::setUid(uint8_t *newUid)
{
}

uint8_t *Mfrc522Reader::getUid()
{
    return this->_mfrc522->uid.uidByte;
}

void Mfrc522Reader::stop()
{
    this->_mfrc522->PICC_HaltA();
    this->_mfrc522->PCD_StopCrypto1();
}
