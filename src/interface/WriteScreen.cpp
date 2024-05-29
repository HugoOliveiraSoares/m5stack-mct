#include "WriteScreen.h"
#include "ScreenManager.h"

using namespace Interface;

WriteScreen::WriteScreen(std::shared_ptr<TFT_eSPI> display, ButtonInterfaceBase *button)
{
    this->_button = button;
    this->_display = display;
}

void WriteScreen::stop()
{
    if (this->_isRunning)
        this->_stopping = true;

    while (this->_stopping || this->_isRunning)
    {
        delay(100);
    }
}

void WriteScreen::run()
{
    this->_isRunning = true;
    this->_stopping = false;

    while (true)
    {
        this->render();

        if (this->_stopping)
            break;

        delay(100);
    }

    this->_isRunning = false;
    this->_stopping = false;
}

void WriteScreen::start()
{
    if (this->_isRunning)
        return;

    xTaskCreatePinnedToCore(
        [](void *param) {
            auto screen = static_cast<WriteScreen *>(param);
            screen->run();
            vTaskDelete(nullptr);
        },
        "WriteTag_Run", configMINIMAL_STACK_SIZE + 2048, this, 1, nullptr, portNUM_PROCESSORS - 1);
}

void WriteScreen::render()
{
    this->_display->fillScreen(TFT_BLACK);
    this->_display->setCursor(10, this->_display->height() / 2);
    this->_display->printf("W was pressed %d times\n", this->clicado);
}

void WriteScreen::nextButtonPressed()
{
}

void WriteScreen::previousButtonPressed()
{
    this->stop();
    Interface::ScreenManager::setToPreviousScreen();
}
void WriteScreen::selectButtonPressed()
{
    this->clicado++;
}
void WriteScreen::backButtonPressed()
{
    this->stop();
}
