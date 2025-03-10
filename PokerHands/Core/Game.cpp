#include "Game.hpp"

#include <cmath>

Game::Game() : m_window(sf::Vector2u(1200, 800), "Poker Hands")
{
    // Empty body.
}

void Game::run()
{
    while (!m_window.isDone())
    {
        handleEvents();
        draw();
    }
}

void Game::handleEvents()
{
    m_window.handleInput();
}

void Game::update(const float& dt)
{
    // Empty body.
}

void Game::draw()
{
    m_window.beginDraw();

    sf::RectangleShape m_rectangleShape;
    m_rectangleShape.setSize(sf::Vector2f(100.f, 50.f));
    m_rectangleShape.setFillColor(sf::Color::Red);

    m_window.draw(m_rectangleShape);

    m_window.endDraw();
}

