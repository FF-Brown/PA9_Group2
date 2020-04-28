
//Class definition file for the base Enemy

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
    bool isEnemy; //true if the object is an Enemy, false if an Empty

    //Constructor
    Enemy(void)
    {
        isEnemy = true;
        shape.setPosition(Board::getStartingPosition()); //Gets the position of the start of the path

        health = 0;
        reward = 0;
        speed  = 0;
    }

    void move(Board& board)
    {
        float dx, dy;

        switch (board.getDirection(shape.getPosition()))
        {
        case UP:    dx = 0;
                    dy = -1 * speed;
                    break;
        case DOWN:  dx = 0;
                    dy = speed;
                    break;
        case LEFT:  dx = -1 * speed;
                    dy = 0;
                    break;
        case RIGHT: dx = speed;
                    dy = 0;
                    break;
        default:    dx = 0;
                    dy = 0;
        }
        dx *= SPEED_SCALE;
        dy *= SPEED_SCALE;

        shape.move(dx, dy);
    }

    bool is_alive(void)
    {
        if (health > 0)
            return true;
        else
            return false;
    }

    void damage(int amount)
        { health -= amount; }

    sf::Vector2f get_position(void)
        { return shape.getPosition(); }

    int get_reward(void)
        { return reward; }

    void draw(sf::RenderWindow& window)
        { window.draw(shape); }
};
