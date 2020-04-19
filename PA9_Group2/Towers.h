
//Class Definition File for Towers

#pragma once

#include "Tower.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>


class Turret : public Tower
{
private:
    int currentLevel;
    int damage;
    int attSpeed; //Or enum slow, medium, fast...

    void set_attributes(int level)
    {
        switch (currentLevel)
        {
        case 1: damage = 100;
                attSpeed = 10;
                break;
        case 2: damage = 150;
                attSpeed = 12;
                break;
        }
    }

public:
    Turret(void) : Tower()
    {
        *projectileType = Bullet();
        currentLevel = 1;
        set_attributes(1);
    }

    bool upgrade(void)
    {
        if (currentLevel == 3) //Max level
            return false;
        else
        {
            currentLevel++;
            set_attributes(currentLevel);
            return true;
        }
    }
};


class BombTower : public Tower
{

};

class PoisonTower : public Tower
{

};
