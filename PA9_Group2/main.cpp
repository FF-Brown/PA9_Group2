
//Main File
#include <SFML/Graphics.hpp>
#include "main_menu.h"
#include "PA9.h"
using namespace std;


int main(void)
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tower Defense");
    Menu menu(WINDOW_WIDTH, WINDOW_HEIGHT);
    MainMenuOption option;

    Board board;
    int test = 0;

    while (window.isOpen()) {
        //Input detection
        sf::Event event;

        //Check if the window was closed
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    test = board.getSquareCoord(event.mouseButton.x, event.mouseButton.y);
                    if (test != -1)
                        board.colorCell(test);
                }
            }

        }

        //Render
        window.clear();
        board.displayBoard(window);
        window.display();
    }
    return 0;

    do
    {
        menu.display_main_menu(window);
        option = menu.get_Selected_Index();

        switch (option)
        {
        case INSTRUCTIONS:
            display_instructions(window);
            cout << "Instructions forthcoming...\n";
            break;

        case PLAY_GAME:
            play_game(window);
            break;

        case EXIT:
            
            break;
        }
    } while (option != EXIT);

    window.close();
    
    return 0;
}
