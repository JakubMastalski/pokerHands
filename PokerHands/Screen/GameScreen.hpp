#include <Screen/BaseScreen.hpp>
#include <Screen/MenuScreen.hpp>

#include "Entity/Player.hpp"
#include "Entity/Dealer.hpp"

#include "Manager/ScreenManager.hpp"

#include <iostream>
#include <unordered_map>
#include <unordered_set>


class GameScreen final : public BaseScreen
{
public:
    explicit GameScreen(Window* window);

public:
    void handleEvents() override;
    void update() override;
    void render() override;

public:
    void setChosenNumber(int chosenNumber);
    void initPlayer();

private:
    void addCard_Dealer();
    void game_restart();

private:
    std::vector<std::unique_ptr<Player>> playersVector;
    std::vector<std::unique_ptr<Dealer>> dealerVector;

    std::unordered_map<Suit, std::unordered_set<Rank>> cardControlMap;

private:  
    sf::Sprite backgroundImage;
    sf::Texture backgroundTexture;

private:
    int m_chosenNumber = 0;
    int m_roundeCounter = 1;

    bool changePlayerNumber = false;

};