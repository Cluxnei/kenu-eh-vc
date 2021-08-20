#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include "Game.h"
#include "Player.h"

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "kenu é vc");
    // window.setPosition(sf::Vector2i(1200, 900));
    Game game(&window);
    const float playerSize = static_cast<float>(game.getMap()->getUnitSize());
    Player* player = new Player(game.getSafePosition(), sf::Vector2f(playerSize, playerSize));

    game.addPlayer(player);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        game.update();
        game.render();
    }

    return 0;
}