/*
Authors: Derek Henderson, Koji Nastuhara, Nathan Brown, Sammy West
Description: Epic tower defense game
*/

#include "PA9.h"


int main()
{
	
	std::cout << "Tower Defense!" << std::endl;

    double windowWidth = 501;
    double windowHeight = 501;
    double cellWidth = 72;
    int i = 0;
    int verticals = windowWidth / cellWidth + 1;
    int horizontals = windowHeight / cellWidth + 1;
    int vertPoints = 2 * verticals;
    int horizPoints = 2 * horizontals;
    int offset = 1;
    int midpoint = verticals * 2; 

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

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