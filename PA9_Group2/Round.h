
//Round class defintition file

#pragma once

//Included project files
#include "Enemies.h"

//Included std libraries
#include <queue>

//Number of rounds in the game
#define NUM_ROUNDS 12


class Round
{
private:
    int num;
    int reward;
    double spawnCoolDown; //Seconds between enemy spawning
    std::queue<Enemy> enemyQueue;

public:
    //Constructor for a particular round
    Round(int roundNum);

    //Default Constructor
    Round(void)
    {
        num = 0;
        reward = 0;
        spawnCoolDown = 0;
    }

    //Returns the next enemy in the queue and pops it
    Enemy get_next_enemy(void)
    {
        Enemy nextEnemy;
        if (enemyQueue.size() > 0) //If queue is not empty
        {
            nextEnemy = enemyQueue.front();
            enemyQueue.pop();
        }
        else
            nextEnemy = Empty();
        return nextEnemy;
    }

    //Returns true if the round is finished spawning enemies | false otherwise
    bool is_spawning_complete(void)
    {
        if (enemyQueue.size() == 0)
            return true;
        else
            return false;
    }

    //Returns the XP reward for the round
    int get_reward(void)
        { return reward; }

    //Returns spawn cool down time
    double get_spawn_cool_down(void)
        { return spawnCoolDown; }
};
