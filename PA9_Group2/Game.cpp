
//Game Class Implementation File

#include "Game.h"
using namespace std;


Game::Game(sf::RenderWindow& window) : gameWindow(window)
{
    roundStarted = false;
    lastRoundEndTime = time(nullptr);
    lastSpawnTime = time(nullptr);

    for (int i = 0; i < NUM_ROUNDS; i++)
        rounds[i] = Round(i + 1);
}

void Game::run(void)
{
    while (player.is_alive())
    {
        user_input_handler();

        if (difftime(time(nullptr), lastRoundEndTime) > PREP_TIME)
            roundStarted = true;

        if (roundStarted)
        {
            spawn_enemy();
            spawn_projectiles();

            move_enemies();
            move_projectiles();

            despawn_enemies();
            despawn_projectiles();

            //collision_handler();

            if (rounds[currentRound - 1].is_spawning_complete() && enemies.size() == 0)
            {
                currentRound++;
                roundStarted = false;
                lastRoundEndTime = time(nullptr);
            }
        }
        render();
    }
}

void Game::user_input_handler(void)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(gameWindow);

        selectedTower = gui.get_tower_option(mousePos); //GUI::get_tower_option(sf::Vector2i mousePos): Gets which tower was selected from gui menu (enum in Towers.h), or NONE
                                                        //^ Also if button was clicked, highlights button in menu to show shich tower is selected
        if (selectedTower != NONE)
        {
            board.enable_gridlines(); //?
            if (board.add_tower(mousePos, selectedTower)); //Board::add_tower(Vector2i mousePos, Tower nTower): Adds new tower to the board, returns true if added
            {
                gui.deselect_tower(selectedTower); //GUI::unselect_tower(Tower selectedTower): Unhighlights the tower button
                selectedTower = NONE;
                board.disable_gridlines(); //?
            }
        }

        //example code (do for each button in gui and each tower on board)
        sf::RectangleShape button;
        if (button.getGlobalBounds().contains((sf::Vector2f)mousePos))
        {
            //Button clicked
        }
    }
}


void Game::spawn_enemy(void)
{
    if (difftime(time(nullptr), lastSpawnTime) > SPAWN_COOLDOWN)
    {
        Enemy nEnemy = rounds[currentRound - 1].get_next_enemy();
        if (nEnemy.isEnemy)
        {
            nEnemy.set_ID(enemies.size()); //Set ID to the next number and increment
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

void Game::despawn_enemies(void)
{
    list<Enemy>::iterator enemyIt;
    for (enemyIt = enemies.begin(); enemyIt != enemies.end(); enemyIt++)
    {
        if (!enemyIt->is_alive())
            enemies.erase(enemyIt);
    }
}

void Game::spawn_projectiles(void)
{
    vector<Projectile> nProjectiles = board.spawn_projectiles(enemies); //Board::spawn_projectiles(const std::list<Enemy>&): Determines which towers should fire (cool down time), damages enemy, and returns projectiles in a vector
                                                                        //^ Iterate through all towers and call Tower::fire(std::list<Enemy>) on each, which finds closest enemy
    vector<Projectile>::iterator projectileIt;
    for (projectileIt = nProjectiles.begin(); projectileIt != nProjectiles.end(); projectileIt++)
        projectiles.push_front(*projectileIt);
}

void Game::move_projectiles(void)
{
    list<Projectile>::iterator projectileIt;
    for (projectileIt = projectiles.begin(); projectileIt != projectiles.end(); projectileIt++)
        projectileIt->move();
}

void Game::despawn_projectiles(void)
{
    list<Projectile>::iterator projectileIt;
    for (projectileIt = projectiles.begin(); projectileIt != projectiles.end(); projectileIt++)
    {
        if (!projectileIt->is_active())
            projectiles.erase(projectileIt);
    }
}

/*void Game::collision_handler(void)
{

}*/

void Game::render(void)
{
    gameWindow.clear(); //First time in game loop: Clears menu items

    board.draw(gameWindow);
    gui.draw(gameWindow, player.get_health(), player.get_XP(), currentRound);

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
