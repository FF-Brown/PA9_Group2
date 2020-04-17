
#pragma once

#include "Board.h"
#include "Player.h"
#include "Tower.h"
#include "Enemy.h"


class Game
{
private:
    Board board;
    Player player;

    int currentRound = 1;

public:
    Game(void);

    int get_current_round(void)
    {
        return currentRound;
    }

    void next_round(void)
    {
        currentRound++;
    }

    run(void);

    display_results(void);
};
