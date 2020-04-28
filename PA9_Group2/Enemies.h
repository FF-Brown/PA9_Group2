#pragma once

#include "Enemy.h"

class Basic : public Enemy
{
public:
    Basic(void) : Enemy()
    {
        shape.setRadius(8);
        shape.setFillColor(sf::Color::Blue);

        health = 50;
        reward = 25;
        speed  = 10;
    }
};

class BigBoi : public Enemy
{
public:
    BigBoi(void) : Enemy()
    {
        shape.setRadius(16);
        shape.setFillColor(sf::Color::Red);

        health = 200;
        reward = 150;
        speed  = 5;
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
