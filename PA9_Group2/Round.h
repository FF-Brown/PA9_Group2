
#pragma once

#include "Enemies.h"

#include <queue>


#define NUM_ROUNDS 2


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
