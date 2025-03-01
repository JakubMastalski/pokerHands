#include "Game.hpp"

Game::Game() : m_window(sf::Vector2u(1000,800), "Poker Hands")
{
    m_rectangleShape.setSize((sf::Vector2f(300.f, 150.f)));
    m_rectangleShape.setFillColor(sf::Color::Red);
}

void Game::run()
{
    while (m_window.isRunning())
    {
        m_window.handleEvents();
        m_window.beginDraw(sf::Color::Blue);
        m_window.draw(m_rectangleShape);
        m_window.endDraw();
    }
}
