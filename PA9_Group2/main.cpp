/*
Authors: Derek Henderson, Koji Nastuhara, Nathan Brown, Sammy West
Description: Epic tower defense game
*/

#include "PA9.h"


int main()
{
	
	std::cout << "Tower Defense!" << std::endl;


    //IF THIS PRINTS OUT A GREEN CIRCLE, SFML IS WORKING
    double windowWidth = 500;
    double windowHeight = 500;
    double cellWidth = 50;
    int i = 0;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::VertexArray grid(sf::Lines, 40);

    printf("(%.1lf, %.1lf) window\n", windowWidth, windowHeight);
    cout << "Cell width: " << cellWidth << endl;
    cout << "# of vertical lines should be: " << windowWidth / cellWidth << endl;
    cout << "# of horizontal lines should be: " << windowHeight / cellWidth << endl;

    //Height is correct, number of lines is not

    for (i = 0; i < 2 * windowWidth / cellWidth; i += 2) {
            grid[i].position = sf::Vector2f(i * cellWidth / 2 + 1, 0);
            grid[i + 1].position = sf::Vector2f(i * cellWidth / 2 + 1, windowHeight);
    }

    //for (; i < 2 * windowWidth / cellWidth; i += 2) {

    //    grid[i].position = sf::Vector2f(0, i * cellWidth / 2 + 1);
    //    grid[i + 1].position = sf::Vector2f(windowWidth, i * cellWidth / 2 + 1);

    //}
    int midpoint = windowHeight / cellWidth * 2;
    cout << "Midpoint: " << midpoint << endl;

    for (int j = 0; j < 2 * windowHeight / cellWidth; j += 2) {
        grid[j + midpoint].position = sf::Vector2f(0, j * cellWidth / 2 + 1);
        grid[j + midpoint + 1].position = sf::Vector2f(windowWidth, j * cellWidth / 2 + 1);
    }


    //sf::Vertex line[] =
    //{
    //    sf::Vertex(sf::Vector2f(10.f, 0.f)),
    //    sf::Vertex(sf::Vector2f(10.f, 400.f))
    //};
    //sf::Vertex line2[] =
    //{
    //    sf::Vertex(sf::Vector2f(20.f, 0.f)),
    //    sf::Vertex(sf::Vector2f(20.f, 400.f))
    //};
    //sf::Vertex line3[] =
    //{
    //    sf::Vertex(sf::Vector2f(30.f, 0.f)),
    //    sf::Vertex(sf::Vector2f(30.f, 400.f))
    //};

    


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
        //window.draw(line, 2, sf::Lines);
        //window.draw(line2, 2, sf::Lines);
        //window.draw(line3, 2, sf::Lines);
        window.draw(grid);
        window.display();
    }

	return 0;
}