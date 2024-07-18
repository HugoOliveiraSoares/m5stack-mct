#include "Mfrc522Reader.h"
#include <cstdint>
#include <cstdlib>
#include <cstring>

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

    // Serial.println("authenticate:: Autenticando o registrador " + String(reg));

    uint8_t status =
        this->_mfrc522->PCD_Authenticate(MFRC522_I2C::PICC_CMD_MF_AUTH_KEY_A, reg, &_key, &(this->_mfrc522->uid));

    if (status != MFRC522_I2C::STATUS_OK)
    {
        Serial.print(F("authenticate:: Authentication failed: "));
        Serial.println(this->_mfrc522->GetStatusCodeName(status));
        return false;
    }

    // Serial.println("authenticate:: Registrador " + String(reg) + " autenticado!");
    return true;
}

uint8_t *Mfrc522Reader::dumpMemory(uint8_t *uid, uint8_t *key)
{
    uint8_t *buffer = (uint8_t *)malloc(1024);

    if (buffer == nullptr)
    {
        Serial.print("dumpMemory:: Error to alloc buffer");
        return nullptr;
    }

    // Serial.println("dumpMemory:: Lendo a memoria!");

    for (uint8_t i = 0; i < 16; i++)
    {
        if (!this->authenticate(i * 4, key, uid))
        {
            free(buffer);
            return nullptr;
        }

        uint8_t *partial_buffer = this->readSector(i);
        if (partial_buffer != nullptr)
        {
            memcpy(buffer + (64 * i), partial_buffer, 64);
            free(partial_buffer);
        }
        else
        {
            free(buffer);
            return nullptr;
        }
    }

    // Serial.println("dumpMemory:: memoria lida!");
    return buffer;
}

uint8_t *Mfrc522Reader::readSector(uint8_t sec)
{
    uint8_t reg = sec * 4;
    uint8_t *buffer = (uint8_t *)malloc(64);
    uint8_t *regData;

    if (buffer == nullptr)
    {
        Serial.print("readSector:: Error to alloc buffer");
        return nullptr;
    }

    // Serial.println("readSector:: Lendo o setor " + String(sec));

    for (uint8_t i = 0; i < 4; i++)
    {
        regData = this->readRegister(reg + i);
        if (regData == nullptr)
        {
            free(buffer);
            return nullptr;
        }
        else
        {
            memcpy(buffer + (i * 16), regData, 16);
        }
    }

    // Serial.println("readSector:: Setor " + String(sec) + " lido!");
    return buffer;
}

uint8_t *Mfrc522Reader::readRegister(uint8_t reg)
{
    uint8_t len = 18;
    static uint8_t buffer[18];

    // Serial.println("readRegister:: Lendo o registrador " + String(reg));
    uint8_t status = this->_mfrc522->MIFARE_Read(reg, buffer, &len);

    if (status != MFRC522_I2C::STATUS_OK)
    {
        Serial.print("Reading register" + String(reg) + " failed: ");
        Serial.println(this->_mfrc522->GetStatusCodeName(status));
        return nullptr;
    }

    // Serial.println("readRegister:: Registrador " + String(reg) + " lido!");
    return buffer;
}

bool Mfrc522Reader::writeRegister(uint8_t reg, uint8_t *value, uint8_t valueSize)
{
    uint8_t status = this->_mfrc522->MIFARE_Write(reg, value, valueSize);
    if (status != MFRC522_I2C::STATUS_OK)
    {
        Serial.print(F("MIFARE_Write() failed: "));
        Serial.println(this->_mfrc522->GetStatusCodeName(status));
        return false;
    }
    return true;
}

bool Mfrc522Reader::setUid(uint8_t *newUid)
{
    return this->_mfrc522->MIFARE_SetUid(newUid, (uint8_t)4, true);
}

uint8_t *Mfrc522Reader::getUid()
{
    return this->_mfrc522->uid.uidByte;
}

void Mfrc522Reader::halt()
{
    this->_mfrc522->PICC_HaltA();
    this->_mfrc522->PCD_StopCrypto1();
}
