#pragma once

//class for player - # of towers, amount of gold, total HP, etc

#include "header.h"

class Enemy {
public:
    sf::RectangleShape shape;
    sf::Vector2f enemyPosWindow;
    int health;
    bool alive;

    Enemy()
    {
        this->shape.setSize(sf::Vector2f(50.f, 50.f));
        this->shape.setFillColor(sf::Color(255, 255, 0));
        this->health = 255;
        this->alive = true;
    }

    void checkHealth()
    {
        this->shape.setFillColor(sf::Color(255, 0 + health, 0));
    }
};
