#include "Screen.h"

using namespace Interface;

Screen::Screen()
{
}

Screen::Screen(std::shared_ptr<TFT_eSPI> display)
{
    this->_display = display;
}

Screen *Screen::getPreviousScreen()
{
    return this->_previousScreen;
}

void Screen::setPreviousScreen(Screen *previous)
{
    this->_previousScreen = previous;
}

void Screen::nextButtonPressed()
{
}

void Screen::previousButtonPressed()
{
}

void Screen::selectButtonPressed()
{
}

void Screen::backButtonPressed()
{
}
