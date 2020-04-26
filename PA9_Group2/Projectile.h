
#pragma once

//Included SFML Libraries
#include <SFML/Graphics.hpp>

#include <cmath>

#define SPEED 5

double calculate_distance(sf::Vector2f a, sf::Vector2f b);


class Projectile
{
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    double maxDistance;
    double distance;
    bool active;

public:

    Projectile(sf::Vector2f startPoint, sf::Vector2f endPoint)
    {
        shape.setPosition(startPoint);

        sf::Vector2f aimDir = endPoint - startPoint;
        sf::Vector2f aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
        velocity = { aimDirNorm.x * SPEED, aimDirNorm.y * SPEED };

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
