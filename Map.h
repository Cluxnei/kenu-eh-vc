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

public:

private:
	sf::RectangleShape** grid;
	unsigned int squareSize;
	unsigned int squareCount;
};

