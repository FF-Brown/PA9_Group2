
//Class Definition File for the base Tower

#pragma once


#include "Projectile.h"

#include <ctime>


class Tower
{
protected:

    
    sf::Vector2f position;

    int damage;
    double range; //Pixels

    int attSpeed; //Shots per minute
    int coolDownTime; //  = (60 / attSpeed) in constructor

    bool activeStatus = true;
    time_t lastFireTime = 0;
    void update_status(void)
    {
        if (difftime(time(nullptr), lastFireTime) < coolDownTime)
            activeStatus = false;
        else
            activeStatus = true;
    }

public:

    Tower(void) {}

    Tower(sf::Vector2f initPosition)
    {
        position = initPosition;
    }
    
    double get_range(void)
    {
        return range;
    }
    
    int get_attack_speed(void)
    {
        return attSpeed;
    }

    void fire(void)
    {
        lastFireTime = time(nullptr);
    }

    bool is_active(void)
    {
        update_status();
        return activeStatus;
    }

    sf::Vector2f get_position(void)
    {
        return position;
    }

    int get_damage(void)
    {
        return damage;
    }
};

