#pragma once

#include "Screen.h"
#include <TFT_eSPI.h>

namespace Interface
{
class ScreenManager
{
  public:
    ScreenManager();
    ScreenManager(std::shared_ptr<TFT_eSPI> display);
    void setCurrentScreen(Screen *newScreen, bool setPrevious = true);
    void setToPreviousScreen();
    Screen *getCurrentScreen();
    virtual void render();

  private:
    std::shared_ptr<TFT_eSPI> _display;
    Screen *_currentScreen = nullptr;
};
} // namespace Interface
