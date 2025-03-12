#include "Screen/GameScreen.hpp"
#include <iostream>

GameScreen::GameScreen(Window* window) :BaseScreen(window)
{
	//EMPTY BODY
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

    m_window->endDraw();
}

void GameScreen::setChosenNumber(int chosenNumber)
{
	m_chosenNumber = chosenNumber;
}
