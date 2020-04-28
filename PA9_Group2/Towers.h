
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
        attSpeed = 90; //1.5 shots/second
        set_cool_down();
        damage = 25;
    }
};


class Sniper : public Tower
{
public:
    Sniper(sf::Vector2f initPosition = { 0, 0 }) : Tower(initPosition)
    {
        name = "Sniper";
        type = SNIPER;
        attSpeed = 30; //0.5 shots/second
        damage = 60;
    }
};


class BombTower : public Tower
{

};

class PoisonTower : public Tower
{

};
