#pragma once
#include <SFML/Graphics.hpp>

class Control
{
private:
	sf::Keyboard::Key moveUpKey;
	sf::Keyboard::Key moveDownKey;
	sf::Keyboard::Key moveLeftKey;
	sf::Keyboard::Key moveRightKey;
	bool moveUp;
	bool moveDown;
	bool moveLeft;
	bool moveRight;
	float movementXFactor;
	float movementYFactor;
	std::pair<
		std::pair<float, float>,
		std::pair<float, float>
	> movementLimits;

private:
	void bindMoveKeys();
public:
	void setMoveKeys(const sf::Keyboard::Key up, const sf::Keyboard::Key down, const sf::Keyboard::Key left, const sf::Keyboard::Key right);
	void setMovementFactor(const float x, const float y);
	void setMovementLimits(const float minX, const float maxX, const float minY, const float maxY);
	sf::Vector2f getMovementResultVector();
	bool inMovementArea(const sf::Vector2f position, const sf::Vector2f size);
};

