#include "Player.h"
#include "Constants.h"

Player::Player(sf::Vector2f position) {
	this->shape.setSize(sf::Vector2f(Constants::_UNIT_SIZE, Constants::_UNIT_SIZE));
	this->shape.setPosition(position);
	this->shape.setFillColor(sf::Color::Red);
}

