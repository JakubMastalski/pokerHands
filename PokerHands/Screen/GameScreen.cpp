#include "Screen/GameScreen.hpp"

GameScreen::GameScreen(Window* window) : BaseScreen(window)
{
    if (!backgroundTexture.loadFromFile("res/images/5.png"))
    {
        std::cerr << "Failed to load 5.png!" << std::endl;
    }

        backgroundImage.setTexture(backgroundTexture);

        sf::Vector2u windowSize = window->getSize();

        backgroundImage.setScale(
            static_cast<float>(windowSize.x) / backgroundTexture.getSize().x,
            static_cast<float>(windowSize.y) / backgroundTexture.getSize().y
        );
}

void GameScreen::initPlayer()
{
    for (int i = 0; i < m_chosenNumber; i++) {

        std::unique_ptr<Player> player;

        while (true) {
            player = std::make_unique<Player>(m_window.get());

            Suit suit1 = player->playerDeck[0].suit;
            Rank rank1 = player->playerDeck[0].rank;

            Suit suit2 = player->playerDeck[1].suit;
            Rank rank2 = player->playerDeck[1].rank;

            if (cardControlMap[suit1].find(rank1) == cardControlMap[suit1].end() &&
                cardControlMap[suit2].find(rank2) == cardControlMap[suit2].end()) {

                cardControlMap[suit1].insert(rank1);
                cardControlMap[suit2].insert(rank2);
                break;
            }
        }

        switch (i) {
        case 0: player->setPosition(-5, 45); break;
        case 1: player->setPosition(705, 45); break;
        case 2: player->setPosition(-5, 530); break;
        case 3: player->setPosition(705, 530); break;
        default: break;
        }

        playersVector.emplace_back(std::move(player));
    }
}


void GameScreen::addCard_Dealer()
{
        std::unique_ptr<Dealer> dealer;

        while (true) {

            dealer = std::make_unique<Dealer>(m_window.get());

            Suit suit = dealer->dealerCard.suit;
            Rank rank = dealer->dealerCard.rank;

            if (cardControlMap[suit].find(rank) == cardControlMap[suit].end()) {

                cardControlMap[suit].insert(rank);
                break;
            }
        }

        dealer->setPosition(90 + 100 * m_roundeCounter, 270);

        dealerVector.emplace_back(std::move(dealer));
        m_roundeCounter++;
}

void GameScreen::handleEvents()
{
    sf::Event m_event{};

    while (m_window->getRenderer().pollEvent(m_event))
    {
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
        if (m_event.type == sf::Event::KeyPressed)
        {
            if (m_event.key.code == sf::Keyboard::Enter)
            {
                if (m_roundeCounter <= 5) addCard_Dealer();
                else
                {
                    //restart();
                }
            }
        }
    }
}

void GameScreen::update()
{
	//EMPTY BODY
}

void GameScreen::render()
{
    m_window->beginDraw();
    
    m_window->draw(backgroundImage);

   
    for (auto& playerCards : playersVector)
    {
        playerCards->draw(m_window.get());
    }

    for (auto& dealerCards : dealerVector)
    {
        dealerCards->draw(m_window.get());
    }

    m_window->endDraw();
}

void GameScreen::setChosenNumber(int chosenNumber)
{
	m_chosenNumber = chosenNumber;
}
