
#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "PA9.h"
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
private:
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

};



