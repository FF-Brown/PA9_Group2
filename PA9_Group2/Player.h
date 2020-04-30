
//Player Class Definition & Implementation File

#pragma once

#define INIT_HEALTH 20
#define INIT_XP     150


class Player
{
private:
    int health = INIT_HEALTH;
    int XP     = INIT_XP;
    int score         = 0;
    int enemiesKilled = 0;
    bool won = false;

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
        { return XP; }

    //Subtracts an amount from the playere's XP
    void remove_XP(int amount)
        { XP -= amount; }

    //Subtracts an amount from the player's health
    void damage(int amount)
        { health -= amount; }

    //Increments the number of enemies killed
    void inc_enemies_killed(void)
        { enemiesKilled++; }

    //Sets the player to have won the game
    void set_won(void)
        { won = true; }

    //Returns true if the player won the game | false otherwise
    bool check_won(void)
        { return won; }

    //Returns the player's score
    int get_score(void)
        { return score; }

    //Returns the number of enemies killed
    int get_enemies_killed(void)
        { return enemiesKilled; }
};
