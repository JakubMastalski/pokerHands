#include "Screen/MenuScreen.hpp"

MenuScreen::MenuScreen(Window* window) : BaseScreen(window)
{
    m_font.loadFromFile("res/fonts/aleo/Aleo-Light.otf");
    m_selectfont.loadFromFile("res/fonts/aleo/Aleo-Light.otf");
 
    m_text.setFont(m_font);
    m_select.setFont(m_selectfont);

    m_text.setString("Welcome in Poker Hands!");
    m_select.setString("Chose Number of Players:");

    m_text.setCharacterSize(40);
    m_text.setFillColor(sf::Color::White);

    m_select.setCharacterSize(40);
    m_select.setFillColor(sf::Color::Red);

    m_text.setPosition(static_cast<float>(m_window->getSize().x * 0.5 - m_text.getGlobalBounds().width * 0.5),
        static_cast<float>(m_window->getSize().y * 0.2 - m_text.getGlobalBounds().height * 0.2));

    m_select.setPosition(static_cast<float>(m_window->getSize().x * 0.5 - m_select.getGlobalBounds().width * 0.5),
        static_cast<float>(m_window->getSize().y * 0.4 - m_select.getGlobalBounds().height * 0.4));
}

void MenuScreen::handleEvents()
{
    while (m_window->getRenderer().pollEvent(m_event))
    {
        if (m_event.type == sf::Event::KeyPressed && m_event.key.code == sf::Keyboard::Enter)
        {
            //Change screen to Game
        }
        if (m_event.type == sf::Event::Closed)
        {
            m_window->close();
        }
        if (m_event.type == sf::Event::KeyPressed)
        {
            if (m_event.key.code == sf::Keyboard::Escape)
            {
                m_window->close();
            }
        }
    }
}

void MenuScreen::update()
{
   
}

void MenuScreen::render()
{
    m_window->beginDraw();

    m_window->draw(m_text);
    m_window->draw(m_select);

    m_window->endDraw();
}