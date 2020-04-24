#pragma once

#include "Enemy.h"

class Basic : public Enemy
{
public:
    Basic(void) : Enemy()
    {

    }
};


class EmptyEnemy : public Enemy
{
public:
    EmptyEnemy(void)
    {
        isEnemy = false;
    }
};
