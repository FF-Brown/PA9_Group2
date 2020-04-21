
#include "Round.h"


Round::Round(int roundNum)
{
    num = roundNum;

    switch (roundNum)
    {
    //Define Round 1: 3 basic enemies
    case 1:
        reward = 100;
        for (int i = 0; i < 3; i++)
            enemyQueue.push(Basic()); //5 Basic enemies
        break;

    //Define Round 2: 2 waves of 3 basic enemies
    case 2:
        reward = 120;
        for (int i = 0; i < 3; i++)
            enemyQueue.push(Basic()); //3 basic enemies
        for (int i = 0; i < 2; i++)
            enemyQueue.push(NoSpawn()); //2 NoSpawns
        for (int i = 0; i < 3; i++)
            enemyQueue.push(Basic()); //3 Basic enemies
        break;
    }
}

Enemy Round::get_next_enemy(void)
{
    Enemy nextEnemy;
    if (enemyQueue.size() > 0)
    {
        nextEnemy = enemyQueue.front();
        enemyQueue.pop();
    }
    else
        nextEnemy = NoSpawn();
    return nextEnemy;
}

bool Round::is_spawning_complete(void)
{
    if (enemyQueue.size() == 0)
        return true;
    else
        return false;
}
