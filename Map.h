#pragma once
#include "SFML/Graphics.hpp"

class Map
{
public:
	Map(unsigned int unitSize, unsigned int width, unsigned int height);
	unsigned int getSquareSize();
	unsigned int getSquareCount();
	sf::RectangleShape** getGrid();
private:
	void computeSquareCount(unsigned int unitSize, unsigned int width, unsigned int height);
	void computeSquareSize(unsigned int unitSize);
	void computeGridRectangleShapes(unsigned int unitSize, unsigned int width, unsigned int height);
public:

private:
	sf::RectangleShape** grid;
	unsigned int squareSize;
	unsigned int squareCount;
};

