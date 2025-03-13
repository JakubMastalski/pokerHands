#include "Screen/GameScreen.hpp"
#include <iostream>

GameScreen::GameScreen(Window* window) : BaseScreen(window)
{
    if (!backgroundTexture.loadFromFile("res/images/5.png"))
    {
        std::cerr << "Failed to load 5.png!" << std::endl;
    }

    for (int i = 0; i < m_chosenNumber; i++)
    {
        auto player = std::make_unique<Player>(window);
        player->setPosition(i * 50, i * 125);

        playersVector.push_back(std::move(player));
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

   
    for (auto& player : playersVector)
    {
        player->draw(m_window.get());
    }

    m_window->endDraw();
}

void GameScreen::setChosenNumber(int chosenNumber)
{
	m_chosenNumber = chosenNumber;
}
