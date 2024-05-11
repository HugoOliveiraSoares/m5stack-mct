#include "Menu.h"

using namespace Interface;

Menu::Menu()
{
}

Menu::Menu(std::shared_ptr<TFT_eSPI> display, ButtonInterfaceBase *button)
{
    this->_display = display;
    this->_button = button;
}

void Menu::render()
{
    this->_display->fillScreen(TFT_BLACK);
    this->_display->setCursor(40, 40);

    for (int i = 0; i < this->_items.size(); i++)
    {
        this->_display->setCursor(40, this->_display->getCursorY());

        if (cursor == i)
            this->_display->printf("> %s\n", this->_items[i].getText());
        else
            this->_display->printf("%s\n", this->_items[i].getText());
    }
}

void Menu::addItem(MenuItem item)
{
    this->_items.push_back(item);
}

void Menu::nextItem()
{

    if (this->cursor < this->_items.size() - 1)
        this->cursor++;
    else
        this->cursor = 0;

    this->render();
}

void Menu::previousItem()
{
    if (this->cursor > 0)
        this->cursor--;
    else
        this->cursor = this->_items.size() - 1;

    this->render();
}

void Menu::selectItem()
{
    Serial.printf("selectItem: %s \t isDefinedOnClick: %d \n", this->_items[cursor].getText(),
                  this->_items[cursor].isDefinedOnClick());

    Serial.print(" Menu: keysState ");
    Serial.println(this->_button->isPressed());

    this->_items[cursor].click();
}

void Menu::nextButtonPressed()
{
    Serial.println("nextItem");
    this->nextItem();
}

void Menu::previousButtonPressed()
{
    Serial.println("previousItem");
    this->previousItem();
}

void Menu::selectButtonPressed()
{
    Serial.println("selectItem");
    this->selectItem();
}
