
#include "PA9.h"
#include "GUI.h"

bool display_instructions(sf::RenderWindow& window)
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
			button.is_over(window);
			break;
		case sf::Event::MouseButtonPressed:
			for (int i = 0; i < 3; i++)
			{
				if (button.is_over(window))
				{
					exit = true;
				}
			}

			break;
		}
	}

	window.draw(text[5]);
	button.draw_display(window);


	return exit;
}

