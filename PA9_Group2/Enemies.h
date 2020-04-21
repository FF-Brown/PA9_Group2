#pragma once

#include "Enemy.h"

class Basic : public Enemy
{
public:
    Basic(void) : Enemy()
    {

    }
};




class NoSpawn : public Enemy
{
public:
    NoSpawn(void)
    {
        isEnemy = false;
    }
};
