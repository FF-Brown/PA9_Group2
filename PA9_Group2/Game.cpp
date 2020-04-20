
//Game Class Implementation File

#include "Game.h"
using namespace std;


Game::Game(sf::RenderWindow& window) : gameWindow(window)
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

        gameWindow.clear(); //First time in game loop: Clears menu items

        //board.draw(gameWindow); //Including towers/traps
        //gui.draw(gameWindow);

        //Draw all enemies
        list<Enemy>::iterator enemyIt;
        for (enemyIt = enemies.begin(); enemyIt != enemies.end(); enemyIt++)
            enemyIt->draw(gameWindow);

        //Draw all projectiles
        list<Projectile>::iterator projectileIt;
        for (projectileIt = projectiles.begin(); projectileIt != projectiles.end(); projectileIt++)
            projectileIt->draw(gameWindow);

        gameWindow.display();
    }
}

void Game::user_input_handler(void)
{

}

void Game::collision_handler(void)
{

}

void Game::display_results(void)
{

}
