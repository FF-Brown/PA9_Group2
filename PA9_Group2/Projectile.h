
#pragma once

#include "Utility.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>


#define SPEED 10


class Projectile
{
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    int damage;

public:
    Projectile(sf::Vector2f startPoint, sf::Vector2f endPoint, int initDamage)
    {
        shape.setPosition(startPoint);
        shape.setRadius(4);
        shape.setFillColor(sf::Color::Black);

        sf::Vector2f aimDir = endPoint - startPoint;
        sf::Vector2f aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
        velocity = { aimDirNorm.x * SPEED, aimDirNorm.y * SPEED };

        damage = initDamage;
    }

    sf::FloatRect get_bounds(void)
        { return shape.getGlobalBounds(); }

    sf::Vector2f get_position(void)
        { return shape.getPosition(); }

    int get_damage(void)
        { return damage; }

    void move(void)
        { shape.move(velocity); }

    void draw(sf::RenderWindow& window)
        { window.draw(shape); }
};