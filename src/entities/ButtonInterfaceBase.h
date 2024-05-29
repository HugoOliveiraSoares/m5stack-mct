#pragma once

#define DEBOUNCE_MS 10

namespace Entities
{
class ButtonInterfaceBase
{
  public:
    virtual void begin() = 0;
    virtual void loop() = 0;
    virtual bool isClickNext() = 0;
    virtual bool isClickPrevious() = 0;
    virtual bool isClickSelect() = 0;
};

} // namespace Entities
