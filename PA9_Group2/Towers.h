
//Implementation file for towers

#pragma once

#include "Tower.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>

//Basic tower
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
        damage    = 18;
        projSpeed = 10;

        set_cool_down();
    }
};

//Long range tower with large damage and slow speed
class Sniper : public Tower
{
public:
    Sniper(sf::Vector2f initPosition = { 0, 0 }) : Tower(initPosition)
    {
        name = "Sniper";
        type  = SNIPER;
        price = 150;

        range     = SQUARE_SIZE * 9;
        attSpeed  = 30; //0.5 shots/second
        damage    = 35;
        projSpeed = 13;

        set_cool_down();
    }
};

//Rapid firing tower with low damage per shot
class Rapid : public Tower
{
public:
    Rapid(sf::Vector2f initPosition = { 0, 0 }) : Tower(initPosition)
    {
        name = "Rapid";
        type  = RAPID;
        price = 175;

        range     = SQUARE_SIZE * 5;
        attSpeed  = 240; //4 shots/second
        damage    = 2;
        projSpeed = 12;

        set_cool_down();
    }
};
