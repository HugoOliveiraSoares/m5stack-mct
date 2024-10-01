#ifdef CARDPUTER
#include "Button.h"

using namespace Infrastructure::cardputer;

Button::Button() : ButtonInterfaceBase()
{
}

void Button::begin()
{
    this->_keyboard.begin();
}

void Button::loop()
{
    this->_keyboard.updateKeyList();
    this->_keyboard.updateKeysState();
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
    return this->_keyboard.isKeyPressed(KEY_ENTER);
}

bool Button::isChange()
{
    return this->_keyboard.isChange();
}

#endif
