#ifdef CPLUS2
#pragma once

#include "../../entities/ButtonInterfaceBase.h"
#include <ezButton.h>

using namespace Entities;

#define BUTTON_SELECT_PIN 37
#define BUTTON_NEXT_PIN 39

namespace Infrastructure::cplus2
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
    ezButton _buttonNext = ezButton(BUTTON_NEXT_PIN);
};
} // namespace Infrastructure::cplus2
#endif
