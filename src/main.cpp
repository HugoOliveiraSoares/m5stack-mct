#include "DeviceSelect.h"
#include "entities/ButtonInterfaceBase.h"
#include "entities/DeviceBase.h"
#include "interface/Menu.h"
#include "interface/MenuItem.h"
#include "interface/ScreenManager.h"
#include "interface/WriteScreen.h"
#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>

using namespace Entities;

std::shared_ptr<TFT_eSPI> display;

DeviceBase *dev;
// Interface::ScreenManager screenManager;
Interface::Menu mainMenu;
ButtonInterfaceBase *buttonI;

void setup()
{
    dev = DeviceBase::getInstance();

    dev->begin();
    display = dev->getDisplay();
    buttonI = dev->getButton();

    mainMenu = Interface::Menu(dev->getDisplay(), dev->getButton());
    Interface::ScreenManager::init(dev->getDisplay());

    Interface::MenuItem readMenuItem("readSubMenu", "Read Tag");
    Interface::MenuItem writeMenuItem("writeSubMenu", "Write Tag");
    Interface::MenuItem emulateMenuItem("emulateSubMenu", "Emulate Tag");
    Interface::MenuItem importMenuItem("importSubMenu", "Import Tag");

    readMenuItem.setOnClick([]() { Serial.println("Botão Pressionado"); });

    writeMenuItem.setOnClick([]() {
        auto write = new Interface::WriteScreen(display, buttonI);
        Interface::ScreenManager::setCurrentScreen(write);
        write->start();
    });

    mainMenu.addItem(readMenuItem);
    mainMenu.addItem(writeMenuItem);
    mainMenu.addItem(emulateMenuItem);
    mainMenu.addItem(importMenuItem);

    Interface::ScreenManager::setCurrentScreen(&mainMenu, false);
}

void loop()
{

    dev->loop();

    if (buttonI->isClickNext())
    {
        Serial.println("next");
        Interface::ScreenManager::getCurrentScreen()->nextButtonPressed();
    }

    if (buttonI->isClickPrevious())
    {
        Serial.println("previous");
        Interface::ScreenManager::getCurrentScreen()->previousButtonPressed();
    }

    if (buttonI->isClickSelect())
    {
        Serial.println("select");
        Interface::ScreenManager::getCurrentScreen()->selectButtonPressed();
    }
}
