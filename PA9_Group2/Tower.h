
//Class Definition File for the base Tower

#pragma once

#include "Projectiles.h"


class Tower
{
protected:
    Projectile* projectileType;
    int location;

public:
    //Returns true if upgrade successful
    virtual bool upgrade(void) = 0;
};