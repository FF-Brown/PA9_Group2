
//Player Class Definition & Implementation File

#pragma once

#define INIT_HEALTH 100


class Player
{
private:
    int health = INIT_HEALTH;
    int XP = 0;
    int score = 0;

public:
    //Returns the player's health
    int get_health(void)
    {
        return health;
    }

    //Subtracts an amount from the player's health
    void damage(int amount)
    {
        health -= amount;
    }

    //Returns the player's XP
    int get_XP(void)
    {
        return XP;
    }

    //Adds an amount to the player's XP
    void add_XP(int amount)
    {
        XP += amount;
        score += amount;
    }
};
