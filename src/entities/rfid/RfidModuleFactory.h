#include "ModulesEnum.h"
#include "RfidInterface.h"
#include "mfrc522/Mfrc522Reader.h"
#include "pn532/PN532Reader.h"
#include <iostream>
#include <stdexcept>
#include <string>

namespace Entities::RFID
{
class RfidModuleFactory
{
  public:
    static RfidModuleInterface *createRfidModule(ModulesEnum module)
    {

        switch (module)
        {
        case ModulesEnum::MFRC522:
            return new Mfrc522Reader();
            break;
        case ModulesEnum::PN532:
            return new PN532Reader();
            break;
        default:
            throw std::runtime_error("Unsupported RFID module type");
        }
    }
};
} // namespace Entities::RFID
