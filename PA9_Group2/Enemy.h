
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

    void update_color(void)
    {
        sf::Color color = getFillColor();
        color.a = (MAX_OPACITY - MIN_OPACITY) * ((double)health / (double)initHealth) + MIN_OPACITY; //Opacity decreases with health
        setFillColor(color);
    }

public:
    bool isEnemy; //true if the object is an Enemy, false if an Empty

    //Constructor
    Enemy(void)
    {
        isEnemy = true;
        setPosition(Board::getStartingPosition()); //Gets the position of the start of the path

        initHealth = 0;
        health = 0;
        reward = 0;
        speed  = 0;
    }

    void move(Board& board)
    {
        float dx, dy;

        switch (board.getDirection(getPosition()))
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

    bool is_alive(void)
    {
        if (health > 0)
            return true;
        else
            return false;
    }

    void draw(sf::RenderWindow& window)
    {
        update_color();
        window.draw(*this);
    }

    sf::Vector2f get_center_position(void)
    {
        sf::Vector2f center;
        center.x = getPosition().x + getRadius();
        center.y = getPosition().y + getRadius();
        return center;
    }

    void damage(int amount)
        { health -= amount; }

    int get_reward(void)
        { return reward; }
};
