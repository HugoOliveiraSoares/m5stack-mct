#ifdef CARDPUTER
#pragma once

#include "../../entities/ButtonInterfaceBase.h"
#include "utils/Keyboard.h"

using namespace Entities;

namespace Infrastructure::cardputer
{
class Button : public ButtonInterfaceBase
{
  public:
    Button();
    void begin();
    void loop();
    bool isClickNext();
    bool isClickPrevious();
    bool isClickSelect();
    bool isChange();

  private:
    Keyboard_Class _keyboard = Keyboard_Class();
};
} // namespace Infrastructure::cardputer
#endif
