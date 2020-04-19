
//Class Definition File for the base Tower

#pragma once

#include "Projectiles.h"


class Tower
{
protected:
    Projectile* projectileType;

public:
    //Returns true if upgrade successful
    virtual bool upgrade(void);
};