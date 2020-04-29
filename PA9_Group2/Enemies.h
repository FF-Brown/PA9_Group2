
//Implementation file for enemies

#pragma once

#include "Enemy.h"

class Basic : public Enemy
{
public:
    Basic(void)
    {
        health = 50;
        reward = 10;
        speed  = 10;

        healthScale = 255 / (double)health;

        shape.setRadius(8);
        shape.setFillColor(sf::Color(0, 0, 255)); //Blue
    }

protected:
    double healthScale = (health == 0) ? 0 : (255 / health);

    void update_color(void)
        { shape.setFillColor(sf::Color(0, 0, health * healthScale)); }
};

class BigBoi : public Enemy
{
public:
    BigBoi(void)
    {
        shape.setRadius(16);
        shape.setFillColor(sf::Color(255, 0, 0)); //Red

        health = 200;
        reward = 50;
        speed  = 5;
    }

protected:
    double healthScale = (health == 0) ? 0 : (255 / health);

    void update_color(void)
            { shape.setFillColor(sf::Color(health * healthScale, 0, 0)); }
};


class Empty : public Enemy
{
public:
    Empty(void)
    {
        isEnemy = false;
    }
};
