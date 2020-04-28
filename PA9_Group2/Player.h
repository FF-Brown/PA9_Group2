
//Player Class Definition & Implementation File

#pragma once

#define INIT_HEALTH 100
#define INIT_XP     75


class Player
{
private:
    int health = INIT_HEALTH;
    int XP     = INIT_XP;
    int score         = 0;
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

    //Adds an amount to the player's XP
    void add_XP(int amount)
    {
        XP += amount;
        score += amount;
    }

    //Returns the player's XP
    int get_XP(void)
        { return XP;  }

    //Subtracts an amount from the playere's XP
    void remove_XP(int amount)
        { XP -= amount; }

    //Subtracts an amount from the player's health
    void damage(int amount)
        { health -= amount; }

    //Increments the number of enemies killed
    void inc_enemies_killed(void)
        { enemiesKilled++; }
};
