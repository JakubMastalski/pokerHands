#pragma once

#include "Entity/Player.hpp"

class Dealer
{
public:
    explicit Dealer(const Window* window);

public:
    void update();
    void draw(Window* window) const;

public:
    std::array<sf::Texture, 2> cartTexture;
    std::array<sf::Sprite, 2> cartSprite;

public:
    std::array<Cart,5> dealerDeck;

};
