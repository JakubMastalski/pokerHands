#include <SFML/Graphics.hpp>
#include <iostream>

#include "Core/Game.hpp"

int main()
{
    Game game;
    game.run();

    std::cin.get();
    return 0;
}