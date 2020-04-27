
//Main File


#pragma once

//Included Project Files
#include "main_menu.h"
//Included SFML Libraries
#include <SFML/Graphics.hpp>

using namespace std;


//Main Window Dimensions
#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH  800

//Frame Rate Limit
#define FR_LIMIT 60


int main(void)
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tower Defense");
    window.setFramerateLimit(FR_LIMIT);

    Menu menu(WINDOW_WIDTH, WINDOW_HEIGHT);
    MainMenuOption option;

    Board board;
    int test = 0;
    BoardTest testBoard;
    testBoard.testAddTower();

    return 0;


    do
    {
        menu.display_main_menu(window);
        option = menu.get_Selected_Index();

        switch (option)
        {
        case INSTRUCTIONS:
            while (!menu.display_instructions(window))
            {
                window.display();
                menu.set_Selected_Index(NOTHING);
            }
            break;

        case PLAY_GAME:
            menu.play_game(window);
            break;

        case EXIT:
            
            break;
        }
    } while (option != EXIT);

    window.close();
    
    return 0;
}
