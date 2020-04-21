
//Game Class Implementation File

#include "Game.h"
using namespace std;


Game::Game(sf::RenderWindow& window) : gameWindow(window)
{
    numEnemies = 0;

    roundStarted = false;
    lastRoundEndTime = time(nullptr);
    lastSpawnTime = time(nullptr);

    for (int i = 0; i < NUM_ROUNDS; i++)
        rounds[i] = Round(i + 1);
}

void Game::run(void) //Refactor
{

    while (player.is_alive())
    {
        user_input_handler();


        if (difftime(time(nullptr), lastRoundEndTime) > PREP_TIME)
            roundStarted = true;


        if (roundStarted)
        {
            spawn_enemy();
            move_enemies();


            //Poison effect?


            spawn_projectiles();

            collision_handler();
        }

        if (rounds[currentRound - 1].is_spawning_complete() && numEnemies == 0)
        {
            currentRound++;
            roundStarted = false;
        }

        render();

    }
}

void Game::user_input_handler(void)
{

}


void Game::spawn_enemy(void)
{
    if (difftime(time(nullptr), lastSpawnTime) > SPAWN_COOLDOWN)
    {
        Enemy nEnemy = rounds[currentRound - 1].get_next_enemy();
        if (nEnemy.isEnemy)
        {
            nEnemy.set_ID(numEnemies++); //Set ID to the next number and increment
            enemies.push_back(nEnemy);
        }
    }
}

void Game::move_enemies(void)
{
    list<Enemy>::iterator enemyIt;
    for (enemyIt = enemies.begin(); enemyIt != enemies.end(); enemyIt++)
        enemyIt->move(board);
}

void Game::spawn_projectiles(void)
{

}

void Game::collision_handler(void)
{

}

void Game::render(void)
{
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

void Game::display_results(void)
{

}
