#ifdef CARDPUTER
#include "ButtonInterface.h"

using namespace Infrastruture::cardputer;

ButtonInterface::ButtonInterface() : ButtonInterfaceBase()
{
}

void ButtonInterface::begin()
{
    this->_buttonSelect.setDebounceTime(DEBOUNCE_MS);
}

void ButtonInterface::loop()
{
    // this->_buttonNext.loop();
    this->_buttonSelect.loop();
}

bool ButtonInterface::isPressed()
{
    return this->_buttonSelect.isPressed();
}

bool ButtonInterface::isReleased()
{
    return this->_buttonSelect.isReleased();
}

#endif
