#pragma once

#include "Screen/Window.hpp"
#include <SFML/Graphics.hpp>

#include <cmath>

class Game
{
public:
    Game();

    void run();

private:
    void handleEvents();
    void update(const float& dt);
    void draw();

    Window m_window;
};