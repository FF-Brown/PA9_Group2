/*
Authors: Derek Henderson, Koji Nastuhara, Nathan Brown, Sammy West
Description: Epic tower defense game
*/

#include "PA9.h"
#include "Board.h"


int main()
{
    double windowWidth = 500, windowHeight = 500, cellSize = 50;
    double gridWidth = 215, gridHeight = 470;
	
	std::cout << "Tower Defense!" << std::endl;

    //Circle test code
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //Drawing grid 
    sf::RectangleShape* squareGrid = createGrid(gridWidth, gridHeight, cellSize);
    int numSquares = ((int)(gridWidth / cellSize) * (int)(gridHeight / cellSize));

    while (window.isOpen())
    {
        //Close window
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Redraw 
        window.clear();
        for (int i = 0; i < numSquares; i++) {
            window.draw(squareGrid[i]);
        }
        window.draw(shape);
        window.display();
    }

	return 0;
}