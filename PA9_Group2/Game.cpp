
//Game Class Implementation File

#include "Game.h"
using namespace std;


Game::Game(sf::RenderWindow& window) : gameWindow(window)
{
    currentRound = 1;
    roundStarted = false;
    clock.restart();
    lastRoundEndTime = clock.getElapsedTime();
    lastSpawnTime    = clock.getElapsedTime();

    selectedTower = NONE;

    init_rounds();
    init_towerRef();
}

void Game::run(void)
{
    while (player.is_alive())
    {
        user_input_handler();

        if (Utility::time_since(clock, lastRoundEndTime).asSeconds() > PREP_TIME)
            roundStarted = true;

        move_projectiles();

        if (roundStarted)
        {
            spawn_enemy();
            spawn_projectiles();

            move_enemies();

            despawn_enemies();
            despawn_projectiles();

            if (player.is_alive() && rounds[currentRound - 1].is_spawning_complete() && enemies.size() == 0)
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
                TowerType newSelection = gui.get_tower_choice(event.mouseButton.x, event.mouseButton.y, player);
                if (newSelection == selectedTower)
                    selectedTower = NONE; //Unselect current tower
                else if (selectedTower != NONE && newSelection == NONE) //If a tower is currently selected and a new one isn't chosen
                    add_tower(event);
                else
                    selectedTower = newSelection;    //Update selection
                gui.highlight_button(selectedTower); //Update highlighted button
            }
            break;
        }
}

void Game::add_tower(sf::Event& event)
{
    bool towerAdded = board.addTower(sf::Vector2f(event.mouseButton.x, event.mouseButton.y), selectedTower);
    if (towerAdded)
    {
        player.remove_XP(towerRef[selectedTower].get_price()); //Take tower price out of player's XP balance
        selectedTower = NONE; //Reset selected tower
        gui.highlight_button(selectedTower); //Update highlighted button
    }
}

void Game::spawn_enemy(void)
{
    if (Utility::time_since(clock, lastSpawnTime).asSeconds() > SPAWN_COOLDOWN)
    {
        lastSpawnTime = clock.getElapsedTime();
        Enemy nEnemy = rounds[currentRound - 1].get_next_enemy(); //Get the next enemy in the current round's queue
        if (nEnemy.isEnemy)
            enemies.push_back(nEnemy); //Add enemy to game
    }
}

void Game::move_enemies(void)
{
    for (auto it = enemies.begin(); it != enemies.end(); it++) //Iterate through all enemies
    {
        it->move(board);
        if (board.isAtEnd(it->get_position())) //If the enemy reached the end of the path
        {
            player.damage(1);
            enemies.erase(it);
            return;
        }
    }
}

void Game::despawn_enemies(void)
{
    for (auto it = enemies.begin(); it != enemies.end(); it++) //Iterate through all enemies
        if (!it->is_alive())
        {
            player.add_XP(it->get_reward());
            player.inc_enemies_killed();
            enemies.erase(it);
            return;
        }
}

void Game::spawn_projectiles(void)
{
    Tower* towers = board.getTowers(); //All towers on the board
    for (int i = 0; i < board.getTowerCount(); i++) //Iterate through all towers
        if (towers[i].is_active())
        {
            bool found = false;
            sf::Vector2f closestEnemy;
            sf::Vector2f towerPos  = towers[i].get_position();
            double closestDistance = towers[i].get_range();

            for (auto it = enemies.begin(); it != enemies.end(); it++) //Iterate through all enemies to find the closest to the current tower
            {
                sf::Vector2f enemyPos = it->get_center_position();

                double distance = Utility::calculate_distance(towerPos, enemyPos);
                if (distance < closestDistance)
                {
                    found = true;
                    closestEnemy = enemyPos; //Position of closest enemy
                    closestDistance = distance;
                }
            }
            if (found) //Enemy found in range
            {
                towers[i].fire();
                projectiles.push_back(Projectile(towerPos, closestEnemy, towers[i].get_damage())); //Spawn projectile
            }
        }
}

void Game::move_projectiles(void)
{
   for (auto it = projectiles.begin(); it != projectiles.end(); it++) //Iterate through all projectiles
        it->move();
}

void Game::despawn_projectiles(void)
{
    for (auto projectileIt = projectiles.begin(); projectileIt != projectiles.end(); projectileIt++) //Iterate through all projectiles
        for (auto enemyIt = enemies.begin(); enemyIt != enemies.end(); enemyIt++) //Iterate through all enemies
        {
            if (projectileIt->get_bounds().intersects(enemyIt->get_bounds())) //If projectile hit an enemy
            {
                enemyIt->damage(projectileIt->get_damage()); //Damage enemy
                projectiles.erase(projectileIt);
                return;
            }
            sf::Vector2f projPos = projectileIt->get_position();
            if (!(0 <= projPos.x && projPos.y <= GRID_WIDTH && 0 <= projPos.y && projPos.y <= GRID_HEIGHT)) //Erase projectiles that left the board
            {
                projectiles.erase(projectileIt);
                return;
            }
        }
}

void Game::render(void)
{
    gameWindow.clear();

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

bool Game::display_results(void)
{
    //Display stats

    //Menu button
    

    sf::Event event;
    while (gameWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            gameWindow.close();
            return false;
        }
        if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button = sf::Mouse::Left))
        {
            sf::Vector2i mousePos = { event.mouseButton.x, event.mouseButton.y };
            if (20 < mousePos.x && mousePos.x < 40 && 20 < mousePos.y && mousePos.y < 10);
                return false;
        }
    }
    return true;
}
