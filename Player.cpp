#include "Player.h"
#include "Constants.h"
#include "Control.h"

Player::Player(sf::Vector2f size) {
	this->size = size;
	this->control = new Control();
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

void Player::setTexture(sf::Texture& texture)
{
	texture.setSmooth(true);
	this->shape.setTexture(texture);
	sf::Vector2u textureSize = this->shape.getTexture()->getSize();
	this->shape.setOrigin(sf::Vector2f(textureSize.x / 2.f, textureSize.y / 2.f));
}

void Player::update()
{
	this->velocity = this->control->getMovementResultVector();
	sf::Vector2f nextPosition = this->position + this->velocity;
	bool canMove = this->control->inMovementArea(nextPosition, this->size);
	if (canMove) {
		this->setPosition(nextPosition.x, nextPosition.y);
		this->setRotation(this->control->getMovementResultRotationDegree());
	}
}

void Player::setRotation(float rotationDegree) 
{
	this->shape.setRotation(rotationDegree);
}

