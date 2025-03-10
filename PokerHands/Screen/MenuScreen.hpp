#pragma once

#include "Screen/BaseScreen.hpp"

enum PlayerNumber
{
    twoPlayer, threePlayer, fourPlayer
};

class MenuScreen final : public BaseScreen
{
public:
    explicit MenuScreen(Window* window);

    PlayerNumber PlayerNumber;

public:
    void handleEvents() override;
    void update() override;
    void render() override;

private:
    sf::Font   m_font;
    sf::Text   m_text;
    
    sf::Text   m_select;
    sf::Font   m_selectfont;

    sf::Sprite playersTwo;
    sf::Sprite playersThree;
    sf::Sprite playersFour;

    sf::Texture twoPlayersImage;
    sf::Texture threePlayersImage;
    sf::Texture fourPlayersImage;

    int number = 0;
};