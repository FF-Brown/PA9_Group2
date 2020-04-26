
//Class Definition File for the base Tower

#pragma once

#include "Projectiles.h"
#include <SFML/Graphics.hpp>
//#include <Vector2.hpp>

class Tower
{
protected:
    Projectile* projectileType;
    sf::Vector2f position;

public:
    //Returns true if upgrade successful
    //virtual bool upgrade(void);
    Tower();
    sf::Vector2f getPosition() { return position; }
    void setPosition(sf::Vector2f location) { position = location; }


};

