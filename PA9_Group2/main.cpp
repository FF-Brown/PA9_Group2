
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
