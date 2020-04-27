
//Class Definition File for the base Tower

#pragma once


#include "Projectile.h"

#include <SFML/Graphics.hpp>


class Tower
{
protected:
    sf::Vector2f position;

    double range; //Pixels

    int attSpeed; //Shots per minute
    int coolDownTime; //In seconds
    int damage;

    bool activeStatus = true;
    sf::Clock clock;
    sf::Time lastFireTime = clock.getElapsedTime();

    void update_status(void)
    {
        if ((clock.getElapsedTime() - lastFireTime).asSeconds() < coolDownTime)
            activeStatus = false;
        else
            activeStatus = true;
    }

public:

    Tower(void) {}

    Tower(sf::Vector2f initPosition)
    {
        position = initPosition;

        coolDownTime = 60 / attSpeed;
    }
    
    Tower();

    double get_range(void)
        { return range; }

    int get_attack_speed(void)
        { return attSpeed; }

    void fire(void)
        { lastFireTime = clock.getElapsedTime(); }

    sf::Vector2f getPosition()
        { return position; }

    int getDamage(void)
        { return damage; } 

    sf::Vector2f get_position(void)
        { return position; }

    bool is_active(void)
    {
        update_status();
        return activeStatus;
    }
};

