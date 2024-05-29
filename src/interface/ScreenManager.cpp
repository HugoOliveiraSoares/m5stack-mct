#include "ScreenManager.h"

using namespace Interface;

std::shared_ptr<TFT_eSPI> ScreenManager::_display = nullptr;
Screen *ScreenManager::_currentScreen = nullptr;

void ScreenManager::init(std::shared_ptr<TFT_eSPI> display)
{
    _display = display;
}

void ScreenManager::setCurrentScreen(Screen *newScreen, bool setPrevious)
{

    if (newScreen == nullptr)
        Serial.println("ERROR: newScreen is null");

    if (setPrevious)
        newScreen->setPreviousScreen(_currentScreen);

    _currentScreen = newScreen;
    render();
}

void ScreenManager::setToPreviousScreen()
{
    auto previousScreen = _currentScreen->getPreviousScreen();
    if (previousScreen != nullptr)
    {
        // auto screenToDelete = _currentScreen;
        // _currentScreen = nullptr;
        // delete screenToDelete;

        setCurrentScreen(previousScreen, false);
    }
}

Screen *ScreenManager::getCurrentScreen()
{
    return _currentScreen;
}

void ScreenManager::render()
{
    _display->fillScreen(TFT_BLACK);

    _currentScreen->render();
}
