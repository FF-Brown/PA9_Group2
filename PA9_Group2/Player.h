
//Player Class Definition & Implementation File

#pragma once

#define INIT_HEALTH 100


class Player
{
private:
    int health = INIT_HEALTH;
    int XP = 0;
    int score = 0;
    int enemiesKilled = 0;

public:
    //Returns: true if the player is alive | false otherwise
    bool is_alive(void)
    {
        if (health > 0)
            return true;
        else
            return false;
    }

    //Returns the player's health
    int get_health(void)
    {
        if (health > 0)
            return health;
        else
            return 0;
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

    //Increments the number of enemies killed
    void inc_enemies_killed(void)
    {
        enemiesKilled++;
    }
};
