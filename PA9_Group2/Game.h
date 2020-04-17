
//Game Class Definition File

#pragma once

//Included Project Files
#include "Board.h"     
class Board {}; //temp
#include "Player.h"
#include "Tower.h"
#include "Enemy.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>

//Included STD Libraries


class Game
{
private:
    Board board;
    Player player;

    int currentRound = 1;

public:
    //Constructor
    Game(void);

    //Returns the current round num
    int get_current_round(void)
    {
        return currentRound;
    }

    //Advances counter to next round
    void next_round(void)
    {
        currentRound++;
    }

    void run(void);

    //Displays highest round passed & total score
    void display_results(void);
};
