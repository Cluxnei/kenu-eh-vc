#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"
#include "Map.h"
#include "Constants.h"

Game::Game(sf::RenderWindow* window)
{
    this->debugMode = true;
    this->window = window;
    this->computeWindowSize(this->window);
    this->clock.restart();
    this->map = new Map(this->windowWidth, this->windowHeight);
}

void Game::addPlayer(Player* player) 
{
    this->players.push_back(player);
}

sf::Vector2f Game::getSafePosition()
{
    unsigned int generateRandomPositionAttempts = 0;
    sf::Vector2f randomMapPosition(0.f, 0.f);
    while (generateRandomPositionAttempts < Constants::_RANDOM_POSITION_GENERATION_MAX_ATTEMPS) {
        randomMapPosition = this->map->getRandomPosition();
        if (true) { // TODO - check collisitons to generate safe position
            break;
        }
        generateRandomPositionAttempts++;
    }
    return randomMapPosition;
}

Map* Game::getMap()
{
    return this->map;
}

void Game::computeWindowSize(sf::RenderWindow* window) 
{
    const sf::Vector2u size = window->getSize();
    this->windowWidth = size.x;
    this->windowHeight = size.y;
}

void Game::update() 
{

}

void Game::render() 
{
    this->window->clear(sf::Color::Black);
    if (this->debugMode) {
        this->renderDebugData();
    }
    this->renderPlayers();
    this->window->display();
}

void Game::renderDebugData() 
{
    this->renderGrid();
}

void Game::renderGrid() 
{
    const unsigned int gridCellCount = this->map->getSquareCount();
    sf::RectangleShape** grid = this->map->getGrid();
    for (unsigned int i = 0; i < gridCellCount; i++) {
        for (unsigned int j = 0; j < gridCellCount; j++) {
            this->window->draw(grid[i][j]);
        }
    }
}

void Game::renderPlayers() 
{
    for (const auto& player : this->players) {
        this->window->draw(player->shape);
    }
}