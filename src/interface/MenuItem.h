#pragma once

#include <WString.h>
#include <functional>

namespace Interface
{
class MenuItem
{
  public:
    MenuItem();
    MenuItem(String id, String text);
    String getText();
    void click();
    bool isDefinedOnClick();
    void setOnClick(std::function<void()> onClick);

  private:
    String _id;
    String _text;
    std::function<void()> _onClick = nullptr;
};
} // namespace Interface
