
//Class definition file for the base Enemy

#pragma once

//Included Project Files
#include "Board.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>

#include <cstdint>

#define SPEED_SCALE 0.05
#define MIN_OPACITY 120


class Enemy
{
protected:
    sf::CircleShape shape;

    int health;
    int reward;
    int speed;

    double healthScale;

    void set_health_scale(void)
        { healthScale = (health == 0) ? 0 : ((255 - MIN_OPACITY) / health); }

    void update_color(void)
    {
        sf::Color color = shape.getFillColor();
        color.a = (health * healthScale) + MIN_OPACITY; //Opacity decreases with health
        shape.setFillColor(color);
    }

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

        //Trying with center position instead of vanilla position
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

        shape.move(dx, dy);
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
        window.draw(shape);
    }

    sf::Vector2f get_center_position(void)
    {
        sf::Vector2f center;
        center.x = shape.getPosition().x + shape.getRadius();
        center.y = shape.getPosition().y + shape.getRadius();
        return center;
    }

    sf::Vector2f get_position(void)
        { return shape.getPosition(); }

    sf::FloatRect get_bounds(void)
        { return shape.getGlobalBounds(); }

    void damage(int amount)
        { health -= amount; }

    int get_reward(void)
        { return reward; }
};
