/*
Authors: Derek Henderson, Koji Nastuhara, Nathan Brown, Sammy West
Description: Epic tower defense game
*/

#include "PA9.h"
#include "Grid.h"


int main()
{
    double windowWidth = 501;
    double windowHeight = 501;
    double cellSize = 50;
	
	std::cout << "Tower Defense!" << std::endl;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::VertexArray grid = createGrid(windowWidth, windowHeight, cellSize);

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
        window.draw(shape);
        window.draw(grid);
        window.display();
    }

	return 0;
}