
#pragma once

#include "Enemies.h"

#include <queue>


#define NUM_ROUNDS 2

#define SPAWN_COOLDOWN 1 //Seconds between enemy spawns


class Round
{
private:
    int num;
    int reward;
    std::queue<Enemy> enemyQueue;

public:
    Round(void) {};
    Round(int roundNum);

    Enemy get_next_enemy(void);
    bool is_spawning_complete(void);
};
