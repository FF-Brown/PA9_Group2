
//Main File

#include "PA9.h"
using namespace std;


int main(void)
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tower Defense");

    MainMenuOption option;
    do
    {
        display_main_menu(window);
        option = get_main_menu_option();

        switch (option)
        {
        case INSTRUCTIONS:
            display_instructions(window);
            break;

        case PLAY_GAME:
            play_game(&window);
            break;

        case EXIT:
            break;
        }
    } while (option != EXIT);

    return 0;
}
