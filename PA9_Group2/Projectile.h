
#pragma once

#include "Utility.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>


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
    Projectile(sf::Vector2f startPoint, sf::Vector2f endPoint)
    {
        shape.setPosition(startPoint);
        shape.setRadius(3);
        shape.setFillColor(sf::Color::Black);

        sf::Vector2f aimDir = endPoint - startPoint;
        sf::Vector2f aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
        velocity = { aimDirNorm.x * SPEED, aimDirNorm.y * SPEED };

        maxDistance = Utility::calculate_distance(startPoint, endPoint);
        distance = 0;
        active = true;
    }

    bool is_active(void)
        { return active; }

    void update_active_status(void)
    {
        if (distance > maxDistance)
            active = false;
        else
            active = true;
    }

    void move(void)
    {
        //Move

        //Add move length to distance

        update_active_status();
    }

    void draw(sf::RenderWindow& window)
    {
        if (active)
        {

        }
    }
};