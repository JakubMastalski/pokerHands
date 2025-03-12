#include "Manager/ScreenManager.hpp"

#include <Screen/GameScreen.hpp>
#include <Screen/MenuScreen.hpp>

#include <cassert>

static ScreenManager* s_Instance = nullptr;

void ScreenManager::Init()
{
    assert(!s_Instance);
    s_Instance = new ScreenManager();

}

void ScreenManager::ShutDown()
{
    delete s_Instance;
    s_Instance = nullptr;
}

ScreenManager& ScreenManager::GetInstance()
{
    assert(s_Instance);
    return *s_Instance;
}

ScreenManager::ScreenManager()
{
    auto* mainWindow = new Window();

    m_screens[ScreenType::MENU] = std::make_unique< MenuScreen >(mainWindow);
    m_screens[ScreenType::GAME] = std::make_unique< GameScreen >(mainWindow);

    mainWindow->create();

    m_activeScreen = m_screens[ScreenType::MENU].get();
}

void ScreenManager::setScreen(const ScreenType screenType)
{
    if (screenType == ScreenType::GAME)
    {
        auto* menuScreen = dynamic_cast<MenuScreen*>(m_screens[ScreenType::MENU].get());
        auto* gameScreen = dynamic_cast<GameScreen*>(m_screens[ScreenType::GAME].get());

        if (menuScreen && gameScreen)
        {
            gameScreen->setChosenNumber(menuScreen->getChosenNumber() + 2);
        }
    }

    m_activeScreen = m_screens[screenType].get();
}

bool ScreenManager::isRunning() const
{
    return m_activeScreen->isRunning();
}

void ScreenManager::handleEvents() const
{
    m_activeScreen->handleEvents();
}

void ScreenManager::update() const
{
    m_activeScreen->update();
}

void ScreenManager::render() const
{
    m_activeScreen->render();
}