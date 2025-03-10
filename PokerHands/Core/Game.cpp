#include "Core/Game.hpp"

#include "Screen/GameScreen.hpp"
#include "Screen/MenuScreen.hpp"

Game::Game()
{
    auto* mainWindow = new Window();
    // mainWindow->create();

    m_screen = std::make_unique< MenuScreen >( mainWindow );

    auto* additionalWindow = new Window({ 800, 600 }, "Menu Screen");
    additionalWindow->create();

    m_screen = std::make_unique< MenuScreen >(additionalWindow);
}

void Game::run()
{
    while (m_screen->isRunning())
    {
        m_screen->handleEvents();
        m_screen->update();
        m_screen->render();
    }
}

