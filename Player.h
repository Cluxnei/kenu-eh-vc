#pragma once
#include "SFML/Graphics.hpp"

class Player
{
public:
	Player(sf::Vector2f position, sf::Vector2f size);
private:

public:
	sf::RectangleShape shape;
};

