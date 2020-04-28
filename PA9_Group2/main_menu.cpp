
//Main Menu source File

#include "main_menu.h"
using namespace std;

//constructor for menu-  makes all the text and buttons
Menu::Menu(float width, float height)
{

	if (!font.loadFromFile("Resources/Chunk Five.otf"))	//this is just the text file im using we can change
	{
		std::cout << "Error Loading Font" << std::endl;
		return;
	}

	text[0].setFont(font);
	text[0].setFillColor(sf::Color::White);
	text[0].setString("Play Game");
	text[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu_buttons[0].Shape.setSize(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	menu_buttons[0].Shape.setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	menu_buttons[0].Shape.setFillColor(sf::Color::Black);


	text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setString("Instructions");
	text[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu_buttons[1].Shape.setSize(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	menu_buttons[1].Shape.setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	menu_buttons[1].Shape.setFillColor(sf::Color::Black);


	text[2].setFont(font);
	text[2].setFillColor(sf::Color::White);
	text[2].setString("Exit");
	text[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu_buttons[2].Shape.setSize(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	menu_buttons[2].Shape.setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	menu_buttons[2].Shape.setFillColor(sf::Color::Black);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		menu_buttons[i].buttonW = menu_buttons[i].Shape.getGlobalBounds().width;
		menu_buttons[i].buttonH = menu_buttons[i].Shape.getGlobalBounds().height;
	}

}

void Menu::display_main_menu(sf::RenderWindow& mainMenuWindow)
{
	sf::Event event;

	while (mainMenuWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::MouseMoved:
			mousePlace(mainMenuWindow);
			break;
		case sf::Event::MouseButtonPressed:
			get_main_menu_option(mainMenuWindow);
			break;
		}

	}
	mainMenuWindow.clear();
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		mainMenuWindow.draw(menu_buttons[i].Shape);
		mainMenuWindow.draw(text[i]);
	}
	mainMenuWindow.display();
}

//this changes the color of the option near the players mouse
void Menu::mousePlace(sf::RenderWindow& mainMenuWindow)
{
	int mouseX = sf::Mouse::getPosition(mainMenuWindow).x;
	int mouseY = sf::Mouse::getPosition(mainMenuWindow).y;

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		int buttonX = (menu_buttons[i].Shape.getPosition().x);
		int buttonY = menu_buttons[i].Shape.getPosition().y;

		int buttonPosW = buttonX + menu_buttons[i].buttonW;
		int buttonPosH = buttonY + menu_buttons[i].buttonH;

		if (mouseX < buttonPosW && mouseX > buttonX&& mouseY < buttonPosH && mouseY > buttonY)
		{
			if (i == 0)
			{
				text[0].setFillColor(sf::Color::Green);
				text[1].setFillColor(sf::Color::White);
				text[2].setFillColor(sf::Color::White);
			}

			if (i == 1)
			{
				text[1].setFillColor(sf::Color::Green);
				text[0].setFillColor(sf::Color::White);
				text[2].setFillColor(sf::Color::White);
			}

			if (i == 2)
			{
				text[2].setFillColor(sf::Color::Green);
				text[0].setFillColor(sf::Color::White);
				text[1].setFillColor(sf::Color::White);
			}
		}
	}

}

void Menu::get_main_menu_option(sf::RenderWindow& window)
{
	int mouseX = sf::Mouse::getPosition(window).x;
	int mouseY = sf::Mouse::getPosition(window).y;

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		int buttonX = (menu_buttons[i].Shape.getPosition().x);
		int buttonY = menu_buttons[i].Shape.getPosition().y;

		int buttonPosW = buttonX + menu_buttons[i].buttonW;
		int buttonPosH = buttonY + menu_buttons[i].buttonH;

		if (mouseX < buttonPosW && mouseX > buttonX && mouseY < buttonPosH && mouseY > buttonY)
		{
			if (i == 0)
			{
				selectedItemIndex = PLAY_GAME;
			}
			if (i == 1)
			{
				selectedItemIndex = INSTRUCTIONS;
			}
			if (i == 2)
			{
				selectedItemIndex = EXIT;
			}
		}
	}
}

MainMenuOption Menu::get_Selected_Index()
{
	return selectedItemIndex;
}

void Menu::set_Selected_Index(MainMenuOption option)
{
	selectedItemIndex = option;
}

bool Menu::display_instructions(sf::RenderWindow& window)
{
    window.clear();
    sf::Text text[6];
    sf::Font font;
    Button button;
    if (!font.loadFromFile("Resources/Chunk Five.otf"))	//font~~~
    {
        std::cout << "Error Loading Font" << std::endl;
        return true;
    }

    text[0].setString("How to play the Epic Tower Defence Game:");
    text[1].setString("Prevent Monsters from reaching your castle by placing");
    text[2].setString(" towers along the path by clicking the button of the ");
    text[3].setString("tower you want and then clicking the space where you");
    text[4].setString(" want it placed");

    for (int i = 0, h = 10; i < 5; i++)
    {
        text[i].setFont(font);
        text[i].setOutlineColor(sf::Color::Black);
        text[i].setOutlineThickness(2);
        text[i].setFillColor(sf::Color::White);
        text[i].setCharacterSize(25);
        text[i].setPosition(sf::Vector2f(50, h));
        h = h + 50;
        window.draw(text[i]);
    }

    button.set_size(50, 80);
    button.set_text("BACK", 25);
    button.set_position(70, 450);



    sf::Event event;

    bool exit = false;


    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::MouseMoved:
            //button.is_over(window);
            break;
        case sf::Event::MouseButtonPressed:
            for (int i = 0; i < 3; i++)
            {
                //if (button.is_over(window))
                //{
                //    exit = true;
                //}
            }

            break;
        }
    }

    window.draw(text[5]);
    button.draw_display(window);


    return exit;
}

void Menu::play_game(sf::RenderWindow& window)
{
    Game game(window);

    game.run();
    game.display_results();
}
