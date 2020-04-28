
//Game Class Implementation File

#include "Game.h"
using namespace std;


Game::Game(sf::RenderWindow& window) : gameWindow(window)
{
    roundStarted = false;
    clock.restart();
    lastRoundEndTime = clock.getElapsedTime();
    lastSpawnTime = clock.getElapsedTime();

    for (int i = 0; i < NUM_ROUNDS; i++)
        rounds[i] = Round(i + 1);
}

void Game::run(void)
{
    while (player.is_alive())
    {
        user_input_handler();

        if ((clock.getElapsedTime() - lastRoundEndTime).asSeconds() > PREP_TIME)
            roundStarted = true;

        if (roundStarted)
        {
            spawn_enemy();
            spawn_projectiles();

            move_enemies();
            move_projectiles();

            despawn_enemies();
            despawn_projectiles();

            if (rounds[currentRound - 1].is_spawning_complete() && enemies.size() == 0)
            {
                currentRound++;
                roundStarted = false;
                lastRoundEndTime = clock.getElapsedTime();
            }
        }
        render();
    }
}

void Game::user_input_handler(void)
{
    sf::Event event;
    while (gameWindow.pollEvent(event))
        switch (event.type)
        {
        case sf::Event::Closed:
            gameWindow.close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                selectedTower = gui.get_tower_choice(event.mouseButton.x, event.mouseButton.y);
                if (selectedTower != NONE)
                {
                    //board.enable_gridlines();
                    if (board.addTower(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)/*, selectedTower*/));
                    {
                        //gui.deselect_tower(selectedTower); //GUI::unselect_tower(Tower selectedTower): Unhighlights the tower button
                        selectedTower = NONE;
                        //board.disable_gridlines();
                    }
                }
            }
            break;
        }
}


void Game::spawn_enemy(void)
{
    if ((clock.getElapsedTime() - lastSpawnTime).asSeconds() > SPAWN_COOLDOWN)
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
    {
        it->move(board);
        if (board.is_at_castle(it->get_position()))
        {
            player.damage(it->get_damage());
            enemies.erase(it);
        }
    }
}

void Game::despawn_enemies(void)
{
    for (auto it = enemies.begin(); it != enemies.end(); it++)
    {
        if (!it->is_alive())
        {
            player.add_XP(it->get_reward());
            player.inc_enemies_killed();
            enemies.erase(it);
        }
    }
}

void Game::spawn_projectiles(void)
{
    Tower* towers = board.getTowers();

    for (int i = 0; i < board.getTowerCount(); i++)
        if (towers[i].is_active())
        {
            sf::Vector2f towerPos = towers[i].getPosition();

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
            if (closestEnemy == nullptr) //No enemies found in range
                continue;
            
            towers[i].fire();
            closestEnemy->damage(towers[i].getDamage()); //Damage enemy
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
