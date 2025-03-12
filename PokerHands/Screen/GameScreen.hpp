#include <Screen/BaseScreen.hpp>
#include <Screen/MenuScreen.hpp>

class GameScreen final : public BaseScreen
{
public:
    explicit GameScreen(Window* window);

public:
    void handleEvents() override;
    void update() override;
    void render() override;

};