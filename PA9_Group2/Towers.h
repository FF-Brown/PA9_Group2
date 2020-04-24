
//Class Definition File for Towers

#pragma once

#include "Tower.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>

enum TowerType
{
    TURRET,
    NONE
};


class Turret : public Tower
{
private:
    int damage;
    int attSpeed; //Or enum slow, medium, fast...

    

public:
    Turret(void) : Tower()
    {
        
    }
};


class BombTower : public Tower
{

};

class PoisonTower : public Tower
{

};
