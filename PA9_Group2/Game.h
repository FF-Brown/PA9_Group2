
//Game Class Definition File

#pragma once

//Included Project Files
#include "Board.h"
#include "GUI.h"
class GUI {}; //temp
#include "Player.h"
#include "Tower.h"
#include "Enemy.h"
#include "Round.h"


//Included SFML Libraries
#include <SFML/Graphics.hpp>


//Included Std Libraries
#include <list>
#include <iterator>
#include <ctime>


#define NUM_ROUNDS 1

#define PREP_TIME 10.0     //Seconds before first enemy in round spawns
#define SPAWN_COOLDOWN 1.5 //Seconds between enemy spawns


class Game
{
private:
    //Reference to window
    sf::RenderWindow& gameWindow;

    Board board;
    GUI gui;

    Player player;

    std::list<Enemy> enemies;
    int numEnemies;

    std::list<Projectile> projectiles;

    //Has offset of -1 for array bound
    Round rounds[NUM_ROUNDS];

    int currentRound = 1;

    bool roundStarted;
    time_t lastRoundEndTime;
    time_t lastSpawnTime;

public:
    //Constructor
    Game(sf::RenderWindow& window);


    //Functions to run game

    void run(void);

    void user_input_handler(void);

    void spawn_enemy(void);
    
    void move_enemies(void);
    
    void spawn_projectiles(void);

    void collision_handler(void);

    void render(void);


    //Displays highest round passed, total score, and number of enemies killed
    void display_results(void);
};
