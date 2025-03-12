#include "Core/Game.hpp"

#include "Manager/ScreenManager.hpp"

Game::Game()
{
    ScreenManager::Init();
}

Game::~Game()
{
    //ScreenManager::ShutDown();
}

void Game::run()
{
    while (ScreenManager::GetInstance().isRunning())
    {
        ScreenManager::GetInstance().handleEvents();
        ScreenManager::GetInstance().update();
        ScreenManager::GetInstance().render();
    }
}

