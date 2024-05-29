#ifdef CARDPUTER
#include "ButtonInterface.h"

using namespace Infrastruture::cardputer;

ButtonInterface::ButtonInterface() : ButtonInterfaceBase()
{
}

void ButtonInterface::begin()
{
    // this->_buttonSelect.setDebounceTime(DEBOUNCE_MS);
    this->_keyboard.begin();
}

void ButtonInterface::loop()
{
    this->_keyboard.updateKeyList();
    this->_keyboard.updateKeysState();

    // this->_buttonSelect.loop();
}

bool ButtonInterface::isClickNext()
{
    return this->_keyboard.isKeyPressed('.');
}

bool ButtonInterface::isClickPrevious()
{
    return this->_keyboard.isKeyPressed(';');
}

bool ButtonInterface::isClickSelect()
{
    return this->_keyboard.isKeyPressed(KEY_ENTER);
}

#endif
