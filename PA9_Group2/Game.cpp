
//Game Class Implementation File

#include "Game.h"
using namespace std;


Game::Game(void)
{

}

void Game::run(void)
{


    while (player.is_alive())
    {

        user_input_handler();


        //Spawn enemies

        //Move all enemies


        collision_handler();


        //Render
        gameWindow.clear();

        board.draw(gameWindow); //Including towers/traps
        towerMenu.draw(gameWindow);

        /*draw all enemies from linked list/vector*/
        /*draw all projectiles*/

        gameWindow.display();
    }



    
}

void user_input_handler(void)
{

}

void collision_handler(void)
{

}

void Game::display_results(void)
{

}
