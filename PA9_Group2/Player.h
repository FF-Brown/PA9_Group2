
#pragma once

#define INIT_HEALTH 100


class Player
{
private:
    int health = INIT_HEALTH;
    int XP = 0;

public:
    int get_health(void)
    {
        return health;
    }

    void damage(int amount)
    {
        health -= amount;
    }

    int get_XP(void)
    {
        return XP;
    }

    void add_XP(int amount)
    {
        XP += amount;
    }
};
