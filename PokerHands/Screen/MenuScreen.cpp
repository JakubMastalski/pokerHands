#include "Screen/MenuScreen.hpp"

MenuScreen::MenuScreen(Window* window) : BaseScreen(window)
{
    m_font.loadFromFile("res/fonts/aleo/Aleo-Light.otf");
    m_text.setFont(m_font);
    m_text.setString("Welcome in Poker Hands! , Select Player Number:");
    m_text.setCharacterSize(64);
    m_text.setFillColor(sf::Color::White);
    m_text.setPosition(static_cast<float>(m_window->getSize().x * 0.5 - m_text.getGlobalBounds().width * 0.5),
        static_cast<float>(m_window->getSize().y * 0.5 - m_text.getGlobalBounds().height * 0.5));
}

void MenuScreen::handleEvents()
{
    while (m_window->getRenderer().pollEvent(m_event))
    {
        if (m_event.type == sf::Event::KeyPressed && m_event.key.code == sf::Keyboard::Enter)
        {
            //Change screen to Game
        }
    }
}

void MenuScreen::update(const float dt)
{
   
}

void MenuScreen::render()
{
    m_window->beginDraw();

    m_window->draw(m_text);
    m_window->endDraw();
}