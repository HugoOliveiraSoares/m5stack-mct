#include "Mfrc522Reader.h"

using namespace Entities::RFID;

Mfrc522Reader::Mfrc522Reader()
{
}

bool Mfrc522Reader::isCardPresent()
{
}

bool Mfrc522Reader::authenticate(uint8_t reg, uint8_t key, uint8_t uid)
{
}

uint8_t Mfrc522Reader::dumpMemory(uint8_t uid)
{
}

uint8_t Mfrc522Reader::readSector(uint8_t reg)
{
}

uint8_t Mfrc522Reader::readRegister(uint8_t reg)
{
}

bool Mfrc522Reader::writeRegister(uint8_t reg, uint8_t value)
{
}

bool Mfrc522Reader::setUid(uint8_t *newUid)
{
}
