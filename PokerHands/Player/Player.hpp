#pragma once

#include "Screen/Window.hpp"
#include "Tools/RandomGenerator.hpp"

#include <array>

enum class Suit { Hearts = 1, Diamonds, Clubs, Spades };
enum class Rank { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

struct Cart
{
    Suit suit;
    Rank rank;
};

class Player
{
public:
    explicit Player(const Window* window);

public:
    void update();
    void draw(Window* window) const;

private:
    void setSprite();

private:
    std::array<sf::Texture, 2> cartTexture;
    std::array<sf::Sprite, 2> cartSprite;

private:
    std::array<Cart, 2> playerDeck;

private:
    int playerNumber;
};
