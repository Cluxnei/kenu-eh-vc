#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include "Game.h"
#include "Player.h"

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(1500, 850), "kenu é vc");
    window.setPosition(sf::Vector2i(1200, 900));
    Game game(&window);

    Player* player = new Player(game.getSafePosition());

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