
#pragma once

//Included SFML Libraries
#include <SFML/Graphics.hpp>

#include <cmath>


class Projectile
{
private:
    sf::Vector2f initialPos;
    sf::Vector2f currentPos;
    sf::Vector2f velocity;
    double maxDistance;
    bool active;

public:

    Projectile(sf::Vector2f startPoint, sf::Vector2f endPoint)
    {
        initialPos = startPoint;
        currentPos = endPoint;

        //velocity is direction toward endPos scaled by speed

        maxDistance = calculate_distance(startPoint, endPoint);

        active = true;
    }

    bool is_active(void)
    {
        return active;
    }

    void move(void)
    {
        //Move

        if (calculate_distance(initialPos, currentPos) > maxDistance)
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
