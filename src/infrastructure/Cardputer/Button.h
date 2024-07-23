#ifdef CARDPUTER
#pragma once

#include "../../entities/ButtonInterfaceBase.h"
#include "utils/Keyboard.h"
#include <ezButton.h>

using namespace Entities;

#define BUTTON_SELECT_PIN 0

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

  private:
    ezButton _buttonSelect = ezButton(BUTTON_SELECT_PIN);
    Keyboard_Class _keyboard = Keyboard_Class();
};
} // namespace Infrastructure::cardputer
#endif
