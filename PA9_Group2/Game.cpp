
//Game Class Implementation File

#include "Game.h"
using namespace std;


Game::Game(sf::RenderWindow& window) : gameWindow(window)
{
    currentRound = 0;
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
    while (player.is_alive() && gameWindow.isOpen())
    {
        user_input_handler();

        if (Utility::time_since(clock, lastRoundEndTime).asSeconds() > PREP_TIME)
            if (!roundStarted)
            {
                currentRound++;
                roundStarted = true;
            }

        move_projectiles();
        move_enemies();

        despawn_enemies();
        despawn_projectiles();

        if (roundStarted)
        {
            spawn_enemy();
            spawn_projectiles();

            if (player.is_alive() && rounds[currentRound - 1].is_spawning_complete() && enemies.size() == 0)
            {
                player.add_XP(rounds[currentRound - 1].get_reward());

                if (currentRound == NUM_ROUNDS) //If the highest round was beaten
                {
                    player.set_won();
                    break;
                }
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
    if (Utility::time_since(clock, lastSpawnTime).asSeconds() > rounds[currentRound - 1].get_spawn_cool_down())
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
        if (board.isAtEnd(it->getPosition())) //If the enemy reached the end of the path
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
            sf::Vector2f towerPos  = towers[i].get_center_position();
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
                projectiles.push_back(Projectile(towerPos, closestEnemy, towers[i].get_damage(), towers[i].get_range(), towers[i].get_proj_speed())); //Spawn projectile
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
            if (projectileIt->getGlobalBounds().intersects(enemyIt->getGlobalBounds())) //If projectile hit an enemy
            {
                enemyIt->damage(projectileIt->get_damage()); //Damage enemy
                projectiles.erase(projectileIt);
                return;
            }
            if (!projectileIt->is_active()) //If projectile has reached the end of its range
            {
                projectiles.erase(projectileIt);
                return;
            }
            sf::Vector2f projPos = projectileIt->getPosition();
            if (!(0 <= projPos.x && projPos.x <= GRID_WIDTH
               && 0 <= projPos.y && projPos.y <= GRID_HEIGHT)) //If the projectile has left the board
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
    gui.draw(gameWindow, player.get_health(), player.get_XP(), (currentRound == 0) ? 1 : currentRound); //If round 1 hasn't started yet: still display round 1 in GUI

    //Draw all enemies
    for (auto it = enemies.begin(); it != enemies.end(); it++)
        it->draw(gameWindow);

    //Draw all projectiles
    for (auto it = projectiles.begin(); it != projectiles.end(); it++)
        gameWindow.draw(*it);

    gameWindow.display();
}


void Game::display_results(void)
{
    //Load font
    sf::Font font;
    if (!font.loadFromFile("Resources/Chunk Five.otf"))
    {
        std::cout << "Error Loading Font" << std::endl;
        return;
    }
    
    //Define text
    sf::Text text[4];
    text[0].setString(player.check_won() ? "You won!" : "Game Over! You made it to round " + to_string(currentRound));
    text[1].setString("Total score: " + to_string(player.get_score()));
    text[2].setString("Total enemies killed: " + to_string(player.get_enemies_killed()));
    text[3].setString("MENU");

    //Set up Menu button
    sf::RectangleShape button;
    sf::Vector2f buttonPos(70, 450);

    button.setSize(sf::Vector2f(100, 100));
    button.setPosition(buttonPos);
    button.setFillColor(sf::Color::Green);
    button.setOutlineColor(sf::Color::Green);
    button.setOutlineThickness(2);

    //Set up text style
    for (int i = 0; i < 4; i++)
    {
        text[i].setFont(font);
        text[i].setOutlineThickness(2);
        text[i].setOutlineColor(sf::Color::Black);
        text[i].setFillColor(sf::Color::White);
        text[i].setCharacterSize(25);
        if (i == 3)
            text[i].setPosition(buttonPos);
        else
            text[i].setPosition(sf::Vector2f(50, (50 * i) + 10));
    }

    //Display loop
    bool exit = false;
    while (!exit && gameWindow.isOpen())
    {
        //Render
        gameWindow.clear();
        gameWindow.draw(button);
        for (int i = 0; i < 4; i++)
            gameWindow.draw(text[i]);
        gameWindow.display();

        //Event handling: highlight button, leave screen, close window
        sf::Event event;
        while (gameWindow.pollEvent(event))
            switch (event.type)
            {
            case sf::Event::Closed:
                gameWindow.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                    if (button.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                        exit = true;
                break;
            case sf::Event::MouseMoved:
                if (button.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
                    button.setOutlineColor(sf::Color::Blue);
                else
                    button.setOutlineColor(sf::Color::Green);
                break;
            }
    }
}
