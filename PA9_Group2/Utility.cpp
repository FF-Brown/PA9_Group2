
#include "Utility.h"


sf::Time Utility::time_since(const sf::Clock& clock, const sf::Time lastTime)
{
    return clock.getElapsedTime() - lastTime;
}

double Utility::calculate_distance(sf::Vector2f a, sf::Vector2f b)
{
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}
