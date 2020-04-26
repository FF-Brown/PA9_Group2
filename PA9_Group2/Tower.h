
//Class Definition File for the base Tower

#pragma once


#include "Projectile.h"

#include <ctime>


class Tower
{
protected:

    
    

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
};

