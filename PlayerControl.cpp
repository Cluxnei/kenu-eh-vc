#include "PlayerControl.h"

void Control::setMoveKeys(const sf::Keyboard::Key up, const sf::Keyboard::Key down, const sf::Keyboard::Key left, const sf::Keyboard::Key right)
{
	this->moveUpKey = up;
	this->moveDownKey = down;
	this->moveLeftKey = left;
	this->moveRightKey = right;
}

void Control::setMovementFactor(const float x, const float y)
{
	this->movementXFactor = x;
	this->movementYFactor = y;
}

void Control::setMovementLimits(const float minX, const float maxX, const float minY, const float maxY)
{
	this->movementLimits = std::make_pair(std::make_pair(minX, maxX), std::make_pair(minY, maxY));
}

sf::Vector2f Control::getMovementResultVector()
{
	this->bindMoveKeys();
	sf::Vector2f vector(0.f, 0.f);
	if (this->moveUp)
		vector.y -= this->movementYFactor;
	if (this->moveDown)
		vector.y += this->movementYFactor;
	if (this->moveLeft)
		vector.x -= this->movementXFactor;
	if (this->moveRight)
		vector.x += this->movementXFactor;
	return vector;
}

bool Control::inMovementArea(const sf::Vector2f position, const sf::Vector2f size)
{
	return position.x >= this->movementLimits.first.first
		&& position.x + size.x <= this->movementLimits.first.second
		&& position.y >= this->movementLimits.second.second
		&& position.y + size.y <= this->movementLimits.second.first;
}

void Control::bindMoveKeys() {
	this->moveUp = sf::Keyboard::isKeyPressed(this->moveUpKey);
	this->moveDown = sf::Keyboard::isKeyPressed(this->moveDownKey);
	this->moveLeft = sf::Keyboard::isKeyPressed(this->moveLeftKey);
	this->moveRight = sf::Keyboard::isKeyPressed(this->moveRightKey);
}