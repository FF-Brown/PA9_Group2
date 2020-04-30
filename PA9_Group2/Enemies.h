
//Implementation file for enemies

#pragma once

#include "Enemy.h"

class Basic : public Enemy
{
public:
    Basic(void)
    {
        shape.setRadius(8);
        shape.setFillColor(sf::Color::Blue);

        health = initHealth = 50;
        reward = 8;
        speed = 14;
    }
};

class BigBoi : public Enemy
{
public:
    BigBoi(void)
    {
        shape.setRadius(12);
        shape.setFillColor(sf::Color::Red);

        health = initHealth = 250;
        reward = 25;
        speed = 10;
    }
};

class SpeedyBoi : public Enemy
{
public:
    SpeedyBoi(void)
    {
        shape.setRadius(6);
        shape.setFillColor(sf::Color::Yellow);

        health = initHealth = 45;
        reward = 15;
        speed = 27;
    }
};


class Empty : public Enemy
{
public:
    Empty(void)
    {
        isEnemy = false;
    }
};
