/*
Authors: Derek Henderson, Koji Nastuhara, Nathan Brown, Sammy West
Description: Epic tower defense game
*/

#include "PA9.h"


int main()
{
    bool exit;
    do
    {
        exit = main_menu();

        Game game;

        game.run();

        game.display_results();
    } while (!exit);
    
    //close window


    
    //Example code
    /*double windowWidth = 501;
    double windowHeight = 501;
	
	std::cout << "Tower Defense!" << std::endl;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);



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
        window.display();
    }*/

	return 0;
}