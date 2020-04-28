
//Class Definition File for Towers

#pragma once

#include "Tower.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>

#define SQUARE_SIZE 25


class Turret : public Tower
{
public:
    Turret(sf::Vector2f initPosition = { 0, 0 }) : Tower(initPosition)
    {
        name = "Turret";
        type  = TURRET;
        price = 50;

        range = SQUARE_SIZE * 4;
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
        type  = SNIPER;
        price = 120;

        range = SQUARE_SIZE * 10;
        attSpeed = 30; //0.5 shots/second
        set_cool_down();
        damage = 60;
    }
};

class BombTower : public Tower
{

};

class PoisonTower : public Tower
{

};
