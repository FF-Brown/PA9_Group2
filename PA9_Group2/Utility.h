
//Utility Functions

#pragma once

#include <SFML/Graphics.hpp>

#include <cmath>

namespace Utility
{
    //Returns the time elapsed since lastTime
    sf::Time time_since(const sf::Clock& clock, const sf::Time lastTime);

    //Returns the distance between two vectors
    double calculate_distance(sf::Vector2f a, sf::Vector2f b);
}
