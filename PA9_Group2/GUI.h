 #pragma once
#include "Board.h"
#include "Towers.h"
#include "Player.h"

class Display
{
protected:
	sf::RectangleShape Shape;
	int buttonW;
	int buttonH;
	int data;
	sf::Font font;
	sf::Text text;
    bool highlighted;

public:
	Display();
	void set_size(int w, int h);
	void set_position(int x, int y);
	void set_text(std::string, int size);
	void draw_display(sf::RenderWindow& window);
	void set_data(int);
	int get_data();
    void highlight(bool set);
};

class Button : public Display
{
public:
	bool is_over(int mouseX, int mouseY);		//checks if the mouse is over
    Tower tower;
};

class GUI : public Button
{
	Display round;
	Display display[NUM_TOWERS];
	Button buttons[NUM_TOWERS];
    Tower towers[NUM_TOWERS]; //For reference in button info
	TowerType choice;
public:
	GUI();		//initates all the buttons
	void draw(sf::RenderWindow& window, int hp, int xp, int round);
	TowerType get_tower_choice(int mouseX, int mouseY, Player& player);
    void highlight_button(TowerType towerType);
};
