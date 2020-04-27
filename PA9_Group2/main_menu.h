
#pragma once

#include "Game.h"

#include <iostream>
#include <SFML\Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3


//Contains an option from the main menu
enum MainMenuOption
{
	INSTRUCTIONS,
	PLAY_GAME,
	NOTHING,
	EXIT
};

class Menu
{
private:
    sf::RenderWindow MenuWindow; //Could use this instead of pass sf::RenderWindow as parameter in all functions | use initializer list


	MainMenuOption selectedItemIndex;
	sf::Font font;
	sf::Text text[MAX_NUMBER_OF_ITEMS];
	struct button {
		sf::RectangleShape Shape;
		int buttonW;
		int buttonH;
	};
	button menu_buttons[3];

public:
	Menu(float width, float height);
	void display_main_menu(sf::RenderWindow& window);
	void mousePlace(sf::RenderWindow& window);
	void get_main_menu_option(sf::RenderWindow& window);
	MainMenuOption get_Selected_Index();
	void set_Selected_Index(MainMenuOption option);

    void play_game(sf::RenderWindow& window);
};



