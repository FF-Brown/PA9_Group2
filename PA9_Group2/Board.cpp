
#include "Board.h"


sf::RectangleShape* createGrid(double width, double height, double cellSize) {

    //Number of squares across and down
    int x = width / cellSize, y = height / cellSize, total = x * y;

    double xCoord = 0, yCoord = 0;

    sf::RectangleShape* squareGrid = new sf::RectangleShape [total];

    for (int m = 0; m < total; m++, xCoord += cellSize) {
        squareGrid[m].setSize(sf::Vector2f(cellSize, cellSize));
        squareGrid[m].setFillColor(sf::Color::Black);
        squareGrid[m].setOutlineThickness(2);
        squareGrid[m].setOutlineColor(sf::Color::White);
        if (m % x == 0 && m != 0) {
            xCoord = 0;
            yCoord += cellSize;
        }
        squareGrid[m].setPosition(sf::Vector2f(xCoord, yCoord));
    }

    return squareGrid;
}
