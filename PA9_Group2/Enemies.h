
//Implementation file for enemies

#pragma once

#include "Enemy.h"

//Medium speed, size, health
class Basic : public Enemy
{
public:
    Basic(void)
    {
        isEnemy = true;
        setRadius(8);
        CircleShape::move(sf::Vector2f(-8, 0));
        setFillColor(sf::Color::Blue); 

        health = initHealth = 50;
        reward = 8;
        speed = 14;
    }
};

//Slow, large, and high health
class BigBoi : public Enemy
{
public:
    BigBoi(void)
    {
        isEnemy = true;
        setRadius(12);
        CircleShape::move(sf::Vector2f(-12, 0));
        setFillColor(sf::Color::Red);

        health = initHealth = 250;
        reward = 25;
        speed = 10;
    }
};

//Fast, small, medium health
class SpeedyBoi : public Enemy
{
public:
    SpeedyBoi(void)
    {
        isEnemy = true;
        setRadius(6);
        CircleShape::move(sf::Vector2f(-6, 0));
        setFillColor(sf::Color::Yellow);

        health = initHealth = 45;
        reward = 15;
        speed = 27;
    }
};

//Non-enemy used to create gaps in the enemy queue in rounds
class Empty : public Enemy
{
public:
    Empty(void)
    {
        isEnemy = false;
    }
};
