
//Game Class Definition File

#pragma once

//Included Project Files
#include "Board.h"     
class Board {}; //temp
#include "GUI.h"
class GUI {}; //temp
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
    GUI towerMenu;
    Player player;

    sf::RenderWindow gameWindow(...);

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

    //Runs the game
    void run(void);

    void user_input_handler(void);

    void collision_handler(void);

    //Displays highest round passed & total score
    void display_results(void);
};
