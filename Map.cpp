#include "Map.h"
#include "Constants.h"
#include "SFML/Graphics.hpp"
#include <cmath>

Map::Map(unsigned int width, unsigned int height)
{
	this->computeSquareCount(width, height);
	this->computeSquareSize();
	this->computeGrid(width, height);
	this->computePositionMap();
}

void Map::computeGrid(unsigned int width, unsigned int height) 
{
	const float size = static_cast<float>(this->unitSize);
	const float leftToCenter = floor((float)width / 2.f - (float)this->squareSize / 2.f);
	const float topToCenter = floor((float)height / 2.f - (float)this->squareSize / 2.f);
	const sf::Vector2f gridCellSize(size, size);

	this->grid = new sf::RectangleShape * [this->squareCount];

	for (unsigned int i = 0; i < this->squareCount; i++) {
		this->grid[i] = new sf::RectangleShape[this->squareCount];
		for (unsigned int j = 0; j < this->squareCount; j++) {
			const float x = i * gridCellSize.x + leftToCenter;
			const float y = j * gridCellSize.y + topToCenter;
			this->grid[i][j] = sf::RectangleShape(gridCellSize);
			this->grid[i][j].setFillColor(sf::Color::Transparent);
			this->grid[i][j].setOutlineColor(sf::Color::White);
			this->grid[i][j].setOutlineThickness(1.f);
			this->grid[i][j].setPosition(x, y);
		}
	}
}

void Map::computePositionMap() {
	for (unsigned int i = 0; i < this->squareCount; i++) {
		for (unsigned int j = 0; j < this->squareCount; j++) {
			const sf::Vector2f position = this->grid[i][j].getPosition();
			this->positionMap.push_back(sf::Vector2f(position.x, position.y));
		}
	}
}

void Map::computeSquareCount(unsigned int width, unsigned int height) 
{
	const float w = static_cast<float>(width);
	const float h = static_cast<float>(height);

	float u = static_cast<float>(Constants::__BASE_UNIT_SIZE);
	while (u > 1.f) {
		unsigned int horizontalUnitsCount = static_cast<unsigned int>(floor(w / u)) - 1;
		unsigned int verticalUnitsCount = static_cast<unsigned int>(floor(h / u)) - 1;
		this->squareCount = std::min(horizontalUnitsCount, verticalUnitsCount);
		if (this->squareCount >= 64) {
			this->unitSize = static_cast<unsigned int>(ceil(u));
			this->squareCount = 64;
			break;
		}
		u--;
	}

}

void Map::computeSquareSize() 
{
	this->squareSize = this->squareCount * this->unitSize;
}

unsigned int Map::getSquareSize() 
{
	return this->squareSize;
}

unsigned int Map::getSquareCount() 
{
	return this->squareCount;
}

sf::RectangleShape** Map::getGrid() 
{
	return this->grid;
}

unsigned int Map::getUnitSize()
{
	return this->unitSize;
}

sf::Vector2f Map::getRandomPosition()
{
	return this->positionMap[Constants::randomIntBetween(0, this->positionMap.size() - 1)];
}
