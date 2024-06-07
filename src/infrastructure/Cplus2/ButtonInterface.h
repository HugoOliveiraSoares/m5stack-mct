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
    bool isClickNext();
    bool isClickPrevious();
    bool isClickSelect();

  private:
    ezButton _buttonSelect = ezButton(BUTTON_SELECT_PIN, INPUT_PULLDOWN);
    ezButton _buttonNext = ezButton(BUTTON_NEXT_PIN, INPUT_PULLDOWN);
};
} // namespace Infrastructure::cplus2
#endif
