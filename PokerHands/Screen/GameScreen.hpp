#include <Screen/BaseScreen.hpp>
#include <Screen/MenuScreen.hpp>

#include "Player/Player.hpp"

class GameScreen final : public BaseScreen
{
public:
    explicit GameScreen(Window* window);

public:
    void handleEvents() override;
    void update() override;
    void render() override;

    void initPlayer();

public:
    void setChosenNumber(int chosenNumber);

private:
    std::vector<std::unique_ptr<Player>> playersVector;

    sf::Sprite backgroundImage;
    sf::Texture backgroundTexture;

    int m_chosenNumber = 0;
};