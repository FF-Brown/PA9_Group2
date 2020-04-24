
#pragma once

//Included SFML Libraries
#include <SFML/Graphics.hpp>

#include <cmath>


class Projectile
{
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    double maxDistance;
    double distance;
    bool active;

public:

    Projectile(sf::Vector2f startPoint, sf::Vector2f endPoint)
    {
        position = startPoint;

        //velocity is direction toward endPos scaled by speed

        maxDistance = calculate_distance(startPoint, endPoint);
        distance = 0;
        active = true;
    }

    bool is_active(void)
    {
        return active;
    }

    void move(void)
    {
        //Move

        //Add to distance

        if (distance > maxDistance)
            active = false;
    }

    void draw(sf::RenderWindow& window)
    {
        if (active)
        {

        }
    }
};

double calculate_distance(sf::Vector2f a, sf::Vector2f b)
{
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}
