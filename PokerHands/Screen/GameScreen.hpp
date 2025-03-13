#include <Screen/BaseScreen.hpp>
#include <Screen/MenuScreen.hpp>

#include "Player/Player.hpp"

#include <iostream>
#include <unordered_set>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

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
    std::unordered_set<std::pair<Suit, Rank>, pair_hash> usedCards;

private:  
    sf::Sprite backgroundImage;
    sf::Texture backgroundTexture;

    int m_chosenNumber = 0;
};