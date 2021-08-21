#include "Player.h"
#include "Constants.h"

Player::Player(sf::Vector2f size) {
	this->size = size;
	this->shape.setSize(this->size);
	this->shape.setFillColor(sf::Color::Red);
}

void Player::setPosition(float x, float y) {
	this->position.x = x;
	this->position.y = y;
	this->shape.setPosition(this->position);
}

void Player::setVelocity(float x, float y) {
	this->velocity.x = x;
	this->velocity.y = y;
}
void Player::setControl(Control* control)
{
	this->control = control;
}

void Player::update()
{
	this->velocity = this->control->getMovementResultVector();
	sf::Vector2f nextPosition = this->position + this->velocity;
	bool canMove = this->control->inMovementArea(nextPosition, this->size);
	if (canMove) {
		this->setPosition(nextPosition.x, nextPosition.y);
	}
}

