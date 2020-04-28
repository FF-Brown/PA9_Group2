
//Class Definition File for Towers

#pragma once

#include "Tower.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>


class Turret : public Tower
{
private:
    

public:
    Turret(sf::Vector2f initPosition = { 0, 0 }) : Tower(initPosition)
    {
        name = "Turret";
        type = TURRET;
        price = 50;
    }
};


class BombTower : public Tower
{

};

class PoisonTower : public Tower
{

};
