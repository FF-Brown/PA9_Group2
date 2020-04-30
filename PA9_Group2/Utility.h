
//Utility Functions Definitions

#pragma once

//Included SFML library
#include <SFML/Graphics.hpp>

//Included std libraries
#include <cmath>


namespace Utility
{
    //Returns the time elapsed in clock since lastTime
    sf::Time time_since(const sf::Clock& clock, const sf::Time lastTime);

    //Returns the distance between two vectors
    double calculate_distance(sf::Vector2f a, sf::Vector2f b);

    //Delays the program for n seconds
    void delay(double n);
}
