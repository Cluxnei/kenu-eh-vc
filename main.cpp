#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 850), "kenu é vc"/*, sf::Style::Fullscreen*/);
    window.setPosition(sf::Vector2i(1200, 900));
    Game game(&window);

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