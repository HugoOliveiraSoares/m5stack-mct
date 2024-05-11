#pragma once

#include "../entities/ButtonInterfaceBase.h"
#include <TFT_eSPI.h>
#include <WString.h>
#include <memory>

using namespace Entities;

namespace Interface
{
class Screen
{
  public:
    Screen();
    Screen(std::shared_ptr<TFT_eSPI> display);
    virtual void render() = 0;
    Screen *getPreviousScreen();
    void setPreviousScreen(Screen *previous);
    virtual void nextButtonPressed();
    virtual void previousButtonPressed();
    virtual void selectButtonPressed();
    virtual void backButtonPressed();

  protected:
    std::shared_ptr<TFT_eSPI> _display;
    Screen *_previousScreen = nullptr;
};

} // namespace Interface
