#include <SFML/Graphics.hpp>
#include "Control.h"

Control::Control()
{
	this->moveUp = false;
	this->moveDown = false;
	this->moveLeft = false;
	this->moveRight = false;

	this->movementXFactor = 0.1f;
	this->movementYFactor = 0.1f;
	
	this->moveUpKey = sf::Keyboard::Key::W;
	this->moveDownKey = sf::Keyboard::Key::S;
	this->moveLeftKey = sf::Keyboard::Key::A;
	this->moveRightKey = sf::Keyboard::Key::D;

	this->movementLimits = std::make_pair(std::make_pair(0.f, 0.f), std::make_pair(0.f, 0.f));
}

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

void Control::setMovementLimits(std::pair<std::pair<float, float>, std::pair<float, float>> movementLimit)
{
	this->movementLimits = movementLimit;
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

float Control::getMovementResultRotationDegree()
{
	if (this->moveUp) {
		degrees = 0;
		if (this->moveLeft)
			degrees += -45;
		if (this->moveRight)
			degrees += 45;
	}
	if (this->moveDown) {
		degrees = 180;
		if (this->moveLeft)
			degrees += -45;
		if (this->moveRight)
			degrees += 45;
	}
	if (this->moveLeft) {
		degrees = -90;
		if (this->moveDown)
			degrees += -45;
		if (this->moveUp)
			degrees += 45;
	}
	if (this->moveRight) {
		degrees = 90;
		if (this->moveDown)
			degrees += 45;
		if (this->moveUp)
			degrees += -45;
	}
	return degrees;
}

void Control::bindMoveKeys() {
	this->moveUp = sf::Keyboard::isKeyPressed(this->moveUpKey);
	this->moveDown = sf::Keyboard::isKeyPressed(this->moveDownKey);
	this->moveLeft = sf::Keyboard::isKeyPressed(this->moveLeftKey);
	this->moveRight = sf::Keyboard::isKeyPressed(this->moveRightKey);
}