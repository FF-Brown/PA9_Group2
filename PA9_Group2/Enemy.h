

#pragma once

//Included Project Files
#include "Board.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>


class Enemy
{
protected:
    unsigned int ID;
    sf::CircleShape shape;

    int health;
    int attStrength;

public:
    bool isEnemy;

    Enemy(void);

    void set_ID(int nID)
    {
        ID = nID;
    }

    unsigned int get_ID(void)
    {
        return ID;
    }

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

    int get_damage(void)
        { return attStrength; }


    void move(const Board& board);

    void draw(sf::RenderWindow& window);
};
