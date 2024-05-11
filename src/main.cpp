#include "DeviceSelect.h"
#include "entities/DeviceBase.h"
#include "interface/Menu.h"
#include "interface/MenuItem.h"
#include "interface/ScreenManager.h"
#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>

using namespace Entities;

std::shared_ptr<TFT_eSPI> display;

DeviceBase *dev;
Interface::ScreenManager screenManager;
Interface::Menu mainMenu;

void setup()
{
    dev = DeviceBase::getInstance();

    dev->begin();
    display = dev->getDisplay();

    mainMenu = Interface::Menu(dev->getDisplay(), dev->getButton());

    Interface::MenuItem readMenuItem("readSubMenu", "Read Tag");
    Interface::MenuItem writeMenuItem("writeSubMenu", "Write Tag");
    Interface::MenuItem emulateMenuItem("emulateSubMenu", "Emulate Tag");
    Interface::MenuItem importMenuItem("importSubMenu", "Import Tag");

    readMenuItem.setOnClick([]() { Serial.println("Botão Pressionado"); });

    writeMenuItem.setOnClick([]() { Serial.println("Botão Pressionado"); });

    mainMenu.addItem(readMenuItem);
    mainMenu.addItem(writeMenuItem);
    mainMenu.addItem(emulateMenuItem);
    mainMenu.addItem(importMenuItem);

    screenManager = Interface::ScreenManager(dev->getDisplay());

    screenManager.setCurrentScreen(&mainMenu, false);
}

void loop()
{
    dev->loop();

    if (dev->getButton()->isPressed())
    {
        screenManager.getCurrentScreen()->nextButtonPressed();
    }

    // if (dev->getButton()->isPressed())
    // {
    //     display->drawString("Button isPressed", 240 / 2, 135 / 2);
    // }
    // if (dev->getButton()->isReleased())
    // {
    //     display->fillScreen(TFT_BLACK);
    // }
}
