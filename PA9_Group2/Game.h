
//Game Class Definition File

#pragma once

//Included Project Files
#include "Player.h"
#include "Round.h"
#include "Board.h"
#include "GUI.h"
#include "Towers.h"
#include "Enemies.h"
#include "Projectile.h"
#include "Utility.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>

//Included Std Libraries
#include <string>
#include <list>
#include <iterator>


#define PREP_TIME 4.0 //Seconds before first enemy in round spawns


class Game
{
public:
    //Constructor
    Game(sf::RenderWindow& window);

    //Run game
    void run(void);

    //Displays if the player won, highest round passed, total score, and number of enemies killed
    void display_results(void);

private:
    sf::RenderWindow& gameWindow; //Reference to window
    sf::Clock clock; //Clock to track in-game time

    Player player;
    Board board;
    GUI gui;

    int currentRound;
    Round rounds[NUM_ROUNDS]; //Array of all rounds | has offset of -1 for array index
    void init_rounds(void)
    {
        for (int i = 0; i < NUM_ROUNDS; i++)
            rounds[i] = Round(i + 1); //Round 1 stored in rounds[0], Round 2 in rounds[1], etc.
    }

    std::list<Enemy> enemies;          //Contains all enemies on the board
    std::list<Projectile> projectiles; //Contains all projectiles on the board

    bool roundStarted;
    sf::Time lastRoundEndTime; //Time that the previous round ended
    sf::Time lastSpawnTime;    //Time that the previous enemy was spawned

    TowerType selectedTower; //Currently selected tower in the GUI

    Tower towerRef[NUM_TOWERS]; //Tower data used for reference
    void init_towerRef(void)
    {
        towerRef[TURRET] = Turret();
        towerRef[SNIPER] = Sniper();
    }


    //Game Functions

    //Handles user input during the game: closing the window, selected a tower from the GUI, and placing a tower on the board
    void user_input_handler(void);

    //Adds the selected tower to the board
    void add_tower(sf::Event& event);


    //Spawns the next enemy in the round, if the cooldown time has passed
    void spawn_enemy(void);
    
    //Moves all enemies on the board, despawns any enemies that have reached the end of the path
    void move_enemies(void);

    //Despawns any enemy that has died
    void despawn_enemies(void);


    //Spawns any projectiles that towers have fired
    void spawn_projectiles(void);

    //Moves any existing projectiles on the board
    void move_projectiles(void);

    //Despawns any projectile that has collided with an enemy and damages the enemy
    void despawn_projectiles(void);


    //Draws the board, GUI, enemies, and projectiles and displays the window
    void render(void);
};
