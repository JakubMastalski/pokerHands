#include "Entity/Dealer.hpp"

Dealer::Dealer(const Window* window)
{
	RandomNumber randomGenerator;

	dealerCard.rank = static_cast<Rank>(randomGenerator.getNumber(1, 13));
	dealerCard.suit = static_cast<Suit>(randomGenerator.getNumber(1, 4));

	setSprite();
}

void Dealer::setSprite()
{
    const int cardWidth = 98;
    const int cardHeight = 137;

    std::unordered_map<Suit, std::string> suitToFile = {
        {Suit::Hearts, "res/cards/1.png"},
        {Suit::Diamonds, "res/cards/2.png"},
        {Suit::Clubs, "res/cards/3.png"},
        {Suit::Spades, "res/cards/4.png"}
    };

    Suit suit = dealerCard.suit;
    Rank rank = dealerCard.rank;

    std::string filePath = suitToFile[suit];

    if (!cartTexture.loadFromFile(filePath))
    {
        std::cerr << "Failed to load card texture: " << filePath << std::endl;
        return;
    }

    int textureX = (static_cast<int>(rank) - 1) * cardWidth;
    int textureY = 0;

    sf::IntRect cardRect(textureX, textureY, cardWidth, cardHeight);

    cartSprite.setTexture(cartTexture);
    cartSprite.setTextureRect(cardRect);
}

void Dealer::update()
{
	//EMPTY BODY
}

void Dealer::draw(Window* window) const
{
     window->draw(cartSprite);
}

