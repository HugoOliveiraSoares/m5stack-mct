#pragma once

#include "../entities/ButtonInterfaceBase.h"
#include "Screen.h"

using namespace Entities;

namespace Interface
{
class WriteScreen : public Screen
{
  public:
    WriteScreen();
    WriteScreen(std::shared_ptr<TFT_eSPI> display, ButtonInterfaceBase *button);
    void start();
    void stop();
    void run();
    void render();
    void nextButtonPressed();
    void previousButtonPressed();
    void selectButtonPressed();
    void backButtonPressed();

  private:
    ButtonInterfaceBase *_button;
    bool _isRunning = false;
    bool _stopping = false;
    int clicado = 0;
};
} // namespace Interface
