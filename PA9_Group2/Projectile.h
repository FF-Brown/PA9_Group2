
//Projectile class definition file

#pragma once

//Included project files
#include "Utility.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>


class Projectile : public sf::CircleShape
{
private:
    sf::Vector2f velocity;
    sf::Vector2f startPos;
    int maxDistance;
    int damage;
    bool active;

    //Converts a coordinate of the center of the projectile shape to its origin
    sf::Vector2f center_to_origin(sf::Vector2f centerPos)
    {
        sf::Vector2f originPos;
        originPos.x = centerPos.x - getRadius();
        originPos.y = centerPos.y - getRadius();
        return originPos;
    }

public:
    //Constructor
    Projectile(sf::Vector2f startPoint, sf::Vector2f endPoint, int initDamage, int range, int setSpeed)
    {
        startPos = startPoint;
        setPosition(center_to_origin(startPoint));
        setRadius(4);
        setFillColor(sf::Color::Black);

        //Calculate velocity
        sf::Vector2f aimDir = endPoint - startPoint;
        sf::Vector2f aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
        velocity = { aimDirNorm.x * setSpeed, aimDirNorm.y * setSpeed };

        active = true;
        maxDistance = range;
        damage = initDamage;
    }

    //Moves the enemy shape and checks if has reached the end of its range
    void move(void)
    {
        sf::CircleShape::move(velocity);
        if (Utility::calculate_distance(startPos, getPosition()) > maxDistance)
            active = false;
    }

    bool is_active(void)
        { return active; }

    int get_damage(void)
        { return damage; }
};