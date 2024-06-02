#ifdef CPLUS2
#include "ButtonInterface.h"

using namespace Infrastructure::cplus2;

ButtonInterface::ButtonInterface() : ButtonInterfaceBase()
{
}

void ButtonInterface::begin()
{
    this->_buttonNext.setDebounceTime(DEBOUNCE_MS);

    this->_buttonSelect.setDebounceTime(DEBOUNCE_MS);
}

void ButtonInterface::loop()
{
    this->_buttonNext.loop();
    this->_buttonSelect.loop();
}

bool ButtonInterface::isClickNext()
{
    return this->_buttonNext.isPressed();
}

bool ButtonInterface::isClickPrevious()
{
    return false;
}

bool ButtonInterface::isClickSelect()
{
    return this->_buttonSelect.isPressed();
}

#endif
