#include "Screen/GameScreen.hpp"
#include <iostream>

GameScreen::GameScreen(Window* window) : BaseScreen(window), m_player({ window })
{
    if (!backgroundTexture.loadFromFile("res/images/5.png"))
    {
        std::cerr << "Failed to load 5.png!" << std::endl;
    }

    backgroundImage.setTexture(backgroundTexture);

    sf::Vector2u windowSize = window->getSize();

    backgroundImage.setScale(
        static_cast<float>(windowSize.x) / backgroundTexture.getSize().x,
        static_cast<float>(windowSize.y) / backgroundTexture.getSize().y
    );
}

void GameScreen::handleEvents()
{
	BaseScreen::handleEvents();
}


void GameScreen::update()
{
	
}

void GameScreen::render()
{
    m_window->beginDraw();
    
    m_window->draw(backgroundImage);
    m_player.draw(m_window.get());

    m_window->endDraw();
}

void GameScreen::setChosenNumber(int chosenNumber)
{
	m_chosenNumber = chosenNumber;
}
