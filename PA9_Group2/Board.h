#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
//class for game board with grid, display options, enemy marching path, rules for acceptable builds (can't build on the same square 2x, etc)


// May have to redo. Might need to be a collection of squares instead of a collection of lines
// Also this is a crap function, not gonna leave it here. Just needed somewhere to stuff it
// May make a grid class
void createGrid(double width, double height, double cellSize) {

    double windowWidth = width;
    double windowHeight = height;
    double cellWidth = cellSize;
    int i = 0;
    //Number of vertical/horizontal lines
    int verticals = windowWidth / cellWidth + 1;
    int horizontals = windowHeight / cellWidth + 1;
    //Number of vertical/horizontal points
    int vertPoints = 2 * verticals;
    int horizPoints = 2 * horizontals;
    //Shift slightly so 1st line is visible
    int offset = 1;
    int midpoint = vertPoints; //Will be replaced

    sf::VertexArray grid(sf::Lines, vertPoints + horizPoints);

    printf("(%.1lf, %.1lf) window\n", windowWidth, windowHeight);
    cout << "Cell width: " << cellWidth << endl;
    cout << "# of vertical lines should be: " << verticals << endl;
    cout << "# of horizontal lines should be: " << horizontals << endl;
    cout << "Midpoint: " << midpoint << endl;

    for (i = 0; i < vertPoints; i += 2) {
        grid[i].position = sf::Vector2f(i * cellWidth / 2 + offset, 0);
        grid[i + 1].position = sf::Vector2f(i * cellWidth / 2 + offset, windowHeight);
    }


    for (int j = 0; j < horizPoints; j += 2) {
        grid[j + midpoint].position = sf::Vector2f(0, j * cellWidth / 2 + offset);
        grid[j + midpoint + 1].position = sf::Vector2f(windowWidth, j * cellWidth / 2 + offset);
    }
}