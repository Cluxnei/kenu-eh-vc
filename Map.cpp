#include "Map.h"
#include "SFML/Graphics.hpp"
#include <cmath>
#include <cstdlib>

Map::Map(unsigned int unitSize, unsigned int width, unsigned int height)
{
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
	this->squareSize = this->squareCount * unitSize;
	sf::Vector2f gridCellSize(
		static_cast<float>(unitSize),
		static_cast<float>(unitSize)
	);

	float leftToCenter = width / 2 - this->squareSize / 2;
	float topToCenter = height / 2 - this->squareSize / 2;

	float gridCellOutline = 1.f;
	this->grid = new sf::RectangleShape*[this->squareCount];
	for (int i = 0; i < this->squareCount; i++) {
		this->grid[i] = new sf::RectangleShape[this->squareCount];
		for (int j = 0; j < this->squareCount; j++) {
			this->grid[i][j] = sf::RectangleShape();
			this->grid[i][j].setSize(gridCellSize);
			this->grid[i][j].setFillColor(sf::Color::Transparent);
			this->grid[i][j].setOutlineColor(sf::Color::White);
			this->grid[i][j].setOutlineThickness(gridCellOutline);
			this->grid[i][j].setPosition(
				i * gridCellSize.x + gridCellOutline + leftToCenter,
				j * gridCellSize.y + gridCellOutline + topToCenter
			);
		}
	}


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