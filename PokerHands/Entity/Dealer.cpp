#include "Entity/Dealer.hpp"

Dealer::Dealer(const Window* window)
{
	//EMPTY BODY
}

void Dealer::update()
{
	//
}

void Dealer::draw(Window* window) const
{
	for (int i = 0; i < 5; i++)
	{
		window->draw(cartSprite[i]);
	}
}
