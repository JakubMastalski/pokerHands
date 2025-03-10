#pragma once

#include "Screen/BaseScreen.hpp"

class Game
{
public:
    Game();
    void run();

private:
    std::unique_ptr< BaseScreen >  m_screen;
};
