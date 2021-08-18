#include "Map.h"
#include "SFML/Graphics.hpp"
#include <cmath>
#include <cstdlib>

Map::Map(unsigned int unitSize, unsigned int width, unsigned int height)
{
	this->computeSquareCount(unitSize, width, height);
	this->computeSquareSize(unitSize);
	this->computeGridRectangleShapes(unitSize, width, height);
	
}

void Map::computeGridRectangleShapes(unsigned int unitSize, unsigned int width, unsigned int height) {
	const float size = static_cast<float>(unitSize);
	const float leftToCenter = width / 2 - this->squareSize / 2;
	const float topToCenter = height / 2 - this->squareSize / 2;
	const float gridCellOutline = 1.f;
	const sf::Vector2f gridCellSize(size, size);

	this->grid = new sf::RectangleShape * [this->squareCount];

	for (int i = 0; i < this->squareCount; i++) {
		this->grid[i] = new sf::RectangleShape[this->squareCount];
		for (int j = 0; j < this->squareCount; j++) {
			const float x = i * gridCellSize.x + gridCellOutline + leftToCenter;
			const float y = j * gridCellSize.y + gridCellOutline + topToCenter;
			this->grid[i][j] = sf::RectangleShape(gridCellSize);
			this->grid[i][j].setFillColor(sf::Color::Transparent);
			this->grid[i][j].setOutlineColor(sf::Color::White);
			this->grid[i][j].setOutlineThickness(gridCellOutline);
			this->grid[i][j].setPosition(x, y);
		}
	}
}

void Map::computeSquareCount(unsigned int unitSize, unsigned int width, unsigned int height) {
	unsigned int horizontalUnitsCount = floor(
		static_cast<float>(width) / static_cast<float>(unitSize)
	) - 1;
	unsigned int verticalUnitsCount = floor(
		static_cast<float>(height) / static_cast<float>(unitSize)
	) - 1;

	this->squareCount = horizontalUnitsCount;
	if (horizontalUnitsCount > verticalUnitsCount) {
		this->squareCount = verticalUnitsCount;
	}
}

void Map::computeSquareSize(unsigned int unitSize) {
	this->squareSize = this->squareCount * unitSize;
}

unsigned int Map::getSquareSize() {
	return this->squareSize;
}

unsigned int Map::getSquareCount() {
	return this->squareCount;
}

sf::RectangleShape** Map::getGrid() {
	return this->grid;
}