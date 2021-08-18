#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Map.h"

Game::Game(sf::RenderWindow* window)
{
    this->window = window;
    sf::Vector2u size = window->getSize();
    this->windowWidth = size.x;
    this->windowHeight = size.y;
    this->clock.restart();
    this->unitSize = 40;
    this->debugMode = true;
    this->map = new Map(this->unitSize, this->windowWidth, this->windowHeight);
}

void Game::update() {

}

void Game::render() {
    this->window->clear(sf::Color::Black);
    if (this->debugMode) {
        this->renderDebugData();
    }
    this->window->display();
}

void Game::renderDebugData() {
    this->renderGrid();
}

void Game::renderGrid() {
    const unsigned int gridCellCount = this->map->getSquareCount();
    sf::RectangleShape** grid = this->map->getGrid();
    for (unsigned int i = 0; i < gridCellCount; i++) {
        for (unsigned int j = 0; j < gridCellCount; j++) {
            this->window->draw(grid[i][j]);
        }
    }
}