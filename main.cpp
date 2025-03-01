#include <SFML/Graphics.hpp>
#include "Screen/Window.h"

int main()
{
    Window window(sf::Vector2u(200, 200), "Window works!");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isRunning())
    {
        window.handleEvents();
        window.beginDraw(sf::Color::Blue);
        window.draw(shape);
        window.endDraw();
    }

    return 0;
}