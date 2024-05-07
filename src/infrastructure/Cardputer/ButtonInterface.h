#ifdef CARDPUTER
#pragma once

#include "../../entities/ButtonInterfaceBase.h"
#include "utils/Keyboard.h"
#include <ezButton.h>

using namespace Entities;

#define BUTTON_SELECT_PIN 0

namespace Infrastruture::cardputer
{
class ButtonInterface : public ButtonInterfaceBase
{
  public:
    ButtonInterface();
    void begin();
    void loop();
    bool isPressed();
    bool isReleased();

  private:
    ezButton _buttonSelect = ezButton(BUTTON_SELECT_PIN);
};
} // namespace Infrastruture::cardputer
#endif
