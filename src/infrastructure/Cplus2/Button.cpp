#ifdef CPLUS2
#include "Button.h"

using namespace Infrastructure::cplus2;

Button::Button() : ButtonInterfaceBase() {}

void Button::begin() {
  this->_buttonNext.setDebounceTime(50);
  this->_buttonSelect.setDebounceTime(50);
}

void Button::loop() {

  this->_buttonNext.loop();
  this->_buttonSelect.loop();
}

bool Button::isClickNext() { return this->_buttonNext.isPressed(); }

bool Button::isClickPrevious() { return false; }

bool Button::isClickSelect() { return this->_buttonSelect.isPressed(); }

bool Button::isChange() { return true; }

#endif
