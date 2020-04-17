
//Main Header File

#pragma once

//Included Project Files
#include "Game.h"

//Included SFML Libraries
#include <SFML/Graphics.hpp>

//Included Std Libraries
#include <iostream>
#include <string>


//Contains an option from the main menu
enum MainMenuOption
{
    INSTRUCTIONS,
    PLAY_GAME,
    EXIT
};


//Main Menu Functions

//Displays the main menu
void display_main_menu(sf::RenderWindow& mainMenuWindow);

//Gets the users selection from the main menu
//Returns option
MainMenuOption get_main_menu_option(void);

//Displays the game instructions
void display_instructions(void);

//Runs the game
void play_game(void);


//Miscellaneous Functions


