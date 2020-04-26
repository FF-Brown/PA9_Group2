
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
                                                        //^ Also if a tower button was clicked, highlights the button in menu to show shich tower is selected
        if (selectedTower != NONE)
        {
            //board.enable_gridlines();
            if (board.add_tower(mousePos/*, selectedTower*/)); //Board::add_tower(Vector2i mousePos, Tower nTower): Adds new tower to the board, returns true if added
            {
                gui.deselect_tower(selectedTower); //GUI::unselect_tower(Tower selectedTower): Unhighlights the tower button
                selectedTower = NONE;
                //board.disable_gridlines();
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
    for (auto it = enemies.begin(); it != enemies.end(); it++)
        it->move(board);
}

void Game::despawn_enemies(void)
{
    for (auto it = enemies.begin(); it != enemies.end(); it++)
    {
        if (!it->is_alive())
            enemies.erase(it);
    }
}

void Game::spawn_projectiles(void)
{
    Tower towers[] = board.get_towers();
    int numTowers  = board.get_num_towers();

    for (int i = 0; i < numTowers; i++)
        if (towers[i].is_active())
        {
            sf::Vector2f towerPos = towers[i].get_position();

            Enemy* closestEnemy = nullptr;
            double closestDistance = towers[i].get_range();

            for (auto it = enemies.begin(); it != enemies.end(); it++)
            {
                sf::Vector2f enemyPos = it->get_position();

                double distance = calculate_distance(towerPos, enemyPos);
                if (distance < closestDistance)
                {
                    closestEnemy = &(*it); //Address of closest enemy
                    closestDistance = distance;
                }
            }
            if (closestEnemy = nullptr) //No enemies found in range
                continue;

            towers[i].fire();
            closestEnemy->damage(towers[i].get_damage()); //Damage enemy
            projectiles.push_back(Projectile(towerPos, closestEnemy->get_position())); //Spawn projectile
        }
}

void Game::move_projectiles(void)
{
   for (auto it = projectiles.begin(); it != projectiles.end(); it++)
        it->move();
}

void Game::despawn_projectiles(void)
{
    for (auto it = projectiles.begin(); it != projectiles.end(); it++)
    {
        if (!it->is_active())
            projectiles.erase(it);
    }
}

void Game::render(void)
{
    gameWindow.clear(); //First time in game loop: Clears menu items

    board.draw(gameWindow);
    gui.draw(gameWindow, player.get_health(), player.get_XP(), currentRound);

    //Draw all enemies
    for (auto it = enemies.begin(); it != enemies.end(); it++)
        it->draw(gameWindow);

    //Draw all projectiles
    for (auto it = projectiles.begin(); it != projectiles.end(); it++)
        it->draw(gameWindow);

    gameWindow.display();
}

void Game::display_results(void)
{

}
