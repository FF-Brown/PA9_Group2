#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Tower.h"
using namespace std;
//class for game board with grid, display options, enemy marching path, rules for acceptable builds (can't build on the same square 2x, etc)
#define GRID_WIDTH 500
#define GRID_HEIGHT 500
#define CELL_SIZE 25

sf::RectangleShape* createGrid(double width, double height, double cellSize);

class Board
{
public:
	Board();
	~Board();

	//Draws grid on board. Must be used BEFORE any other calls of window.draw()
	//or it will hide other objects
	void displayBoard(sf::RenderWindow& window);
	//Draws path on board in red. Marks player castle yellow
	void markPath();
	//Can be used with other files for different paths
	//Any csv file used must have all values on a single line and end with a comma
	//See path.csv for reference
	void readPath(string fileName);
	//Determines if a square is in the enemy marching path
	//Can be used for checking if a square is a valid location for a tower
	bool inPath(int square);
	int getSquareCoord(double x, double y);
	void colorCell(int cellNum);

private:
	//Note that grid is a 1D array, not 2D which would be preferrable 
	sf::RectangleShape* grid;
	double gridWidth, gridHeight, cellSize;
	int squareCount, columns, rows;
	int* path;
	int pathLength;
	Tower* towers;
};

/*
Snippet for main to test with
	    Board board;
    board.markPath();
    board.displayBoard(window);
    window.display();

    system("pause");
*/
