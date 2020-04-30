
//Class definition file for the base Enemy

#pragma once

//Included Project Files
#include "Board.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>


#define SPEED_SCALE 0.05
#define MAX_OPACITY 255
#define MIN_OPACITY 100


class Enemy : public sf::CircleShape
{
protected:
    int initHealth;
    int health;
    int reward;
    int speed;

    //Updates the opacity of the enemy shape based on health percentage
    void update_opacity(void)
    {
        sf::Color color = getFillColor();
        color.a = (MAX_OPACITY - MIN_OPACITY) * ((double)health / (double)initHealth) + MIN_OPACITY; //Opacity decreases with health
        setFillColor(color);
    }

public:
    bool isEnemy; //true if the object is an Enemy, false if an Empty object

    //Constructor
    Enemy(void)
    {
        isEnemy = false;
        setPosition(Board::getStartingPosition()); //Gets the position of the start of the path

        initHealth = 0;
        health = 0;
        reward = 0;
        speed  = 0;
    }

    //Moves the enemy in the direction specified by the board based on its current position
    void move(Board& board)
    {
        float dx, dy;

        switch (board.getDirection(get_center_position()))
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

        sf::CircleShape::move(dx, dy);
    }

    //Returns true if the enemy is still alive | false otherwise
    bool is_alive(void)
    {
        if (health > 0)
            return true;
        else
            return false;
    }

    //Updates the opacity of the enemy shape and draws it to the window
    void draw(sf::RenderWindow& window)
    {
        update_opacity();
        window.draw(*this);
    }

    //Returns the coordinate of the center of the enemy shape
    sf::Vector2f get_center_position(void)
    {
        sf::Vector2f center;
        center.x = getPosition().x + getRadius();
        center.y = getPosition().y + getRadius();
        return center;
    }

    //Removes health from the enemy based on the amount argument
    void damage(int amount)
        { health -= amount; }

    int get_reward(void)
        { return reward; }
};
