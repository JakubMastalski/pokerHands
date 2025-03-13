#include <Screen/BaseScreen.hpp>
#include <Screen/MenuScreen.hpp>

#include "Player/Player.hpp"

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
    std::vector<std::unique_ptr<Player>> playersVector;
    std::unordered_map<Suit, std::unordered_set<Rank>> cardControlMap;

private:  
    sf::Sprite backgroundImage;
    sf::Texture backgroundTexture;

    int m_chosenNumber = 0;
};