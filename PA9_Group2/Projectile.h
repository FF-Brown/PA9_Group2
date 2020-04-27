
#pragma once

//Included SFML Libraries
#include <SFML/Graphics.hpp>

#include <cmath>

#define SPEED 5


class Projectile
{
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    double maxDistance;
    double distance;
    bool active;

public:

    Projectile(sf::Vector2f startPoint, sf::Vector2f endPoint);

    bool is_active(void) { return active; }

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

double calculate_distance(sf::Vector2f a, sf::Vector2f b); 