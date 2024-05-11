#pragma once

#include "MenuItem.h"
#include "Screen.h"
#include <vector>

namespace Interface
{
class Menu : public Screen
{
  public:
    Menu();
    Menu(std::shared_ptr<TFT_eSPI> display, ButtonInterfaceBase *button);
    void addItem(MenuItem item);
    void nextItem();
    void previousItem();
    void selectItem();
    void render();
    void nextButtonPressed();
    void previousButtonPressed();
    void selectButtonPressed();

  private:
    ButtonInterfaceBase *_button;
    int cursor = 0;
    std::vector<MenuItem> _items = std::vector<MenuItem>();
};
} // namespace Interface
