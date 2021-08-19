#include "Player.h"
#include "Constants.h"

Player::Player(sf::Vector2f position, sf::Vector2f size) {
	this->shape.setSize(size);
	this->shape.setPosition(position);
	this->shape.setFillColor(sf::Color::Red);
}

