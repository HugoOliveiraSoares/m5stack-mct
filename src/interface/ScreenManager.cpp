#include "ScreenManager.h"

using namespace Interface;

ScreenManager::ScreenManager()
{
}

ScreenManager::ScreenManager(std::shared_ptr<TFT_eSPI> display)
{
    this->_display = display;
}

void ScreenManager::setCurrentScreen(Screen *newScreen, bool setPrevious)
{

    if (newScreen == nullptr)
        Serial.println("ERROR: newScreen is null");

    if (setPrevious)
        newScreen->setPreviousScreen(this->_currentScreen);

    this->_currentScreen = newScreen;
    this->render();
}

void ScreenManager::setToPreviousScreen()
{
    auto previousScreen = this->_currentScreen->getPreviousScreen();
    if (previousScreen != nullptr)
    {
        // auto screenToDelete = this->_currentScreen;
        // this->_currentScreen = nullptr;
        // delete screenToDelete;

        this->setCurrentScreen(previousScreen, false);
    }
}

Screen *ScreenManager::getCurrentScreen()
{
    return this->_currentScreen;
}

void ScreenManager::render()
{
    this->_display->fillScreen(TFT_BLACK);

    this->_currentScreen->render();
}
