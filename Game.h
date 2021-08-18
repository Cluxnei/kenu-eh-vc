#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"

class Game
{
public:
	/* Game constructor */
	Game(sf::RenderWindow* window);
	/* Update the game (game logic) */
	void update();
	/* Render the game entities & stuffs */
	void render();
	/* Add player to game */
	void addPlayer(Player* player);
	/* Returns safe position inside a map and without collisions with other stuffs */
	sf::Vector2f getSafePosition();
private:
	/* Render the debug data, if enabled */
	void renderDebugData();
	/* Render the grid */
	void renderGrid();
	/* Compute the window size */
	void computeWindowSize(sf::RenderWindow* window);
	/* Render the players */
	void renderPlayers();
private:

	sf::RenderWindow* window;

	unsigned int windowWidth;
	unsigned int windowHeight;
	unsigned int unitSize;

	bool debugMode;
	
	sf::Clock clock;

	Map* map;

	std::vector<Player *> players;
};

