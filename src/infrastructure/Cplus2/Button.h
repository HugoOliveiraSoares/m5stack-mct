#ifdef CPLUS2
#pragma once

#define BUTTONNEXT 39
#define BUTTONSELECT 37

#include "../../entities/ButtonInterfaceBase.h"
#include <ezButton.h>

using namespace Entities;

namespace Infrastructure::cplus2 {
class Button : public ButtonInterfaceBase {
public:
  Button();
  void begin();
  void loop();
  bool isClickNext();
  bool isClickPrevious();
  bool isClickSelect();
  bool isChange();

private:
  ezButton _buttonNext = ezButton(BUTTONNEXT);
  ezButton _buttonSelect = ezButton(BUTTONSELECT);
};
} // namespace Infrastructure::cplus2
#endif
