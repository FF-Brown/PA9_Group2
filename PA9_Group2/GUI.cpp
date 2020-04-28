
#include "GUI.h"

Display::Display()
{
	if (!font.loadFromFile("Resources/Chunk Five.otf"))	//checks for font
	{
		std::cout << "Error Loading Font" << std::endl;
		return;
	}

	Shape.setFillColor(sf::Color::Green);
	Shape.setOutlineThickness(2);
	Shape.setOutlineColor(sf::Color::Green);	//set up buttons


	text.setFont(font);
	text.setCharacterSize(18);
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(3);			//and the text
	data = 0;
    highlighted = false;
}

void Display::set_size(int w, int h)
{
	buttonH = w;
	buttonW = h;						//width and height save for display
	Shape.setSize(sf::Vector2f(buttonW, buttonH));
}

void Display::set_position(int x, int y)
{
	if (x != 0 && y != 0)
	{
		Shape.setPosition(sf::Vector2f(x - buttonH, y - buttonW));
		text.setPosition(sf::Vector2f(x - buttonH, y - buttonW));
	}
	else if (y == 0)
	{
		Shape.setPosition(sf::Vector2f(x - buttonH, 0));
		text.setPosition(sf::Vector2f(x - buttonH, 0));
	}
	else if (x == 0)
	{
		Shape.setPosition(sf::Vector2f(0, y - buttonW));
		text.setPosition(sf::Vector2f(0, y - buttonW));
	}
}

void Display::set_text(string t, int size)
{
	text.setCharacterSize(size);
	text.setString(t);
}

void Display::draw_display(sf::RenderWindow& window)
{
    if (highlighted)
        Shape.setOutlineColor(sf::Color::Red);
    else
        Shape.setOutlineColor(sf::Color::Transparent);

	window.draw(Shape);
	window.draw(text);
}

void Display::set_data(int i)
{
	data = i;
}

int Display::get_data()
{
	return data;
}

void Display::highlight(bool set)
{
    highlighted = set;
}

bool Button::is_over(int mouseX, int mouseY)
{

	sf::Event event;

	int buttonX = Shape.getPosition().x;
	int buttonY = Shape.getPosition().y;

	int buttonPosW = buttonX + buttonW;
	int buttonPosH = buttonY + buttonH;		//finds the position in the window

	if (mouseX < buttonPosW && mouseX > buttonX&& mouseY < buttonPosH && mouseY > buttonY)
	{
		Shape.setOutlineThickness(2);
		Shape.setOutlineColor(sf::Color::Blue);
		return true;
	}
	else {
		Shape.setOutlineThickness(2);
		Shape.setOutlineColor(sf::Color::Green);
		return false;
	}


}

GUI::GUI()
{
    choice = NONE;
    towers[0] = Turret();
    towers[1] = Sniper();
	for (int i = 150, h = 0; h < 3; h++)
	{
		buttons[h].set_size(60, 60);
		buttons[h].set_position(780, i);
		buttons[h].set_text(towers[h].get_name(), 10);
        buttons[h].tower = towers[h];

		i += 100;

	}
	for (int i = 550, h = 0; h < 2; h++)
	{
		display[h].set_size(30, 150);
		display[h].set_position(i, 580);	//the int h on set size MUST be the same as y in position
		i += 150;
	}
	display[2].set_size(30, 150);
	display[2].set_position(600, 150);

	return;

}

void GUI::draw(sf::RenderWindow& window, int hp, int ex, int round)
{
	string str = "Health: " + to_string(hp) + "/ 100";
	display[0].set_text(str, 15);

	str = "Exp: " + to_string(ex);
	display[1].set_text(str, 15);

	str = "Round " + to_string(round);
	display[2].set_text(str, 15);

	for (int i = 0; i < 3; i++)
	{
		buttons[i].draw_display(window);
		buttons[i].is_over(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		display[i].draw_display(window);

	}
	choice = NONE;		//base choice is always none

	return;
}

TowerType GUI::get_tower_choice(int mouseX, int mouseY, Player& player)
{
    bool buttonClicked = false;
    int price;
    for (int i = 0; i < 3; i++)
    {
        if (buttons[i].is_over(mouseX, mouseY))
        {
            buttonClicked = true;
            choice = buttons[i].tower.get_type();
            price  = buttons[i].tower.get_price();
            std::cout << "Tower clicked" << std::endl;
        }
    }
    if (buttonClicked && player.get_XP() >= price)
        return choice;
    else
        return NONE;
}

void GUI::highlight_button(TowerType towerType)
{
    for (int i = 0; i < NUM_TOWERS; i++)
    {
        if (towers[i].get_type() == towerType)
            buttons[i].highlight(true);
        else
            buttons[i].highlight(false);
    }
}
