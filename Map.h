#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class Map
{
public:
	/* Constructor of map */
	Map(unsigned int unitSize, unsigned int width, unsigned int height);
	/* Getters */
	unsigned int getSquareSize();
	unsigned int getSquareCount();
	sf::RectangleShape** getGrid();

private:
	/* Calculates the maximum number of squares to fit the screen */
	void computeSquareCount(unsigned int unitSize, unsigned int width, unsigned int height);
	/*
		Calculates the width based on the number of 
		squares to fit the screen * the square unit size
	*/
	void computeSquareSize(unsigned int unitSize);
	/*
		Creates a matrix in center of screen with all
		the rectangles that fit into the largest
		possible square on the screen
	*/
	void computeGrid(unsigned int unitSize, unsigned int width, unsigned int height);
	/* Save all the positions of map (grid) in a vector (positionMap) */
	void computePositionMap();
public:

private:

	sf::RectangleShape** grid;
	
	unsigned int squareSize;
	unsigned int squareCount;
	
	std::vector<sf::Vector2f> positionMap;
};

