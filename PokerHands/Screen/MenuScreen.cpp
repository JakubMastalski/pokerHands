#include <iostream>

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

    if (!twoPlayersImage.loadFromFile("res/images/2.png"))
    {
        std::cerr << "Failed to load 2.png!" << std::endl;
    }

    if (!threePlayersImage.loadFromFile("res/images/3.png"))
    {
        std::cerr << "Failed to load 3.png!" << std::endl;
    }

    if (!fourPlayersImage.loadFromFile("res/images/4.png"))
    {
        std::cerr << "Failed to load 4.png!" << std::endl;
    }

    playersTwo.setTexture(twoPlayersImage);
    playersThree.setTexture(threePlayersImage);
    playersFour.setTexture(fourPlayersImage);

    playersTwo.setScale(0.20f, 0.20f);
    playersThree.setScale(0.18f, 0.18f);
    playersFour.setScale(0.18f, 0.18f);

    playersTwo.setPosition(125.f, 320.f);
    playersThree.setPosition(325.f, 320.f);
    playersFour.setPosition(525.f, 320.f);
}

void MenuScreen::handleEvents()
{
    while (m_window->getRenderer().pollEvent(m_event))
    {
        if (m_event.type == sf::Event::Closed)
        {
            m_window->close();
            return;
        }

        if (m_event.type == sf::Event::KeyPressed)
        {
            switch (m_event.key.code)
            {
            case sf::Keyboard::Escape:
                m_window->close();
                break;

            case sf::Keyboard::Enter:
                break;

            case sf::Keyboard::Left:
                if (number > 0) number--;
                break;

            case sf::Keyboard::Right:
                if (number < 2) number++;
                break;

            default:
                break;
            }
        }

        switch (number)
        {
        case PlayerNumber::twoPlayer:
            playersTwo.setScale(0.20f, 0.20f);
            playersThree.setScale(0.18f, 0.18f);
            playersFour.setScale(0.18f, 0.18f);
            break;

        case PlayerNumber::threePlayer:
            playersThree.setScale(0.20f, 0.20f);
            playersTwo.setScale(0.18f, 0.18f);
            playersFour.setScale(0.18f, 0.18f);
            break;

        case PlayerNumber::fourPlayer:
            playersFour.setScale(0.20f, 0.20f);
            playersTwo.setScale(0.18f, 0.18f);
            playersThree.setScale(0.18f, 0.18f);
            break;

        default:
            break;
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

    m_window->draw(playersTwo);
    m_window->draw(playersThree);
    m_window->draw(playersFour);

    m_window->endDraw();
}