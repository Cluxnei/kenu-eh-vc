#pragma once
#include "SFML/Graphics.hpp"
#include "Control.h"

class Player
{
public:
	Player(sf::Vector2f size);

	void setPosition(float x, float y);
	void setVelocity(float x, float y);
	void setControl(Control* control);
	void setTexture(sf::Texture& texture);
	void update();

private:

	Control* control;

	sf::Vector2f size;
	sf::Vector2f position;
	sf::Vector2f velocity;

public:
	sf::Sprite shape;
};

