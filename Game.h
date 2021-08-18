#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"

class Game
{
public:
	Game(sf::RenderWindow* window);
	void update();
	void render();
	void renderDebugData();
private:
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

