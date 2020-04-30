
//Implementation file for towers

#pragma once

#include "Tower.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>


class Turret : public Tower
{
public:
    Turret(sf::Vector2f initPosition = { 0, 0 }) : Tower(initPosition)
    {
        name = "Turret";
        type  = TURRET;
        price = 75;

        range     = SQUARE_SIZE * 5;
        coolDownTime = 0;
        attSpeed  = 45; //0.75 shots/second
        damage    = 20;
        projSpeed = 10;

        set_cool_down();
    }
};

class Sniper : public Tower
{
public:
    Sniper(sf::Vector2f initPosition = { 0, 0 }) : Tower(initPosition)
    {
        name = "Sniper";
        type  = SNIPER;
        price = 150;

        range     = SQUARE_SIZE * 9;
        attSpeed  = 20; //0.5 shots/second
        damage    = 35;
        projSpeed = 13;

        set_cool_down();
    }
};

class Rapid : public Tower
{
public:
    Rapid(sf::Vector2f initPosition = { 0, 0 }) : Tower(initPosition)
    {
        name = "Rapid";
        type  = RAPID;
        price = 175;

        range     = SQUARE_SIZE * 5;
        attSpeed  = 180; //3 shots/second
        damage    = 1;
        projSpeed = 12;

        set_cool_down();
    }
};
