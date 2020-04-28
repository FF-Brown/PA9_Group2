

#pragma once

//Included Project Files
#include "Board.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>

#define SPEED_SCALE 0.1


class Enemy
{
protected:
    sf::CircleShape shape;

    int health;
    int reward;
    int speed;

public:
    bool isEnemy;

    Enemy(void);

    void damage(int amount)
    {
        health -= amount;
    }

    bool is_alive(void)
    {
        if (health > 0)
            return true;
        else
            return false;
    }

    sf::Vector2f get_position(void)
    {
        return shape.getPosition();
    }

    int get_reward(void)
    {
        return reward;
    }


    void move(Board& board);

    virtual void draw(sf::RenderWindow& window);
};
