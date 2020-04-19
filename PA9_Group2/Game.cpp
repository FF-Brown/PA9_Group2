
//Game Class Implementation File

#include "Game.h"
using namespace std;


Game::Game(sf::RenderWindow* window)
{
    gameWindow = window;


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

        gameWindow->clear(); //First time in game loop: Clears menu items

        //board.draw(gameWindow); //Including towers/traps
        //gui.draw(gameWindow);

        //Draw all enemies from linked list/vector
        for (int i = 0; i < enemies.size(); i++)
            enemies[i]->draw(gameWindow);

        //Draw all projectiles
        for (int i = 0; i < projectiles.size(); i++)
            projectiles[i]->draw(gameWindow);

        gameWindow->display();
    }
}

void Game::user_input_handler(void)
{

}

void Game::collision_handler(void)
{

}

void Game::display_results()
{

}
