#pragma once

#include "Screen/Window.cpp"
#include <SFML/Graphics.hpp>

#include <cmath>

class Game
{
public:
    Game();

public:
    void run();

private:
    Window m_window;

    sf::RectangleShape m_rectangleShape;
};