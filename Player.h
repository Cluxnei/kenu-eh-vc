#pragma once
#include "SFML/Graphics.hpp"
#include "Control.h"

class Player
{
public:
	Player(sf::Vector2f position, sf::Vector2f size);
private:
	Control control;
	sf::Vector2f position;
public:
	sf::RectangleShape shape;
};

