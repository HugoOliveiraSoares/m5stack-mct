#pragma once

#define DEBOUNCE_MS 10

namespace Entities
{
class ButtonInterfaceBase
{
  public:
    virtual void begin();
    virtual void loop();
    virtual bool isPressed();
    virtual bool isReleased();
};

} // namespace Entities
