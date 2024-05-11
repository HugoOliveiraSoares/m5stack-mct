#ifdef CPLUS2
#include "ButtonInterface.h"

using namespace Infrastructure::cplus2;

ButtonInterface::ButtonInterface() : ButtonInterfaceBase()
{
}

void ButtonInterface::begin()
{
    this->_buttonSelect.setDebounceTime(DEBOUNCE_MS);
}

void ButtonInterface::loop()
{
    this->_buttonNext.loop();
    this->_buttonSelect.loop();
}

bool ButtonInterface::isPressed()
{
    return this->_buttonNext.isPressed();
}

bool ButtonInterface::isReleased()
{
    return this->_buttonNext.isReleased();
}

#endif
