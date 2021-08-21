#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include "Game.h"
#include "Player.h"
#include "Control.h"
#include "Constants.h"

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    
    sf::RenderWindow window(sf::VideoMode(Constants::_WIDTH, Constants::_HEIGHT), "kenu é vc");

    window.setPosition(sf::Vector2i(0, 0));

    sf::View view(sf::FloatRect(0.f, 0.f, Constants::_WIDTH, Constants::_HEIGHT));

    window.setView(view);

    // window.setPosition(sf::Vector2i(1200, 900));
    Game* game = new Game(&window);
    
    const float playerSize = static_cast<float>(game->getMap()->getUnitSize());

    sf::Texture playerTexture;

    if (!playerTexture.loadFromFile("player.png", sf::IntRect(0, 0, playerSize, playerSize)))
        return 1;

    Player* player = new Player(sf::Vector2f(playerSize, playerSize));

    player->setTexture(playerTexture);

    sf::Vector2f playerPosition = game->getSafePosition();

    player->setPosition(playerPosition.x, playerPosition.y);

    Control* playerControl = new Control();

    playerControl->setMoveKeys(sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D);

    playerControl->setMovementLimits(game->getMap()->getLimits());

    const float movementFactor = Constants::getMovementFactor() * playerSize;

    playerControl->setMovementFactor(movementFactor, movementFactor);

    player->setControl(playerControl);
    
    game->addPlayer(player);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();
           
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }
        game->update();
        game->render();
    }

    return 0;
}