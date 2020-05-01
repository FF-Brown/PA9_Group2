#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Towers.h"
//class for game board with grid, display options, enemy marching path, rules for acceptable builds (can't build on the same square 2x, etc)
#define GRID_WIDTH 500
#define GRID_HEIGHT 500
#define CELL_SIZE 25
enum Direction { UP, DOWN, LEFT, RIGHT };


sf::RectangleShape* createGrid(double width, double height, double cellSize);

class Board
{
public:
	Board(); 
	~Board();

	//Draws grid on board. Must be used BEFORE any calls of window.draw()
	//or it will hide other objects
	void draw(sf::RenderWindow& window);
	//Draws path on board in red. Marks player castle yellow
	void markPath();
	//Can be used with other files for different paths
	//Any csv file used must have all values on a single line and end with a comma
	//See path.csv for reference
	void readPath(std::string fileName);
	//Determines if a square is in the enemy marching path
	//Can be used for checking if a square is a valid location for a tower
	bool inPath(int square);
	//Convert coordinates to cell # for use in other functions
	int getSquareCoord(double x, double y);
	//For testing purposes only
	void colorCell(int cellNum);
	//Checks if a given square has a tower in it
	bool isOpen(sf::Vector2f position);
	//Calls isOpen() and inPath(). If both check out, adds a tower in the given position
	bool addTower(sf::Vector2f position, TowerType nTowerType);
	Tower* getTowers() { return towers; }
	int getTowerCount() { return towerCount; } 
	//Returns spawnpoint of enemies | used in Enemy constructor
	static sf::Vector2f getStartingPosition(void); 
	Direction getDirection(sf::Vector2f position);
	void createSpriteGrid(double width, double height, double cellSize);
	void drawTextures();

    //Checks if the position is inside the castle square
    bool isAtEnd(sf::Vector2f position);

protected:
	//Note that grid is a 1D array, not 2D which would be preferrable 
	sf::RectangleShape* grid;
	sf::Sprite* spriteGrid;
	sf::Texture texture;
	sf::Texture dirt;
	sf::Texture grass;
	sf::Texture castle;
	sf::Texture rapidTower;
	sf::Texture tower;
	sf::Texture sniperTower;

	double gridWidth, gridHeight, cellSize;
	int squareCount, columns, rows;
	int* path;
	int pathLength;
	Tower towers[400];
	int towerCount;
};

/*
Snippet for main to test with
	Board board;
	board.markPath();
	board.draw(window);
	window.display();
*/
