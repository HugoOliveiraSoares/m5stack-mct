#ifdef CARDPUTER
#include "Button.h"

using namespace Infrastructure::cardputer;

Button::Button() : ButtonInterfaceBase()
{
}

void Button::begin()
{
    this->_buttonSelect.setDebounceTime(DEBOUNCE_MS);
    this->_keyboard.begin();
}

void Button::loop()
{
    this->_keyboard.updateKeyList();
    this->_keyboard.updateKeysState();

    this->_buttonSelect.loop();
}

bool Button::isClickNext()
{
    return this->_keyboard.isKeyPressed('.');
}

bool Button::isClickPrevious()
{
    return this->_keyboard.isKeyPressed(';');
}

bool Button::isClickSelect()
{
    return this->_keyboard.isKeyPressed(KEY_ENTER) || this->_buttonSelect.isPressed();
}

#endif
