#pragma once
#include "SFML/Graphics.hpp"
// #include <vector>

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
	void computeGrid(unsigned int unitSize, unsigned int width, unsigned int height);
public:

private:
	sf::RectangleShape** grid;
	unsigned int squareSize;
	unsigned int squareCount;
	// std::vector<sf::Vector2f> positionMap;
};

