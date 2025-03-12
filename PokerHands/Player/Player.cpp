#include "Player/Player.hpp"
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
    const int cardWidth = 100;
    const int cardHeight = 146;

    const std::string basePath = "res/cards/cards.png";

    if (!cartTexture[0].loadFromFile(basePath)) {
        std::cerr << "Failed to load cards.png!" << basePath << std::endl;
        return;
    }

    for (int i = 0; i < 2; ++i)
    {
        Suit suit = playerDeck[i].suit;
        Rank rank = playerDeck[i].rank;

        int suitIndex = static_cast<int>(suit);
        int rankIndex = static_cast<int>(rank) - 1; 

        int textureX = rankIndex * cardWidth;  
        int textureY = suitIndex * cardHeight; 

        sf::IntRect cardRect(textureX, textureY, cardWidth, cardHeight);

        // Ustawienie sprite'a
        cartSprite[i].setTexture(cartTexture[0]);
        cartSprite[i].setTextureRect(cardRect);
        cartSprite[i].setPosition(100 + i * 150, 200);
    }
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
