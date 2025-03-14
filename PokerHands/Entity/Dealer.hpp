#pragma once

#include "Entity/Player.hpp"

#include <iostream>

class Dealer
{
public:
    explicit Dealer(const Window* window);

public:
    void update();
    void draw(Window* window) const;

public:
    void setSprite();
    void setPosition(int posX, int posY);

public:
    sf::Texture cartTexture;
    sf::Sprite cartSprite;

public:
    Cart dealerCard;

};
