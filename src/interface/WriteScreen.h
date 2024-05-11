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
    WriteScreen(ButtonInterfaceBase *button);
    void start();
    void stop();
    void run();
    void render();

  private:
    ButtonInterfaceBase *_button;
    bool _isRunning;
    bool _stopping = false;
    int clicado = 0;
};
} // namespace Interface
