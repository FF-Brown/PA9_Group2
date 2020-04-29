
#pragma once

#include "Utility.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>


class Projectile
{
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    sf::Vector2f startPos;
    int maxDistance;
    int damage;
    bool active;

public:
    Projectile(sf::Vector2f startPoint, sf::Vector2f endPoint, int initDamage, int range, int setSpeed)
    {
        startPos = startPoint;
        shape.setPosition(startPoint);
        shape.setRadius(4);
        shape.setFillColor(sf::Color::Black);

        sf::Vector2f aimDir = endPoint - startPoint;
        sf::Vector2f aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
        velocity = { aimDirNorm.x * setSpeed, aimDirNorm.y * setSpeed };

        active = true;
        maxDistance = range;
        damage = initDamage;
    }

    void draw(sf::RenderWindow& window)
    {
        if (active)
            window.draw(shape);
    }

    void move(void)
    {
        shape.move(velocity);
        if (Utility::calculate_distance(startPos, get_position()) > maxDistance)
            active = false;
    }

    bool is_active(void)
        { return active; }

    sf::FloatRect get_bounds(void)
        { return shape.getGlobalBounds(); }

    sf::Vector2f get_position(void)
        { return shape.getPosition(); }

    int get_damage(void)
        { return damage; }
};