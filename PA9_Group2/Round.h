
#pragma once

#include "Enemies.h"

#include <queue>


#define NUM_ROUNDS 5

#define SPAWN_COOLDOWN 1 //Seconds between enemy spawns


class Round
{
private:
    int num;
    int reward;
    std::queue<Enemy> enemyQueue;

public:
    //Constructor for a particular round
    Round(int roundNum);

    //Default Constructor
    Round(void)
    {
        num = 0;
        reward = 0;
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
};
