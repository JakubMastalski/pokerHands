#include "Entity/Player.hpp"

#include <iostream>

Player::Player(const Window* window)
{
	RandomNumber randomGenerator;

	playerDeck[0].rank = static_cast<Rank>(randomGenerator.getNumber(1, 13));
	playerDeck[0].suit = static_cast<Suit>(randomGenerator.getNumber(1, 4));

	playerDeck[1].rank = static_cast<Rank>(randomGenerator.getNumber(1, 13));
	playerDeck[1].suit = static_cast<Suit>(randomGenerator.getNumber(1, 4));	

    setSprite();
}

void Player::setSprite()
{
    const int cardWidth = 98;
    const int cardHeight = 137;

    std::unordered_map<Suit, std::string> suitToFile = {
        {Suit::Hearts, "res/cards/1.png"},
        {Suit::Diamonds, "res/cards/2.png"},
        {Suit::Clubs, "res/cards/3.png"},
        {Suit::Spades, "res/cards/4.png"}
    };

    for (int i = 0; i < 2; ++i)
    {
        Suit suit = playerDeck[i].suit;
        Rank rank = playerDeck[i].rank;

        std::string filePath = suitToFile[suit];

        if (!cartTexture[i].loadFromFile(filePath))
        {
            std::cerr << "Failed to load card texture: " << filePath << std::endl;
            continue;
        }

        int textureX = (static_cast<int>(rank) - 1) * cardWidth;
        int textureY = 0; 

        sf::IntRect cardRect(textureX, textureY, cardWidth, cardHeight);

        cartSprite[i].setTexture(cartTexture[i]);
        cartSprite[i].setTextureRect(cardRect);
    }
}

void Player::setPosition(int posX , int posY)
{
     cartSprite[0].setPosition(posX, posY);
     cartSprite[1].setPosition(posX + 100, posY);
}

void Player::update()
{
    //EMPTY BODY
}

void Player::draw(Window* window) const
{
    window->draw(cartSprite[0]);
    window->draw(cartSprite[1]);
}
