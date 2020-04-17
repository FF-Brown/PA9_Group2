
//Main File

#include "PA9.h"
#include "Board.h"
using namespace std;


int main(void)
{
    double windowWidth = 500, windowHeight = 500, cellSize = 50;
    double gridWidth = 215, gridHeight = 470;
	
	std::cout << "Tower Defense!" << std::endl;

    //Circle test code
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //Drawing grid
    sf::RectangleShape* squareGrid = createGrid(gridWidth, gridHeight, cellSize);
    int numSquares = ((int)(gridWidth / cellSize) * (int)(gridHeight / cellSize));

    MainMenuOption option;
    do
    {
        display_main_menu();
        option = get_main_menu_option();

        switch (option)
        {
        case INSTRUCTIONS:
            display_instructions();
            break;

        case PLAY_GAME:
            play_game();
            break;


        case EXIT:
            break;
        }

        
    
    } while (option != EXIT);
    //Redraw 
        window.clear();
        for (int i = 0; i < numSquares; i++) {
            window.draw(squareGrid[i]);
        }
        window.draw(shape);
        window.display();

	return 0;
}
