
//Game Class Definition File

#pragma once

//Included Project Files
#include "Board.h"
#include "GUI.h"
#include "Player.h"
#include "Tower.h"
#include "Towers.h"
#include "Enemy.h"
#include "Round.h"
#include "Projectile.h"


//Included SFML Libraries
#include <SFML/Graphics.hpp>


//Included Std Libraries
#include <list>
#include <iterator>
#include <ctime>


#define PREP_TIME 10.0     //Seconds before first enemy in round spawns
#define SPAWN_COOLDOWN 1.5 //Seconds between enemy spawns


class Game
{
private:
    sf::RenderWindow& gameWindow; //Reference to window

    Board board;
    GUI gui;

    Player player;

    std::list<Enemy> enemies;
    std::list<Projectile> projectiles;

    Round rounds[NUM_ROUNDS]; //Has offset of -1 for array index
    int currentRound = 1;

    bool roundStarted;
    time_t lastRoundEndTime;
    time_t lastSpawnTime;

    TowerType selectedTower = NONE;

public:
    //Constructor
    Game(sf::RenderWindow& window);


    //Functions to run game

    void run(void);

    void user_input_handler(void);


    void spawn_enemy(void);
    
    void move_enemies(void);

    void despawn_enemies(void);

    
    void spawn_projectiles(void);

    void move_projectiles(void);

    void despawn_projectiles(void);


    void render(void);


    //Displays highest round passed, total score, and number of enemies killed
    void display_results(void);
};
