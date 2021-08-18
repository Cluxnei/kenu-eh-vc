#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"

class Game
{
public:
	/* Game constructor */
	Game(sf::RenderWindow* window);
	/* Update the game (game logic) */
	void update();
	/* Render the game entities & stuffs */
	void render();
private:
	/* Render the debug data, if enabled */
	void renderDebugData();
	/* Render the grid */
	void renderGrid();
private:

	sf::RenderWindow* window;

	unsigned int windowWidth;
	unsigned int windowHeight;
	unsigned int unitSize;

	bool debugMode;
	
	sf::Clock clock;

	Map* map;
};

