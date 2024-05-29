#pragma once

#include "Screen.h"
#include <TFT_eSPI.h>

namespace Interface
{
class ScreenManager
{
  public:
    static void init(std::shared_ptr<TFT_eSPI> display);
    static void setCurrentScreen(Screen *newScreen, bool setPrevious = true);
    static void setToPreviousScreen();
    static Screen *getCurrentScreen();
    static void render();

  private:
    static std::shared_ptr<TFT_eSPI> _display;
    static Screen *_currentScreen;
};
} // namespace Interface
