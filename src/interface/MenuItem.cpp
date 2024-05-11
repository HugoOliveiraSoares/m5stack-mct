#include "Menu.h"

using namespace Interface;

MenuItem::MenuItem()
{
}

MenuItem::MenuItem(String id, String text)
{
    this->_id = id;
    this->_text = text;
}

String MenuItem::getText()
{
    return this->_text;
}

bool MenuItem::isDefinedOnClick()
{
    return this->_onClick != nullptr;
}

void MenuItem::click()
{
    if (this->_onClick)
        this->_onClick();
    else
        Serial.println("Nenhuma função de clique definida");
}

void MenuItem::setOnClick(std::function<void()> onClick)
{
    this->_onClick = onClick;
}
